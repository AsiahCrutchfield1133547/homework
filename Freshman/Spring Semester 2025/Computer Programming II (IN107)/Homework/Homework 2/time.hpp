#include <iostream>
#include <string>
using namespace std;

class Time {
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0) {}
    // Constructor
    Time(int hour, int minute, int second) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
        normalizeTime();
    }

    // Normalization function to adjust time correctly
    void normalizeTime() {
        // Handle negative values properly
        while (second < 0) {
            second += 60;
            minute--;
        }
        while (minute < 0) {
            minute += 60;
            hour--;
        }
        while (hour < 0) {
            hour += 24;
        }

        // Normalize overflow
        minute += second / 60;
        second %= 60;

        hour += minute / 60;
        minute %= 60;

        hour %= 24; // Wrap around for a 24-hour format
    }

    // Setter methods
    void setSecond(int second) {
        this->second = second;
        normalizeTime();
    }

    void setMinute(int minute) {
        this->minute = minute;
        normalizeTime();
    }

    void setHour(int hour) {
        this->hour = hour;
        normalizeTime();
    }

    // Getter methods
    int getSecond() { return second; }
    int getMinute() { return minute; }
    int getHour() { return hour; }

    // Method to add time
    void add(int amount, string unit) {
        if (unit == "second") {
            this->second += amount;
        } else if (unit == "minute") {
            this->minute += amount;
        } else if (unit == "hour") {
            this->hour += amount;
        } else {
            cout << "Invalid time unit!" << endl;
            return;
        }
        normalizeTime();
    }

    // Method to calculate duration between two Time objects
    int duration(const Time& other) const {
        int sec1 = (hour * 3600) + (minute * 60) + second;
        int sec2 = (other.hour * 3600) + (other.minute * 60) + other.second;
        return (sec1 > sec2) ? (sec1 - sec2) : (sec2 - sec1);
    }

    bool operator<(const Time& other) const { return (hour * 3600 + minute * 60 + second) < (other.hour * 3600 + other.minute * 60 + other.second); }
    bool operator>(const Time& other) const { return other < *this; }
    bool operator==(const Time& other) const { return hour == other.hour && minute == other.minute && second == other.second; }
    bool operator!=(const Time& other) const { return !(*this == other); }
    bool operator<=(const Time& other) const { return !(other < *this); }
    bool operator>=(const Time& other) const { return !(*this < other); }

    // Overload increment & decrement operators
    Time& operator++() { second++; normalizeTime(); return *this; }  // ++t
    Time& operator--() { second--; normalizeTime(); return *this; }  // --t
    Time& operator+=(int sec) { second += sec; normalizeTime(); return *this; }  // t += 5
    Time& operator-=(int sec) { second -= sec; normalizeTime(); return *this; }  // t -= 8

    // Overload '-' operator between two Time objects
    int operator-(const Time& other) const {
        int sec1 = hour * 3600 + minute * 60 + second;
        int sec2 = other.hour * 3600 + other.minute * 60 + other.second;
        return sec1 - sec2; // Can return positive or negative difference
    }

    // Display function
    void displayTime() const {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }
};