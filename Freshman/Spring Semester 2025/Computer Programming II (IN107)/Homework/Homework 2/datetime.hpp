#include <iostream>
#include <string>
#include <vector>
#include "time.hpp"
using namespace std;

class DateTime {
    int date;
    int month;
    int year;
    Time time;

    public: 
        DateTime(int date, int month, int year, Time time) {
            this->date = date;
            this->month = month;
            this->year = year;
            this->time = time;

            normalizeDate();
        };

        void normalizeDate() {
            while (date < 1) {
                month--;
                if (month < 1) {
                    month = 12;
                    year--;
                }
                date += daysInMonth(month, year);
            }

            while (month < 1) {
                month += 12;
                year--;
            };
        };

        // Helper function to get the number of days in a given month
        static int daysInMonth(int month, int year) {
            switch (month) {
                case 4: case 6: case 9: case 11: return 30;  // Months with 30 days
                case 2: return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28; // Leap year check
                default: return 31;  // Months with 31 days
            }
        }

        void addDate(int amount, string unit) {
            if (unit == "year") {
                this->year += amount;
            } else if (unit == "month") {
                this->month += amount;
            } else if (unit == "date") {
                this->date += amount;
            } else {
                cout << "Invalid date unit!" << endl;
                return;
            }
            normalizeDate();
        }

        void dayOfMonth() {
            switch (month) {
                case 1: cout << "January (01)"; break;
                case 2: cout << "February (02)"; break;
                case 3: cout << "March (03)"; break;
                case 4: cout << "April (04)"; break;
                case 5: cout << "May (05)"; break;
                case 6: cout << "June (06)"; break;
                case 7: cout << "July (07)"; break;
                case 8: cout << "August (08)"; break;
                case 9: cout << "September (09)"; break;
                case 10: cout << "October (10)"; break;
                case 11: cout << "November (11)"; break;
                case 12: cout << "December (12)"; break;
                default: cout << "Invalid month"; break;
        }
            cout << month << " has " << daysInMonth(month, year) << " days." << endl;
        }

        bool isLeapYear(int year) {
            // Leap year rule: Divisible by 4, but not by 100 unless divisible by 400.
            return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        }
    
        int daysInAMonth(int month, int year) {
            // Array with the number of days in each month for a non-leap year
            int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            
            // Adjust February for leap years
            if (isLeapYear(year)) {
                daysInMonths[1] = 29;  // February has 29 days in a leap year
            }
    
            return daysInMonths[month - 1];
        }

        int dayOfYear() const {
            // Add up all days from previous months
            int totalDays = 0;
            for (int i = 1; i < month; i++) {
                totalDays += daysInMonth(i, year);  // Add days of the month
            }

            // Add the current day's date
            totalDays += date;

            return totalDays;  // This gives the day number in the year
        }

        string dayOfWeek() {
            int m = month;
            int y = year;
    
            // Adjust for January and February
            if (month <= 2) {
                m += 12;
                y--;
            }
    
            int k = y % 100;  // last two digits of the year
            int j = y / 100;  // first two digits of the year
    
            // Zeller's formula
            int h = (date + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
    
            // Days of the week (0=Saturday, 1=Sunday, ..., 6=Friday)
            string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
            
            return days[h];
        }

        int quarterOfYear() {
            return (month - 1) / 3 + 1;
        }

        int weekOfYear() {
            // Get the day of the year
            int dayOfYearValue = dayOfYear();
            
            // Calculate the week of the year
            int week = (dayOfYearValue - 1) / 7 + 1; // Subtract 1 because weeks start from 1
            
            return week;
        }

        bool operator<(const DateTime& other) const {
            if (year != other.year) return year < other.year;
            if (month != other.month) return month < other.month;
            if (date != other.date) return date < other.date;
            return time < other.time;
        }

        bool operator>(const DateTime& other) const { return other < *this; }
        bool operator==(const DateTime& other) const { return !(*this < other || other < *this); }
        bool operator<=(const DateTime& other) const { return !(other < *this); }
        bool operator>=(const DateTime& other) const { return !(*this < other); }
        bool operator!=(const DateTime& other) const { return !(*this == other); }

        DateTime& operator++() {
            date++;
            normalizeDate();
            return *this;
        }

        DateTime& operator--() {
            date--;
            normalizeDate();
            return *this;
        }

        float duration(const DateTime& other) const {
            int totalDays1 = dayOfYear() + (year * 365);
            int totalDays2 = other.dayOfYear() + (other.year * 365);
            float timeDiff = time - other.time;
            return abs(totalDays1 - totalDays2) + (timeDiff / 86400);
        }

        float operator-(const DateTime& other) const {
            return duration(other) * ((*this < other) ? -1 : 1);
        }

        void setDate(int date) {
            this->date = date;
        }

        void setMonth(int month) {
            this->month = month;
        }

        void setYear(int year) {
            this->year = year;
        }

        void setSecond(int second) {
            time.setSecond(second);
        }

        void setMinute(int minute) {
            time.setMinute(minute);
        }

        void setHour(int hour) {
            time.setHour(hour);
        }

        int getDate() {
            return date;
        }

        int getMonth() {
            return month;
        }

        int getYear() {
            return year;
        }

        int getSecond() {
            return time.getSecond();
        }

        int getMinute() {
            return time.getMinute();
        }
        int getHour() {
            return time.getHour();
        }
};