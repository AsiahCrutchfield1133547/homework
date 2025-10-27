#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; // Count of boxes
    cin >> "Enter your boxes " >> n; // Read number of boxes

    vector<int> a(n); // Create our boxes
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Fill the boxes with numbers
    }

    int half_n = n / 2; // Only need half the pairs
    vector<int> b(half_n); // Create a list for shared toys

    
    for (int j = 0; j < half_n; ++j) {
        b[j] = std::gcd(a[j], a[n - 1 - j]); // Find the biggest shared toy
    }

    
    for (int j = 0; j < half_n; ++j) {
        cout << b[j]; // Show the biggest shared toys
        if (j < half_n - 1) cout << " "; // Space between toys
    }
    cout << endl; // New line at the end

    return 0; // We're done!
}
