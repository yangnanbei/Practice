#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <sys/resource.h>

// 获取当前线程上下文切换统计
void print_thread_ctxt(const std::string& tag) {
    struct rusage usage;
    getrusage(RUSAGE_THREAD, &usage);
    std::cout << "[" << tag << "] voluntary: " << usage.ru_nvcsw
              << ", nonvoluntary: " << usage.ru_nivcsw << std::endl;
}

// 互斥锁测试
void test_mutex() {
    std::mutex mtx;
    bool ready = false;

    auto worker = [&]() {
        while (!ready) std::this_thread::yield();
        auto start = std::chrono::high_resolution_clock::now();

        std::lock_guard<std::mutex> lock(mtx);

        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "[Mutex] Lock acquired after "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
                  << " us\n";
        print_thread_ctxt("Mutex thread");
    };

    std::thread t(worker);

    mtx.lock();
    ready = true;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 持锁1秒
    mtx.unlock();
    t.join();
}

// 自旋锁测试
void test_spinlock() {
    std::atomic_flag spin = ATOMIC_FLAG_INIT;
    bool ready = false;

    auto worker = [&]() {
        while (!ready) std::this_thread::yield();
        auto start = std::chrono::high_resolution_clock::now();

        while (spin.test_and_set(std::memory_order_acquire)) {
            // busy wait
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "[Spinlock] Lock acquired after "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
                  << " us\n";
        spin.clear(std::memory_order_release);
        print_thread_ctxt("Spinlock thread");
    };

    std::thread t(worker);

    spin.test_and_set(std::memory_order_acquire);
    ready = true;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 持锁1秒
    spin.clear(std::memory_order_release);
    t.join();
}

int main() {
    std::cout << "=== Mutex test ===" << std::endl;
    test_mutex();
    std::cout << "\n=== Spinlock test ===" << std::endl;
    test_spinlock();
    return 0;
}
