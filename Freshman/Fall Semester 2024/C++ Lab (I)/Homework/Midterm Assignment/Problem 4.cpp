#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <vector>
#include <cmath>  
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  

    int size = rand() % 99 + 2; 

    cout << "Matrix size: " << size << "x" << size << endl;

    vector<vector<int>> matrix(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 51; 
        }
    }

    cout << "Here is the matrix:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "{";
        for (int j = 0; j < size; j++) {
            if (j < size - 1) {
                cout << matrix[i][j] << ", ";
            } else {
                cout << matrix[i][j];  
            }
        }
        cout << "}" << endl; 
    }

    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < size; i++) {
        primaryDiagonalSum += matrix[i][i]; 
        secondaryDiagonalSum += matrix[i][size - 1 - i]; 
    }

    int absoluteDifference = abs(primaryDiagonalSum - secondaryDiagonalSum);

    cout << "Absolute difference between diagonals: " << absoluteDifference << endl;

    return 0;
}
