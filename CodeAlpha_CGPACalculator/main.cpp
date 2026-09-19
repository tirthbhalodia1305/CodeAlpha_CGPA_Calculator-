#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Course {
    string name;
    char grade;
    float credits;
    float gradepoint;
};

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<Course> courses(n);
    float totalcredits = 0;
    float totalgradepoints = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter detail for course " << i + 1 << endl;
        cout << "Course name: ";
        cin >> courses[i].name;
        cout << "Enter grade (A/B/C/D/F): ";
        cin >> courses[i].grade;
        cout << "Enter credit hours: ";
        cin >> courses[i].credits;

        switch (courses[i].grade) {
            case 'A': case 'a': courses[i].gradepoint = 10; break;
            case 'B': case 'b': courses[i].gradepoint = 8; break;
            case 'C': case 'c': courses[i].gradepoint = 6; break;
            case 'D': case 'd': courses[i].gradepoint = 5; break;
            case 'F': case 'f': courses[i].gradepoint = 0; break;
            default:
                cout << "Invalid grade!" << endl;
                courses[i].gradepoint = 0;
        }

        totalcredits += courses[i].credits;
        totalgradepoints += courses[i].gradepoint * courses[i].credits;
    }

    // calculate GPA safely
    float GPA = (totalcredits > 0) ? (totalgradepoints / totalcredits) : 0;

    // display course details
    cout << "\n====== Course Details =======\n";
    cout << left << setw(15) << "Course"
         << setw(10) << "Grade"
         << setw(10) << "Credits"
         << setw(12) << "Grade Points" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << courses[i].name
             << setw(10) << courses[i].grade
             << setw(10) << courses[i].credits
             << setw(12) << courses[i].gradepoint << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalcredits;
    cout << "\nTotal Grade Points: " << totalgradepoints;
    cout << "\nSemester GPA: " << GPA;

    // single semester, CGPA = GPA
    float CGPA = GPA;
    cout << "\nOverall CGPA: " << CGPA << endl;

    return 0;
}
