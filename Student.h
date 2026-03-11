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
#include "Course.h"
using namespace std;

class Student {
    private:
    string studentName; // added for class student object
    vector<Course> courses; // shows a list of courses a student was enrolled with using vector
    
    public: // Constructor for student name
    Student(string name) : studentName(name) { 
        
    }
    
    string getCourse() const { // get name for course, returns course name
        return courses;
    }

    string getGrade() const { // get name for grade, returns student grade
        return grade;
    }

    string getName() const { // get name for name (student name) also returns name for student
        return studentName;
    }

    void addCourse(const Course& c) { //Added so it can add a course to student record
        courses.push_back(c); 
    }

    // Returns courses through and addede vector so that main() can loop through them
    const vector<Course>& getCourses() const {
        return courses;
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
        cout << "\n--- Student Grade Report " << studentName << " ---" << endl;
        cout << left << setw(30) << "Course"
             << right << setw(15) << "Credits"
             << setw(15) << "Grade"
             << setw(15) << "Grade Points"
             << setw(15) << "Total Points" << endl;
        
        cout << string(90, '-') << "\n"; //Formatting line
        for (int i = 0; i < courses.size(); ++1) {
            course[i].display(); //this will print course name, credit, grade letter, and grade and total in 1 line
            totalPoints += courses[i].getTotalPoints(); //adds up all total points for each course
        }

        gpa = (totalCredit > 0) ? totalPoints / totalCredits: 0.0;
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
             << right << setw(45) << totalCredit << "\n";
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
out the code for class Student and what needed to be done in order to
understand what I got wrong via errors. Another is understanding what needs to be placed
in public function and whats needed to be put in the private functions 
in terms of how needed it needed to format. That's when I was working on
it, I was trying to understand how it it works
for private and public, such as the string name and add course when using void.
*\
