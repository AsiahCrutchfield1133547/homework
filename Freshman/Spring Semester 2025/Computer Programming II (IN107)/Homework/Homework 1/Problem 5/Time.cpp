#include <iostream>
#include <iomanip>
#include <sstream>
#include "Time.hpp"
using namespace std;


int main() {
    Time t1(10, 30, 45);
    Time t2(10, 30, 50);

    cout << "Initial time: " << t1.getTime() << endl;

    t1.add(20);
    cout << "After adding 20 seconds: " << t1.getTime() << endl;

    t1.sub(70);
    cout << "After subtracting 70 seconds: " << t1.getTime() << endl;

    cout << "Comparison result with t2: " << t1.compare(t2) << endl;

    return 0;
}
