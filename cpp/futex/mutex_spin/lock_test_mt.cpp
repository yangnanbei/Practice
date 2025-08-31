#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <vector>
#include <atomic>

#define THREAD_COUNT 16
#define TEST_DURATION 1000000 // 微秒 (1秒)

// ==================== 获取上下文切换统计 ====================
void print_context_switches(const char* name) {
    struct rusage usage{};
    getrusage(RUSAGE_THREAD, &usage);
    std::cout << "[" << name << "] voluntary: " << usage.ru_nvcsw
              << ", nonvoluntary: " << usage.ru_nivcsw << std::endl;
}

// ==================== 互斥锁测试 ====================
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
std::atomic<bool> stop_flag{false};

void* mutex_worker(void* arg) {
    while (!stop_flag.load()) {
        pthread_mutex_lock(&mtx);
        usleep(100); // 模拟临界区
        pthread_mutex_unlock(&mtx);
    }
    print_context_switches("Mutex thread");
    return nullptr;
}

void test_mutex() {
    std::cout << "\n=== Mutex test ===" << std::endl;
    stop_flag.store(false);
    pthread_t threads[THREAD_COUNT];

    // 启动线程
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], nullptr, mutex_worker, nullptr);
    }

    // 等待一段时间
    usleep(TEST_DURATION);
    stop_flag.store(true);

    // 回收线程
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], nullptr);
    }
}

// ==================== 自旋锁测试 ====================
pthread_spinlock_t spin;

void* spin_worker(void* arg) {
    while (!stop_flag.load()) {
        pthread_spin_lock(&spin);
        usleep(100); // 模拟临界区
        pthread_spin_unlock(&spin);
    }
    print_context_switches("Spinlock thread");
    return nullptr;
}

void test_spinlock() {
    std::cout << "\n=== Spinlock test ===" << std::endl;
    stop_flag.store(false);
    pthread_t threads[THREAD_COUNT];
    pthread_spin_init(&spin, PTHREAD_PROCESS_PRIVATE);

    // 启动线程
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], nullptr, spin_worker, nullptr);
    }

    // 等待一段时间
    usleep(TEST_DURATION);
    stop_flag.store(true);

    // 回收线程
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], nullptr);
    }

    pthread_spin_destroy(&spin);
}

// ==================== 主函数 ====================
int main() {
    test_mutex();
    test_spinlock();
    return 0;
}
