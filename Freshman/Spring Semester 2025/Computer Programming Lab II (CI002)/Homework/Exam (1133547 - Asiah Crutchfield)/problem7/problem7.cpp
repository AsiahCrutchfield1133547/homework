#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void isPalindrome(char* str, int size) {
    vector<char> newWord;

    // Create the reversed word
    for (int i = size - 1; i >= 0; i--) {
        newWord.push_back(str[i]);
    }

    bool palindromeOrNo = true;
    for (int i = 0; i < size; i++) {
        if (str[i] != newWord[i]) {
            palindromeOrNo = false;
            break;
        }
    }

    // Printing the reversed word
    cout << "Reversed: ";
    for (char c : newWord) {
        cout << c;
    }
    cout << endl;

    // Output if it's a palindrome or not
    if (palindromeOrNo) {
        cout << "\"" << str << "\" is a palindrome.\n"; 
    } else {
        cout << "\"" << str << "\" is not a palindrome because it looks like this backwards: \"";
        for (char c : newWord) {
            cout << c;
        }
        cout << "\".\n"; 
    }
    cout << endl;
}

int main() {
    char word[] = "bear";  // Example string
    int size = strlen(word);

    isPalindrome(word, size);
}
