#include <iostream>
#include <limits> 
#include <cstdlib> 
#include <ctime>   
#include <vector>
using namespace std;

void shiftRight(vector<int>& arr, int shift) {
    int size = arr.size();
    shift = shift % size;

    for (int i=0; i<shift; i++) {
        int last = arr[size-1];
    
        for (int j=size-1; j>0; j--) {
            arr[j] = arr[j-1];
        }

    arr[0] = last;
    }

    cout << "{";
    for (int l=0; l<size; l++) {
        cout << arr[l];
        if (l<size-1) {
            cout << ", ";
        }
    }
    cout << "}";
}

int main() {
    int k;
    
    while (true) {
        cout << "Enter the array size (1-100): ";
        cin >> k;

        if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That's not a number. Choose between 1 and 100.";
        cout << endl;
        }
        else if(k > 100) {
            cout << "Too high. Choose between 1 and 100: ";
        }
        else if(k < 1) {
            cout << "Too low. Choose between 1 and 100: ";
        }
        else {
            break;
        }
    }
    vector<int> array(k);

    srand(static_cast<unsigned int>(time(0)));

    cout << "Great! Would you like to choose your own numbers "
    << "or choose random ones? (1 = random | 2 = your choice) ";

    int choice;
    bool validChoice = false;

    while (!validChoice) {
        cin >> choice;

        if (cin.fail() || (choice != 1 && choice != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 1 for random "
            << "or 2 to choose. ";
            validChoice = false;
        }
        else {
            validChoice = true;  
        }
    }

        if (choice == 2) {
            cout << "Please enter your " << k << " numbers: ";
            for (int i=0; i < k; i++) {
                cin >> array[i];
            }
            cout << "You entered: {";
            for (int i=0; i < k; i++) {
                cout << array[i];
                if (i < k - 1) {
                    cout << ", ";
                }
            }
            cout << "}";
        }
        else if (choice == 1) {
            cout << "Here's your list: {";
            for (int i=0; i < k; i++) {
                array[i] = rand() % 100 + 1; 
                cout << array[i];
                if (i < k - 1) {
                    cout << ", ";
                }
            }
            cout << "}";
        }
    int size = array.size();

    cout << endl;
    cout << "Here's your shifted array: ";
    shiftRight(array);
}