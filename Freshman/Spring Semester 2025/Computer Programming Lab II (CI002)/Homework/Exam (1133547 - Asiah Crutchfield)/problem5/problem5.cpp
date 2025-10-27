#include <iostream>
using namespace std;

void multiplyMatrices(int* mat1, int* mat2, int* result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i * cols + j] = 0; // Initialize the result matrix element
            for (int k = 0; k < cols; k++) {
                result[i * cols + j] += mat1[i * cols + k] * mat2[k * cols + j]; // Matrix multiplication logic
            }
        }
    }
}

void displayMatrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i * cols + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows = 2, cols = 2; 

    int mat1[] = {1, 2, 3, 4}; 
    int mat2[] = {5, 6, 7, 8}; 
    int result[4]; 

    void (*multiplyPtr)(int*, int*, int*, int, int) = multiplyMatrices;

    multiplyPtr(mat1, mat2, result, rows, cols);

    cout << "Resultant Matrix: " << endl;
    displayMatrix(result, rows, cols);

    return 0;
}
