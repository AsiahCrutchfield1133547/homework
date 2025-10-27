#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

    void normalize() {
        if (second >= 60) {
            minute += second / 60;
            second %= 60;
        } else if (second < 0) {
            minute += (second / 60) - 1;
            second = (second % 60 + 60) % 60;
        }

        if (minute >= 60) {
            hour += minute / 60;
            minute %= 60;
        } else if (minute < 0) {
            hour += (minute / 60) - 1;
            minute = (minute % 60 + 60) % 60;
        }

        hour = (hour + 24) % 24; 
    }

public:
    // Constructors
    Time() : hour(0), minute(0), second(0) {} 

    Time(int h, int m, int s) : hour(h), minute(m), second(s) {
        normalize();
    }

    // Getters
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }

    // Setters
    void setHour(int h) { if (h >= 0 && h < 24) hour = h; }
    void setMinute(int m) { if (m >= 0 && m < 60) minute = m; }
    void setSecond(int s) { if (s >= 0 && s < 60) second = s; }

    // Add seconds
    void add(int sec) {
        second += sec;
        normalize();
    }

    // Subtract seconds
    void sub(int sec) {
        second -= sec;
        normalize();
    }

    // Get time in HH:MM:SS format
    string getTime() {
        ostringstream oss;
        oss << setw(2) << setfill('0') << hour << ":"
            << setw(2) << setfill('0') << minute << ":"
            << setw(2) << setfill('0') << second;
        return oss.str();
    }

    // Compare function
    int compare(const Time& another) {
        if (hour < another.hour || 
            (hour == another.hour && minute < another.minute) || 
            (hour == another.hour && minute == another.minute && second < another.second)) {
            return -1;
        } else if (hour == another.hour && minute == another.minute && second == another.second) {
            return 0;
        } else {
            return 1;
        }
    }
};

