#include <iostream>
#include <functional> 
#include <cassert>
using namespace std;

int until(int x, function<int(int)> f, function<bool(int)> g) {
    while (!g(x)) {    
        x = f(x);     
    }
    return x;          
}

int main() {
    auto doubleNumber = [](int n) { 
        return n * 2; 
    };
    auto greaterThanHundred = [](int n) { 
        return n > 100; 
    };
    assert(until(1, doubleNumber, greaterThanHundred) == 128);

    auto addThree = [](int n) { 
        return n + 3; 
    };
    auto divisibleBySeven = [](int n) { 
        return (n % 7) == 0; 
    };
    assert(until(2, addThree, divisibleBySeven) == 14);

    auto square = [](int n) { 
        return n * n; 
    };
    auto atLeastThousand = [](int n) { 
        return n >= 1000; 
    };
    assert(until(2, square, atLeastThousand) == 65536);

    cout << "Successfully passed all tests\n";
    return 0;
}
