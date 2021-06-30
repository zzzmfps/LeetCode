// 48ms, 57.48%; 9.1MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class FizzBuzz {
private:
    int n;
    int cur;
    mutex mx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->cur = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        helper([&]() { return cur % 5 && cur % 3 == 0; }, [&](int i) { printFizz(); });
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        helper([&]() { return cur % 5 == 0 && cur % 3; }, [&](int i) { printBuzz(); });
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        helper([&]() { return cur % 5 == 0 && cur % 3 == 0; }, [&](int i) { printFizzBuzz(); });
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        helper([&]() { return cur % 5 && cur % 3; }, printNumber);
    }

private:
    void helper(function<bool()> test, function<void(int)> print) {
        while (true) {
            unique_lock<mutex> lock(mx);
            cv.wait(lock, [&]() { return cur > n || test(); });
            if (cur > n) break;
            print(cur++);
            lock.unlock();
            cv.notify_all();
        }
    }
};
