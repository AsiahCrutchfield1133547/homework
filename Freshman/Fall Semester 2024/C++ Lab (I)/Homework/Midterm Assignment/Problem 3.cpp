#include <iostream>
#include <limits> 
#include <cstdlib> 
#include <ctime>   
#include <vector>
#include <set>
using namespace std;

void findPairs(const vector<int>& arr, int target) {
    set<pair<int, int>> uniquePairs;  
     bool pairFound = false;

    for (int i = 0; i < arr.size(); i++) {  
        for (int j = i + 1; j < arr.size(); j++) {  
            if (arr[i] + arr[j] == target) {  
                int a = min(arr[i], arr[j]);  
                int b = max(arr[i], arr[j]);

                if (uniquePairs.find({a, b}) == uniquePairs.end()) {
                    uniquePairs.insert({a, b});  
                    cout << "Pair found: (" << a << ", " << b << ")" << endl;
                    pairFound = true;
                }
            }
        }
    }
    if (!pairFound) {
        cout << "Looks like no pairs were found that equaled the target." << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    int size = rand() % 21 + 4;
    vector<int> array(size);
    int target = rand() % 201 - 100; 

    cout << "This is our target: " << target << "." << endl;
    cout << "Array: {";

    for (int i=0; i < array.size(); i++) {
        array[i] = rand() % 201 - 100; 
        cout << array[i];
        if (i < array.size() - 1) {
            cout << ", ";
            }
        }
            cout << "}" << endl;

    findPairs(array, target);  
}
