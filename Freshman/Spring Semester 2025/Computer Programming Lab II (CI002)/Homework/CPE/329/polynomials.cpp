#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <climits>
#include <vector>
#include "polynomials.hpp"
using namespace std;

int main() {
    srand(time(0));

    for (int i = 0; i < 9; i++) {
        coefficients[i] = rand() % 11 * (rand() % 2 == 0 ? 1 : -1);
    }

    printCoefficients(coefficients);
    polynomials(coefficients);
}