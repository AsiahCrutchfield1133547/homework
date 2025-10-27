#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <vector>
using namespace std;

void findMinMax(int *arr, int size, int &min, int &max) {
    min = arr[0];
    max = arr[0];

    cout << "This is your original array: {";
    for (int i=0; i<size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "}" << "\n";

    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }

        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "These are the minimums and maximums of your array: \n";
    cout << "Min: " << min << "\n";
    cout << "Max: " << max << "\n";
}

int main() {
    srand(std::time(0));

    int random = rand() % 10 + 1;
    vector<int> arr(random);

    int min, max;

    for (int i = 0; i < random; i++) {
        arr[i] = rand() % 10 + 1;
    }

    findMinMax(arr.data(), random, min, max);
}