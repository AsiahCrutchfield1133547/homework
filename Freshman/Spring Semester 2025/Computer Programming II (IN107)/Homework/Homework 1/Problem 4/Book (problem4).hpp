#include <string>
using namespace std;

class Book {
    string title;
    string author;
    int quantity;

    public:
        // Setters
         // Constructor
         Book(string Title, string Author) {
            title = Title;
            author = Author;
        }

        void setQuantity(int Quantity) {
            quantity = Quantity;
        }

        // Getters
        int getQuantity() {
            return quantity;
        }
        
        string getTitle() {
            return title;
        }

        string getAuthor() {
            return author;
        }
};