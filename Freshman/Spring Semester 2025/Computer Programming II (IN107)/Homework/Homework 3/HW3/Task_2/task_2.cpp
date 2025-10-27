#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Helper function to trim whitespace
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

// BEGIN YOUR CLASS/FUNCTION

struct Product {
    string name;
    double unitPrice;
};

struct Customer {
    string name;
    char type;
};

// END YOUR CLASS/FUNCTION

int main() {
    map<string, Product> products;
    map<string, Customer> customers;

    // Read products.csv
    ifstream productFile("products.csv");
    if (!productFile) {
        cerr << "Failed to open products.csv\n";
        return 1;
    }

    string line;
    getline(productFile, line); // Skip header
    while (getline(productFile, line)) {
        stringstream ss(line);
        string productId, productName, priceStr;
        if (!getline(ss, productId, ',') ||
            !getline(ss, productName, ',') ||
            !getline(ss, priceStr, ',')) {
            cerr << "Skipping malformed product line: " << line << "\n";
            continue;
        }
        try {
            double price = stod(priceStr);
            products[productId] = {productName, price};
        } catch (...) {
            cerr << "Invalid price in product line: " << line << "\n";
        }
    }
    productFile.close();

    // Read customers.csv
    ifstream customerFile("customers.csv");
    if (!customerFile) {
        cerr << "Failed to open customers.csv\n";
        return 1;
    }

    getline(customerFile, line); // Skip header
    while (getline(customerFile, line)) {
        stringstream ss(line);
        string customerId, customerName, customerTypeStr;
        if (!getline(ss, customerId, ',') ||
            !getline(ss, customerName, ',') ||
            !getline(ss, customerTypeStr, ',')) {
            cerr << "Skipping malformed customer line: " << line << "\n";
            continue;
        }
        if (customerTypeStr.empty()) {
            cerr << "Missing customer type in line: " << line << "\n";
            continue;
        }
        customers[customerId] = {customerName, customerTypeStr[0]};
    }
    customerFile.close();

    // Prepare result.csv with full absolute path
    ofstream resultFile(R"(C:\Users\sunjs\Desktop\學校\Freshman\Spring Semester 2025\Computer Programming II (IN107)\Homework\Homework 3\HW3\Task_2\result.csv)");
    if (!resultFile) {
        cerr << "Failed to open result.csv for writing\n";
        return 1;
    }
    resultFile << "CustomerID,CustomerName,PriceUnit,Quantity,Amount,Discount,Total\n";

    // Read orders.csv and process
    ifstream orderFile("orders.csv");
    if (!orderFile) {
        cerr << "Failed to open orders.csv\n";
        return 1;
    }

    getline(orderFile, line); // Skip header
    while (getline(orderFile, line)) {
        stringstream ss(line);
        string orderId, customerId, productId, quantityStr, yearsLoyalStr;

        if (!getline(ss, orderId, ',') ||
            !getline(ss, customerId, ',') ||
            !getline(ss, productId, ',') ||
            !getline(ss, quantityStr, ',') ||
            !getline(ss, yearsLoyalStr, ',')) {
            cerr << "Skipping malformed order line: " << line << "\n";
            continue;
        }

        int quantity = 0;
        try {
            quantity = stoi(quantityStr);
            if (quantity < 0) {
                cerr << "Negative quantity in line: " << line << "\n";
                continue;
            }
        } catch (...) {
            cerr << "Invalid quantity in line: " << line << "\n";
            continue;
        }

        int yearsLoyal = 0;
        try {
            yearsLoyal = yearsLoyalStr.empty() ? 0 : stoi(yearsLoyalStr);
            if (yearsLoyal < 0) {
                cerr << "Negative yearsLoyal in line: " << line << "\n";
                continue;
            }
        } catch (...) {
            cerr << "Invalid yearsLoyal in line: " << line << "\n";
            continue;
        }

        if (customers.find(customerId) == customers.end()) {
            cerr << "Unknown customer ID: " << customerId << " in line: " << line << "\n";
            continue;
        }
        if (products.find(productId) == products.end()) {
            cerr << "Unknown product ID: " << productId << " in line: " << line << "\n";
            continue;
        }

        auto product = products[productId];
        auto customer = customers[customerId];

        double baseAmount = quantity * product.unitPrice;
        double discount = 0.0;
        const double vat = 0.1;

        if (customer.type == 'A') {
            discount = 0.0;
        } else if (customer.type == 'B') {
            double promoPercent = min(0.02 * yearsLoyal, 0.2);
            discount = baseAmount * promoPercent;
        } else if (customer.type == 'C') {
            discount = baseAmount * 0.7;
        } else {
            discount = 0.0;
        }

        double amountAfterDiscount = baseAmount - discount;
        double total = amountAfterDiscount * (1 + vat);

        resultFile << customerId << ","
                   << customer.name << ","
                   << fixed << setprecision(2) << product.unitPrice << ","
                   << quantity << ","
                   << fixed << setprecision(2) << baseAmount << ","
                   << discount << ","
                   << total << "\n";
    }
    orderFile.close();
    resultFile.close();

    cout << "Processing completed. Check result.csv for output.\n";

    return 0;
}
