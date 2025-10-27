#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <string>
#include <vector>
using namespace std;

class Student {
    string name;
    double id;
    vector<int> grades;

    public:
        Student(string name, double id, vector<int> grades) {
            this->name = name;
            this->id = id;
            this->grades = grades;
        };

        string showStudentName() {
            return name;
        };

        double showID() {
            return id;
        }

        vector<int> showGrades() {
            return grades;
        }

        ~Student() {
            cout << name << " is no longer a student here." << endl;
        }

};

int main() {
   
}