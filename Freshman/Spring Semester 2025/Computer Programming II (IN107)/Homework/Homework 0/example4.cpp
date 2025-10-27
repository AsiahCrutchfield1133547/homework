#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base case: return 1 for n = 0 or n = 1
    }
    return fibonacci(n - 2) + fibonacci(n - 1);  // Recursive case: Fn = F(n-2) + F(n-1)
}

int main() {
    int n;

    // Input: Number of Fibonacci terms to print
    cout << "Input n: ";
    cin >> n;

    // Print the first n Fibonacci numbers
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}
