#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isB2Sequence(const vector<int>& seq) {
    set<int> sums;
    int n = seq.size();

    // Check if the sequence is strictly increasing and all numbers are positive
    for (int i = 0; i < n - 1; ++i) {
        if (seq[i] <= 0 || seq[i] >= seq[i + 1]) {
            return false;  // Invalid sequence: non-positive or not strictly increasing
        }
    }

    // Check all pairwise sums bi + bj (i <= j)
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = seq[i] + seq[j];
            if (sums.count(sum)) {
                return false;  // Found a duplicate sum
            }
            sums.insert(sum);
        }
    }

    return true;
}

int main() {
    int N, caseNum = 1;
    
    // Read until EOF
    while (cin >> N) {
        vector<int> seq(N);
        for (int i = 0; i < N; ++i) {
            cin >> seq[i];
        }

        bool valid = isB2Sequence(seq);

        cout << "Case #" << caseNum++ << ": ";
        if (valid)
            cout << "It is a B2-Sequence." << endl;
        else
            cout << "It is not a B2-Sequence." << endl;
        cout << endl;  // Blank line after each case
    }

    return 0;
}
