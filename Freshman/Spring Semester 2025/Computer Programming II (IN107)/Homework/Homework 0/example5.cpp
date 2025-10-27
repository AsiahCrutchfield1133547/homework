#include <iostream>
#include <string>
using namespace std;

struct profile {
    string fullname;
    double score;
    string grade;
};

string calculateGrade(double score) {
    if (score >= 9.0) return "A";
    else if (score >= 8.0) return "B+";
    else if (score >= 7.0) return "B";
    else if (score >= 6.0) return "C+";
    else if (score >= 5.0) return "C";
    else if (score >= 4.5) return "D+";
    else if (score >= 4.0) return "D";
    else return "F";
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    profile students[n];  // Declare an array of profiles

    // Input details for each student
    for (int i = 0; i < n; i++) {
        cout << "Enter full name of student " << i + 1 << ": ";
        cin.ignore();  // Ignore the newline character left in the buffer
        getline(cin, students[i].fullname);

        cout << "Enter score of " << students[i].fullname << ": ";
        cin >> students[i].score;

        // Calculate grade based on score
        students[i].grade = calculateGrade(students[i].score);
    }

    // Print the results
    cout << "\nFULL NAME\tSCORE\tGRADE\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << students[i].fullname << "\t" << students[i].score << "\t" << students[i].grade << endl;
    }

    return 0;
}
