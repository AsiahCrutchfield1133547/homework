#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <string>
#include <vector>
using namespace std;

void countEvenOdd(int* arr, int size, int &evenCount, int &oddCount) {
    evenCount = 0;
    oddCount = 0;

    cout << "This is your array: {";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "}\n";

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    cout << "Even numbers: " << evenCount << "\n";
    cout << "Odd numbers: " << oddCount << "\n";
}

int main() {
    srand(std::time(0));

    int random = rand() % 20 + 1;
    vector<int> arr(random);

    for (int i = 0; i < random; i++) {
        arr[i] = rand() % 100 + 1;
    }

    int even, odd;

    countEvenOdd(arr.data(), random, even, odd);
}