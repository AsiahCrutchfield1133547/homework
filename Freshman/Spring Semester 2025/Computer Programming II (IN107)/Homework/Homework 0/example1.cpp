#include <iostream>
#include <vector>
using namespace std;

void orderNum() {  
    int a, b, c;
    vector<int> arr;

    cout << "Enter your 1st number: ";
    cin >> a;
    cout << "Enter your 2nd number: ";
    cin >> b;
    cout << "Enter your 3rd number: ";
    cin >> c;

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    cout << "This is your set: {";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) { 
            cout << ", ";
        }
    }
    cout << "}" << endl;

    for (int i = 0; i < arr.size()-1; i++) {
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "This is your new set: {";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) { 
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int main() {
    orderNum();
}