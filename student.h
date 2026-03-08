/*
Name: Miguel llapa
Course: CSCI 272
Date: 
Group Project 1
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "course.h"
using namespace std;

class Student {
    private:
    string studentName; // added for class student object
    vector<Course> courses; // shows a list of courses a student was enrolled with using vector
    
    public: // Constructor for student name
    Student(string name) : studentName(name) { 
        
    }
    void addCourse(const Course& c) { //Added for course.h to start working
        courses.push_back(c); 
    }
    //Added so it can calculate the total GPA
    double calculateGPA() const {
        if (courses.empty()) return 0.0;
        
        double totalGradePoints = 0;
        int totalCredits = 0;
        
        for (const auto& course : courses){ //loop for any course mentioned
            totalGradePoints += course.getTotalPoints(); //Added for points earned in course
            totalCredits += course.getCredits(); // added for credits earned in course
        }
        
        if (totalCredits == 0) return 0.0;
        return totalGradePoints / totalCredits;
    }
    //A print to display the report card after filling out courses, hours
    // and grade later to display for the student
    void displayReportCard() const {
        cout << "\n--- Report Card for " << studentName << " ---" << endl;
        cout << left << setw(30) << "Course"
             << right << setw(15) << "Credits"
             << setw(15) << "Grade"
             << setw(15) << "Points"
             << setw(15) << "Total" << endl;
        cout << string(90, '-') << endl;
        
        for (const auto& course : courses) {
            course.display();
        }
        // Shows/displays the GPA and standing
        cout << string(90, '-') << endl;
        cout << "Cumulative GPA: " << fixed << setprecision(2) << calculateGPA() << endl;
    }
};

/*
Refection and challenges:
The challenges/difficult parts I came when handling student class is to filling
out the code for class Student and what needed to be done in order to
understand what I got wrong via errors. Another is understanding what needed to
put in public and what needed to put private in terms of how needed it needed
to format. That's when I was working on it, I was trying to understand how it it works
for private and public such as the string name and add course when using void.
*\