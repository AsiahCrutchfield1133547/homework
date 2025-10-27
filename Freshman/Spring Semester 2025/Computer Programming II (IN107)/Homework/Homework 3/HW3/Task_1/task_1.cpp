#include <iostream>
#include <vector>
#include <string>
#include <initializer_list> // For convenient collection initialization
#include <stdexcept>        // For out_of_range
using namespace std;

// BEGIN YOUR CODE

namespace Task_1a {
    template <typename T>
    T max(const T& a, const T& b) {
        return (a > b) ? a : b;
    }

    template <typename T>
    T min(const T& a, const T& b) {
        return (a < b) ? a : b;
    }

    template <typename T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
}

namespace Task_1b {
    // Base case for max
    template <typename T>
    T max(const T& a) {
        return a;
    }

    // Recursive case for max
    template <typename T, typename... Args>
    T max(const T& a, const Args&... args) {
        T temp = max(args...);
        return (a > temp) ? a : temp;
    }

    // Overload for const char* to use std::string
    inline std::string max(const char* a) {
        return std::string(a);
    }

    template <typename... Args>
    std::string max(const char* a, const Args&... args) {
        std::string temp = max(args...);
        return (std::string(a) > temp) ? std::string(a) : temp;
    }

    // Base case for min
    template <typename T>
    T min(const T& a) {
        return a;
    }

    // Recursive case for min
    template <typename T, typename... Args>
    T min(const T& a, const Args&... args) {
        T temp = min(args...);
        return (a < temp) ? a : temp;
    }

    // Overload for const char* to use std::string
    inline std::string min(const char* a) {
        return std::string(a);
    }

    template <typename... Args>
    std::string min(const char* a, const Args&... args) {
        std::string temp = min(args...);
        return (std::string(a) < temp) ? std::string(a) : temp;
    }
}

template <typename T>
class SortableCollection {
private:
    std::vector<T> data;

public:
    // Default constructor
    SortableCollection() = default;

    // Constructor from initializer list
    SortableCollection(std::initializer_list<T> initList) : data(initList) {}

    // Add an element
    void add(const T& element) {
        data.push_back(element);
    }

