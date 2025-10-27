#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Event Planning.hpp"
using namespace std;

int main() {
    srand(time(0)); 

    int participants = 1 + rand() % 201; // 1 to 200 people
    int budget = 1 + rand() % 500001; // $1 to $500,000
    int hotels = 1 + rand() % 19; // 1 to 18
    int weeks = 1 + rand() % 14; // 1 to 13
    int price = 1 + rand() % 10001; // $1 to $10,000

    stayOrGo(participants, budget, hotels, weeks, price);
}