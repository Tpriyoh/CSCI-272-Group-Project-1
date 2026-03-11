/*
Name: Miguel llapa
Course: CSCI 272
Date: 03/08/26
Group Project 1
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Course.h"
using namespace std;

class Student {
    private:
    string studentName; // added for class student object
    vector<Course> courses; // shows a list of courses a student was enrolled with using vector
    
    public: // Constructor for student name
    Student(string name) : studentName(name) { 
        
    }
    // I (Bilal) deleted the get course and getGrade function because they werent running

    string getName() const { // get name for name (student name) also returns name for student
        return studentName;
    }

    void addCourse(const Course& c) { //Added so it can add a course to student record
        courses.push_back(c); 
    }

    //Added so it can calculate the total GPA
    double calculateGPA() const {
        if (courses.empty()) return 0.0;
        
        double totalGradePoints = 0;
        int totalCredits = 0;
        
        for (const auto& course : courses){ //loop for any course mentioned to aggregate data
            totalGradePoints += course.getTotalPoints(); //Added for points earned in course
            totalCredits += course.getCredits(); // added for credits earned in course
        }
        
        if (totalCredits == 0) return 0.0;
        return static_cast<double> (totalGradePoints) / totalCredits; //added cast to double and ensure for the floating point for calculations
    }

    //A print to display the report card after filling out courses, hours
    // and grade later to display for the student
    void displayReportCard()  { //I removed the const because const wouldnt allow me to modify the vector.
        double totalPoints = 0; //
        int totalCredits = 0; //
        
        sort(courses.begin(),courses.end(),[] (Course& a, Course& b) {
            return a.getCredits() > b.getCredits();
        });
        
        cout << "\n--- Student Grade Report " << studentName << " ---" << endl;
        cout << left << setw(30) << "Course"
             << right << setw(15) << "Credits"
             << setw(15) << "Grade"
             << setw(15) << "Grade Points"
             << setw(15) << "Total Points" << endl;
        
        cout << string(90, '-') << "\n"; //Formatting line
        
        for (const auto& course : courses) {
            course.display(); //this will print course name, credit, grade letter, and grade and total in 1 line
            totalPoints += course.getTotalPoints(); //adds up all total points for each course //mistake was a simple extra s in course.
            totalCredits += course.getCredits();
        }

        double gpa = (totalCredits > 0) ? totalPoints / totalCredits: 0.0; //(totalCredits) was missing an s
         //Checks for divide zero to handle bad input
        string standing;
        if (gpa >= 3.7) { //If else statement that determines student's standing based on their gpa
            standing = "Dean's List";
        } else if (gpa >= 2.0) {
            standing = "Good Standing";
        } else {
            standing = "Probation";
        }
        
        // loops through all courses and shows all in single line format.
        cout << string(90, '-') << endl;
        cout << left << setw(30) << "Total Credits:"
             << right << setw(45) << totalCredits << "\n"; // << totalCredits was also missing an s
        cout << left << setw(30) << "Total Points:"
             << right << setw(45) << setprecision(2) << totalPoints << "\n";
        cout << left << setw(30) << "Semester GPA: " 
            << right << setw(45) << setprecision(2) << gpa << "\n";
        cout << left << setw(30) << "Standing: "
             << right << setw(45) << standing << "\n";
        cout << string(90, '=') << "\n";
    }
};

/*
Reflection and challenges:
The challenges/difficult parts I encountered when handling student class is to filling
out the code for class Student and what needed to be done to better
understand for what I got wrong via errors. Another is understanding what needs to be placed
in public function and whats needed to be put in the private functions 
in terms of how it needs to be formatted. That's when I was working on
it, I was trying to understand how it it works for private and public,
such as the string name and adding a course when using void. As well as understanding const
auto and how it works for course display, credits and total points for course when it
comes to calculate the GPA. 
*\
