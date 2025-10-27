#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int findLCS(string A, string B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1]) {
                grid[i][j] = grid[i - 1][j - 1] + 1; 
            } else {
                grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]); 
            }
        }
    }
    return grid[n][m];
}

int main() {
    srand(time(0)); 

    int T = rand() % 10 + 1;
    cout << "Number of test cases: " << T << endl;

    for (int t = 0; t < T; ++t) {
        string A, B;
        
        cout << "Test case " << t + 1 << ":" << endl;
        cout << "Enter string A: ";
        cin >> A;  
        cout << "Enter string B: ";
        cin >> B;  
        
        cout << "LCS Length: " << findLCS(A, B) << endl;
        cout << "--------------------------" << endl;
    }

    return 0;
}
