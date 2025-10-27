#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <climits>
#include <vector> 
using namespace std;

string addCommas(int number) {
    string numStr = to_string(number);
    int insertPosition = numStr.length() - 3;

    while (insertPosition > 0) {
        numStr.insert(insertPosition, ",");
        insertPosition -= 3;
    }

    return numStr;
}

void stayOrGo(int p, int b, int h, int w, int pr) {

    vector<int> hotel_prices;  // stores total price for each hotel
    vector<int> hotel_beds;    // stores number of beds for each hotel

    if (p > 1) {
        cout << "There are " << p << " participants going.\n";
    } else {
        cout << "There is " << p << " participant going.\n";
    }

    if (h > 1) {
        cout << "There are " << h << " hotels available ";
    } else {
        cout << "There is " << h << " hotel available ";
    }

    if (w > 1) {
        cout << "for " << w << " weeks.\n";
    } else {
        cout << "for " << w << " week.\n";
    }

    cout << "The budget is $" << addCommas(b) << "\n";

    // Generate hotel prices and bed counts for each hotel
    for (int i = 0; i < h; i++) {
        int hotel_price_per_week = 1 + rand() % 10001;  // Random price per week
        hotel_prices.push_back(hotel_price_per_week * w * p);  // Total price for all weeks and participants
        hotel_beds.push_back(1 + rand() % 1001);  // (1 to 1000)
    }

    // Find the cheapest hotel that fits within the budget
    int lowest_price = INT_MAX;
    int lowest_price_index = -1;

    for (int i = 0; i < h; i++) {
        if (hotel_prices[i] <= b && hotel_beds[i] >= p) {
            if (hotel_prices[i] < lowest_price) {
                lowest_price = hotel_prices[i];
                lowest_price_index = i;
            }
        }
    }

    if (lowest_price_index != -1) {
        cout << "Hotel " << lowest_price_index + 1 << " is within budget and costs $" << addCommas(lowest_price) << ".\n";
    } else {
        cout << "\033[31mStay home.\033[0m\n";
    }
}
