#include <iostream>
#include <thread>
#include <mutex>

//std::mutex mtx; // 普通互斥锁，替换为 std::recursive_mutex 可解决重入
std::recursive_mutex mtx;

void inner(int n) {
    std::lock_guard<std::recursive_mutex> lk(mtx); // 若 mtx 是 std::mutex，第二次 lock 将死锁
    std::cout << "inner " << n << " locked by thread " << std::this_thread::get_id() << "\n";
    if (n > 0) inner(n - 1);
}

int main() {
    std::thread t([]{
        // 如果 mtx 是 std::mutex，这里第一次 lock 后，inner 再次 lock 会死锁。
        // 将上方 mtx 改成 std::recursive_mutex 并把 lock_guard 类型也改为 std::lock_guard<std::recursive_mutex>
        inner(2);
    });
    t.join();
    std::cout << "done\n";
}

