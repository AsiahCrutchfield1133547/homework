// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    cout << "I bet you can't guess how long this sentence is. \n";
    string sentence = "This is a sentence.";
    int sentence_total = sentence.length();
    int counter = 0;
    int player;
    cout << "What's your guess? ";
    cin >> player;
    while (counter < 3) {
           if (player != sentence_total) {
               counter + 1;
               cout << "Try again. ";
               cin >> player;
          } else if (player == sentence_total){
               cout << "You got it! The sentence had " << sentence_total;
           } else {
               cout << "You lose! it was " << sentence_total;
           }
    
   }
}