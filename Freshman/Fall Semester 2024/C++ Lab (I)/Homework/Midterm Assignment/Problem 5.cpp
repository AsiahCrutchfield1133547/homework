#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <vector>
#include <cmath> 
using namespace std;

bool hasSubarrayWithSum(const vector<int>& arr, int target) {
    int Sum = 0;
    int start = 0;
    
    for (int end = 0; end < arr.size(); end++) {
        Sum += arr[end];
        
        while (Sum > target && start <= end) {
            Sum -= arr[start];
            start++;
        }
        
        if (Sum == target) {
            return true;
        }
    }
    
    return false;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));


    vector<int> arr1 = {1, 4, 20, 3, 10, 5};
    int target1 = rand() % 99 + 2; 
    if (hasSubarrayWithSum(arr1, target1)) {
        cout << "Subarray found with sum " << target1 << endl;
    } else {
        cout << "No subarray found with sum " << target1 << endl;
    }

    vector<int> arr2 = {1, 4, 0, 0, 3, 10, 5};
    int target2 = rand() % 99 + 2;
    if (hasSubarrayWithSum(arr2, target2)) {
        cout << "Subarray found with sum " << target2 << endl;
    } else {
        cout << "No subarray found with sum " << target2 << endl;
    }

    return 0;
}
