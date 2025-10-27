#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <vector>
using namespace std;

void reverseArray(int *arr, int size) {
    vector<int> newArr;

    cout << "This is your original array: {";
    for (int i=0; i<size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "}" << "\n";

    // ------

    for (int i=size-1; i>=0; i--) {
        newArr.push_back(arr[i]);
    }

    // ------
    
    cout << "This is your reversed array: {";
    for (int i=0; i<size; i++) {
        cout << newArr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "}" << "\n";

}

int main() {
    srand(std::time(0));

    int random = rand() % 10 + 1;
    vector<int> a(random);

    for (int i = 0; i < random; i++) {
        a[i] = rand() % 10 + 1;
    }

    reverseArray(a.data(), random);
}