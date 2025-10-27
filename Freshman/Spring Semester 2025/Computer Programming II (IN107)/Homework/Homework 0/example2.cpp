#include <iostream>
using namespace std;

void displayFactorial(int x) {
    long long factorial = 1;

    // Print the multiplication sequence only if x <= 5
    if (x <= 5) {
        cout << "The factorial of " << x << " is: ";
        for (int i = 1; i <= x; i++) {
            cout << i;
            if (i != x) { // If it's not the last number, print " x "
                cout << " x ";
            }
            factorial *= i; // Calculate factorial
        }
        cout << " = " << factorial << "\n";
    } else {
        for (int i = 1; i <= x; i++) {
            factorial *= i; // Calculate factorial
        }
        cout << "The factorial is: " << factorial << "\n";
    }
}

void displayHarmonicSum(int x) {
    double harmonicSum = 0;  

    
    if (x <= 5) {
        cout << "The harmonic sum of " << x << " is: ";
        for (int i = 1; i <= x; i++) {
            cout << "1/" << i;
            harmonicSum += 1.0 / i; 
            if (i != x) { 
                cout << " + ";
            }
        }
        cout << " = " << harmonicSum << "\n";
    } else {
        for (int i = 1; i <= x; i++) {
            harmonicSum += 1.0 / i; 
        }
        cout << "The harmonic sum is: " << harmonicSum << "\n";
    }
}

void displayExpSum(int x) {
    double expSum = 1;  

    if (x <= 5) {
        cout << "The exponential sum of " << x << " is: ";
        for (int i = 1; i <= x; i++) {
            long long factorial = 1;
            for (int j = 1; j <= i; j++) {
                factorial *= j; 
            }
            cout << "1/" << factorial;
            expSum += 1.0 / factorial; 
            if (i != x) { 
                cout << " + ";
            }
        }
        cout << " = " << expSum << "\n";
    } else {
        for (int i = 1; i <= x; i++) {
            long long factorial = 1;
            for (int j = 1; j <= i; j++) {
                factorial *= j; 
            }
            expSum += 1.0 / factorial; 
        }
        cout << "The exponential sum is: " << expSum << "\n";
    }
}

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    displayFactorial(n);
    displayHarmonicSum(n);
    displayExpSum(n);

    return 0;
}
