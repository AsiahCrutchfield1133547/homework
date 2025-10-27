#include <iostream>
#include <cassert>
using namespace std;

void foo(int& x, int& y) {
    if (x <= y) {
        int temp = x;
        x = y;
        y = temp;
    }
}

int main() {
    int x, y;
    int copy_x, copy_y;
    
    cin >> x >> y;
    copy_x = x;
    copy_y = y;
    foo(x, y);
    
    if (copy_x > copy_y)
        assert(copy_x == x && copy_y == y);
    else
        assert(copy_x == y && copy_y == x);
}
