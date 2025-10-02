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
    auto greaterThan200 = [](int n) { 
        return n > 200; 
    };
    assert(until(1, doubleNumber, greaterThan200) == 256);

    auto addThree = [](int n) { 
        return n + 3; 
    };
    auto divisibleByTen = [](int n) { 
        return (n % 10) == 0; 
    };
    assert(until(2, addThree, divisibleByTen) == 20);

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
