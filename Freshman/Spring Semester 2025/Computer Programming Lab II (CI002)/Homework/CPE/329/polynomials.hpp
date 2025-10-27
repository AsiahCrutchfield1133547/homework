#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <climits>
#include <vector>
using namespace std;

int coefficients[9];
int randNum;

template <size_t N>
void printCoefficients(int (&arr)[N]) {
    cout << "These are the coefficients: [";
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}

template <size_t N>
void polynomials(int (&arr)[N]) {
    bool printSign = false;

    for (int i = 0; i < N; i++) {
        int coefficient = arr[i];
        int exponent = N - 1 - i;
        int absCoefficient = abs(coefficient);

        if (coefficient == 0) {
            continue;
        } 

        if (printSign) {
            cout << (coefficient > 0 ? " + " : " - ");
        } else {
            if (coefficient < 0) cout << "-";
            printSign = true;
        }

        if (exponent == 0) {
            cout << absCoefficient;
        } else if (absCoefficient == 1) {
            cout << "x";
            if (exponent != 1) cout << "^" << exponent;
        } else {
            cout << absCoefficient << "x";
            if (exponent != 1) cout << "^" << exponent;
        }
    }
}
