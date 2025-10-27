#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <vector>
using namespace std;

int sumArray(int *arr, int size) {
    int newSum = 0;

    cout << "This is your array: {";
    for (int i=0; i<size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "}" << "\n";

    // ------

    for (int i=0; i<size; i++) {
        newSum += arr[i];
    }
    cout << "This is the sum of your array: (" << newSum << ")"; 

    return newSum;
}

int main() {
    srand(std::time(0));

    int random = rand() % 10 + 1;
    vector<int> a(random);

    for (int i = 0; i < random; i++) {
        a[i] = rand() % 10 + 1;
    }

    sumArray(a.data(), random);
}