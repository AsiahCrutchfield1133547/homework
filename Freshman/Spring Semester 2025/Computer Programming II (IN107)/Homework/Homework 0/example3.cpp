#include <iostream>
#include <vector>
using namespace std;

void reverseOrderNum(int x) {  
    vector<int> arr;
    int num;

    cout << "Enter your " << x << " numbers\n";
    for (int i = 0; i < x; i++) {
        cout << "Number " << i+1 << ": ";
        cin >> num;
        arr.push_back(num);
    }

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
            if (arr[j] > arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
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
    int user;
    cout << "How many numbers do you want to rearrange? ";
    cin >> user;

    reverseOrderNum(user);
}