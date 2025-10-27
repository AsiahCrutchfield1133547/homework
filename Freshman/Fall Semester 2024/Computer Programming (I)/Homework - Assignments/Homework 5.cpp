#include <iostream>
using namespace std;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; 
    while (exp > 0) {
        if (exp % 2 == 1)  
            result = (result * base) % mod;
        base = (base * base) % mod;  
        exp /= 2;  
    }
    return result;
}

int main() {
    long long a, b, c;
    int case_number = 1;
    const int MAX_CASES = 6;  

    while (case_number <= MAX_CASES && cin >> a && a != -1) {
        cin >> b >> c;
        cout << "Case " << case_number++ << ": " << mod_exp(a, b, c) << endl;
    }

    return 0;
}
