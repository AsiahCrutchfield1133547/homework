#include <iostream>
using namespace std;

void compress(string sentence) {
    int size = sentence.size();

    int count = 1;
    string result = "";

    for (int i = 0; i < size-1; i++) {
        if (sentence[i] == sentence[i+1]) {
            count++;
        }
        else {
            result += sentence[i] + to_string(count);
            count = 1;
        }
    }
    result += sentence[size - 1] + to_string(count);

    if (result.size() >= size) {
        cout << "We could not sufficiently compress your string so "
        << "this is the result: ";
        cout << sentence;
    }
    else{
    cout << "Let's see your new sentence: " << result;
    }
}

int main() {
    string sentence;

    cout << "Write any string and I'll see if I can make it shorter: ";
    cin >> sentence;

    compress(sentence);
}