    // Print all elements
    void print() const {
        for (const T& element : data) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // Get size of collection
    size_t getSize() const {
        return data.size();
    }

    // Get element at index, throw std::out_of_range if invalid
    T getElement(size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Sort the collection using selection sort
    void sort() {
        size_t n = data.size();
        for (size_t i = 0; i < n - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }
            if (i != minIndex) {
                Task_1a::swap(data[i], data[minIndex]);
            }
        }
    }
};

// END YOUR CODE

// Test cases
int main() {
    std::cout << "--- Testing Task_1a Non-Variadic Template Functions ---" << std::endl;

    // Test max (Task_1a)
    int a = 10, b = 5;
    std::cout << "Task_1a::max(" << a << ", " << b << "): " << Task_1a::max(a, b) << std::endl;
    double c = 3.14, d = 2.718;
    std::cout << "Task_1a::max(" << c << ", " << d << "): " << Task_1a::max(c, d) << std::endl;
    std::string s1 = "zebra", s2 = "apple";
    std::cout << "Task_1a::max(\"" << s1 << "\", \"" << s2 << "\"): " << Task_1a::max(s1, s2) << std::endl;

    std::cout << std::endl;

    // Test min (Task_1a)
    std::cout << "Task_1a::min(" << a << ", " << b << "): " << Task_1a::min(a, b) << std::endl;
    std::cout << "Task_1a::min(" << c << ", " << d << "): " << Task_1a::min(c, d) << std::endl;
    std::cout << "Task_1a::min(\"" << s1 << "\", \"" << s2 << "\"): " << Task_1a::min(s1, s2) << std::endl;

    std::cout << std::endl;

    // Test swap (Task_1a)
    int x = 1, y = 2;
    std::cout << "Before Task_1a::swap: x = " << x << ", y = " << y << std::endl;
    Task_1a::swap(x, y);
    std::cout << "After Task_1a::swap:  x = " << x << ", y = " << y << std::endl;

    double p = 1.1, q = 9.9;
    std::cout << "Before Task_1a::swap: p = " << p << ", q = " << q << std::endl;
    Task_1a::swap(p, q);
    std::cout << "After Task_1a::swap:  p = " << p << ", q = " << q << std::endl;

    std::string str1 = "hello", str2 = "world";
    std::cout << "Before Task_1a::swap: str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"" << std::endl;
    Task_1a::swap(str1, str2);
    std::cout << "After Task_1a::swap:  str1 = \"" << str1 << "\", str2 = \"" << str2 << "\"" << std::endl;

    std::cout << "\n--- Testing Task_1b Variadic Template Functions ---" << std::endl;

    // Test max (Task_1b) with varying arguments
    std::cout << "Task_1b::max(10): " << Task_1b::max(10) << std::endl;
    std::cout << "Task_1b::max(10, 5): " << Task_1b::max(10, 5) << std::endl;
    std::cout << "Task_1b::max(10, 5, 20): " << Task_1b::max(10, 5, 20) << std::endl;
    std::cout << "Task_1b::max(10, 5, 20, -3, 15): " << Task_1b::max(10, 5, 20, -3, 15) << std::endl;

    std::cout << "Task_1b::max(3.14, 1.618, 2.718): " << Task_1b::max(3.14, 1.618, 2.718) << std::endl;
    std::cout << "Task_1b::max(\"cat\", \"apple\", \"zebra\", \"banana\"): " << Task_1b::max("cat", "apple", "zebra", "banana") << std::endl;

    std::cout << std::endl;

    // Test min (Task_1b) with varying arguments
    std::cout << "Task_1b::min(10): " << Task_1b::min(10) << std::endl;
    std::cout << "Task_1b::min(10, 5): " << Task_1b::min(10, 5) << std::endl;
    std::cout << "Task_1b::min(10, 5, 20): " << Task_1b::min(10, 5, 20) << std::endl;
    std::cout << "Task_1b::min(10, 5, 20, -3, 15): " << Task_1b::min(10, 5, 20, -3, 15) << std::endl;

    std::cout << "Task_1b::min(3.14, 1.618, 2.718): " << Task_1b::min(3.14, 1.618, 2.718) << std::endl;
    std::cout << "Task_1b::min(\"cat\", \"apple\", \"zebra\", \"banana\"): " << Task_1b::min("cat", "apple", "zebra", "banana") << std::endl;

    std::cout << "\n--- Testing SortableCollection ---" << std::endl;

    // Test with integers
    std::cout << "Integer Collection:" << std::endl;
    SortableCollection<int> intCollection;
    intCollection.add(5);
    intCollection.add(2);
    intCollection.add(8);
    intCollection.add(1);
    intCollection.add(9);

    std::cout << "Before sorting: ";
    intCollection.print();
    std::cout << std::endl;

    intCollection.sort();

    std::cout << "After sorting:  ";
    intCollection.print();
    std::cout << std::endl;

    std::cout << std::endl;

    // Test with doubles (using initializer list constructor)
    std::cout << "Double Collection:" << std::endl;
    SortableCollection<double> doubleCollection = {3.14, 1.618, 2.718, 0.577, 9.9};

    std::cout << "Before sorting: ";
    doubleCollection.print();
    std::cout << std::endl;

    doubleCollection.sort();

    std::cout << "After sorting:  ";
    doubleCollection.print();
    std::cout << std::endl;

    std::cout << std::endl;

    // Test with strings
    std::cout << "String Collection:" << std::endl;
    SortableCollection<std::string> stringCollection;
    stringCollection.add("zebra");
    stringCollection.add("apple");
    stringCollection.add("cat");
    stringCollection.add("dog");
    stringCollection.add("banana");
    stringCollection.add("ant");

    std::cout << "Before sorting: ";
    stringCollection.print();
    std::cout << std::endl;

    stringCollection.sort();

    std::cout << "After sorting:  ";
    stringCollection.print();
    std::cout << std::endl;

    // Test exception handling for out-of-bounds access
    std::cout << "\n--- Testing SortableCollection Exception Handling ---" << std::endl;
    SortableCollection<int> smallCollection = {10, 20}; // Create a small collection

    std::cout << "Collection size: " << smallCollection.getSize() << std::endl;
    std::cout << "Attempting to access element at index " << smallCollection.getSize() << " (out of bounds)..." << std::endl;

    try {
        // Accessing index 2 in a collection of size 2 (valid indices are 0 and 1)
        smallCollection.getElement(smallCollection.getSize());
        // This line should not be reached if the exception is thrown
        std::cout << "Error: Exception was NOT thrown." << std::endl;
    } catch (const std::out_of_range& e) {
        // This block should be executed if std::out_of_range is thrown
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
         // Catch any other standard exceptions
         std::cout << "Caught an unexpected standard exception: " << e.what() << std::endl;
    }
    catch (...) {
        // Catch any other unexpected non-standard exceptions
        std::cout << "Caught an unknown unexpected exception." << std::endl;
    }
    std::cout << "Exception test complete." << std::endl;


    return 0;
}