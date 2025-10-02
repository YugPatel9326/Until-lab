#include <iostream>
#include <functional> // std::function
#include <cassert>
using namespace std;

// until: repeatedly apply f to x until g(x) is true, then return x
int until(int x, function<int(int)> f, function<bool(int)> g) {
    while (!g(x)) {    // keep going while the predicate is false
        x = f(x);      // apply f and store result back in x
    }
    return x;          // g(x) is true here, return final value
}

int main() {
    // Test 1: double until greater than 100
    auto doubleNumber = [](int n) { return n * 2; };
    auto greaterThan100 = [](int n) { return n > 100; };
    assert(until(1, doubleNumber, greaterThan100) == 128); // 1->2->4->...->128

    // Test 2: add 3 until divisible by 7
    auto add3 = [](int n) { return n + 3; };
    auto divisibleBy7 = [](int n) { return (n % 7) == 0; };
    // start 2: 2->5->8->11->14 (14 is divisible by 7)
    assert(until(2, add3, divisibleBy7) == 14);

    // Test 3: square until >= 1000
    auto square = [](int n) { return n * n; };
    auto atLeast1000 = [](int n) { return n >= 1000; };
    // start 2: 2->4->16->256->65536 (65536 >= 1000)
    assert(until(2, square, atLeast1000) == 65536);

    // Test 4: trivial predicate already true -> should return initial x
    auto alwaysTrue = [](int) { return true; };
    auto anyFunc = [](int n) { return n + 1; };
    assert(until(42, anyFunc, alwaysTrue) == 42);

    cout << "All asserts passed.\n";
    return 0;
}
