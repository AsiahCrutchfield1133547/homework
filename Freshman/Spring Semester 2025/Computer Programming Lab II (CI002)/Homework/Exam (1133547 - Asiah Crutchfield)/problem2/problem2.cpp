#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <vector>
using namespace std;

int reverseArray(int *arr, int size) {
    cout << "This is your array: {";
    for (int i=0; i<size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "}" << "\n";

    // ------
}
