#include <iostream>
#include <string>
#include <vector>
#include "Book (problem4).hpp"
using namespace std;

int main() {
    int title;
    int quantity;
    int limit = 15;
    int book_num = 0;
    string title_name;
    bool overdue = false;

    vector<Book> books = {
        Book("Pride and Prejudice", "Charles Dickens"),
        Book("Super Interesting Book", "Mr. Smart Guy"),
        Book("Secrets of the Universe", "Science Lady"),
        Book("Learn a Language in 30 Seconds", "Fake Polyglot"),
        Book("Please, Buy My Book", "Broke Man")
    };

    books[0].setQuantity(10);
        books[1].setQuantity(2);
        books[2].setQuantity(5);
        books[3].setQuantity(4);
        books[4].setQuantity(20);

    while (overdue == false) {
        cout << "As a reminder, you can only have " << limit << " books at a time.\n";
        cout << "You currently have " << book_num << ".\n";
        cout << "Here is our book selection:\n";
        for (int i = 0; i < books.size(); i++) {
            cout << "[" << i+1 << "] \"" << books[i].getTitle() << "\" by " << books[i].getAuthor() << "\n"; 
        }
        cout << "\n";

        cout << "Which book would you like to borrow? ";
        cin >> title;

        if (title < 1 || title > books.size()) {
            cout << "We don't seem to have that book. Maybe you can type the title? ";
            cin >> title_name;
            if (title_name == books[title-1].getTitle() && books[title-1].getQuantity() > 0) {
                cout << "Oh, we currently have " << books[title-1].getQuantity() << " of \"" << books[title-1].getTitle() << "\"!\n";
                cout << "How many would you like? ";
                cin >> quantity;
                cout << "\n";
                book_num += quantity;
                books[title - 1].setQuantity(books[title - 1].getQuantity() - quantity);
            } else {
                cout << "Sorry, we couldn't find that book. How about you take another look at what we offer.\n";
            }
        } else if (quantity > books[title-1].getQuantity()) {
            cout << "That is more than we currently have. Try selecting another one.\n";
            continue;
        } else {
            cout << "We currently have " << books[title-1].getQuantity() << " of \"" << books[title-1].getTitle() << "\"!\n";
            cout << "How many would you like? ";
            cin >> quantity;
            cout << "\n";
            book_num += quantity;
            books[title - 1].setQuantity(books[title - 1].getQuantity() - quantity);
        }

        if (book_num >= limit) {
            cout << "You have " << book_num << " books. That's way too many. You can't get anymore.";
            overdue = true;
        }

        
    }
    
}