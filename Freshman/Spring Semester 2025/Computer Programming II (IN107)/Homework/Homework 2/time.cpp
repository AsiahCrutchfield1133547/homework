#include <iostream>
#include <string>
#include "datetime.hpp"
using namespace std;

int main() {
    int userDate;
    int userTime;

    // Create two DateTime objects
    DateTime dt1(30, 3, 2025, Time(14, 30, 0));  // 30 March 2025, 14:30:00
    DateTime dt2(15, 2, 2024, Time(9, 15, 0));   // 15 February 2024, 09:15:00

    // Display dates with proper method calls
    cout << "Date 1: " << dt1.getDate() << "-" << dt1.getMonth() << "-" << dt1.getYear() << " ";
    cout << dt1.getHour() << ":" << dt1.getMinute() << ":" << dt1.getSecond() << endl;

    cout << "Date 2: " << dt2.getDate() << "-" << dt2.getMonth() << "-" << dt2.getYear() << " ";
    cout << dt2.getHour() << ":" << dt2.getMinute() << ":" << dt2.getSecond() << endl;

    // Calculate duration in days
    cout << "Duration between dates: " << dt1.duration(dt2) << " days\n";

    // Compare dates
    if (dt1 > dt2) {
        cout << "Date 1 is after Date 2\n";
    } else {
        cout << "Date 1 is before or the same as Date 2\n";
    }

    // Test operators
    cout << "Difference in days: " << (dt1 - dt2) << endl;

    // Test increment (++) and decrement (--)
    cout << "Incrementing Date 1...\n";
    ++dt1;
    cout << "New Date 1: " << dt1.getDate() << "-" << dt1.getMonth() << "-" << dt1.getYear() << endl;

    cout << "Decrementing Date 2...\n";
    --dt2;
    cout << "New Date 2: " << dt2.getDate() << "-" << dt2.getMonth() << "-" << dt2.getYear() << endl;

    return 0;
}