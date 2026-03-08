#include "Course.h" 
#include <vector> //
#include <iomanip> // for formatting output
/* Name: Tun Tun (Jonathan) Aung
 * Course: CSCI 272(1)
 * Professor: Avijit Roy
 * Date: Spring 2026
 * Team Project 1
 * Member: Tanzin Priyoh, Tun Tun (jonathan) Aung, Miguel Llapa
*/
int main()  {
    cout << string(62, '=') << "\n"; //format line
    cout << setw(42) << "Student Grade Report\n";
    cout << string(62, '=') << "\n"; //formatting

vector<Course> courses; // a vector to hold all courses from the users entries.
string name(""), grade("");
int numOfCourses(0), credits(0), totalCredit(0); //made int and string vales = to 0 or blank to
double totalPoints(0.0), gpa(0.0);
    //prevent random autofill.

cout << "How many courses did you take? ";
cin >> numOfCourses; //total courses taken.
cin.ignore(); //clears new line so that getline works later.

for(int i = 0; i < numOfCourses; ++i) { //loop for every course mentioned.

cout << "Course Name: ";
getline(cin, name);

cout << "Credit Hours: ";
cin >> credits;
    totalCredit += credits;
cin.ignore(); //added again so getline works once more when i call it again.

cout << "Letter Grade: ";
getline(cin, grade);

//once a course object is made its given data is added to this vector
//and pushed to the back of the list.
courses.push_back(Course(name, credits, grade));

cout << endl; //added so theres a clear space when a new courses info is being requested.
}
cout << "\n\n";

// loops through all courses and shows them all in a single line format.
cout << left  << setw(30) << "Course"
     << right << setw(15) << "Credits"
              << setw(15) << "Grade"
              << setw(15) << "Grade Points"
              << setw(15) << "Total Points" << endl;

    cout << string (90, '-') << "\n" ; //formatting line
for(int i = 0; i < courses.size(); ++i) {
    courses[i].display(); // will print Course name, credit, gradeLetter, gradeNum, and total in 1 line.
    totalPoints += courses[i].getTotalPoints(); // adds up all the total points for each course.
}

gpa = (totalCredit > 0) ? totalPoints / totalCredit: 0.0; //calculates gpa by dividing total poitns and total credits
    //checks for divide zero to handle bad input
string standing;
if (gpa >= 3.7) { //If else statement that determines student's standing based off gpa
    standing = "Dean's List";
} else if (gpa >= 2.0) {
    standing = "Good Standing";
} else {
    standing = "Probation";
}
    // Displays Total Credit, Total points, GPA, and standing in a neat and tidy format. Experimented with setw range, but putting at 45 for sake of personal preference
cout << string ( 90, '-') << "\n" ;
cout << left << setw(30) << "Total Credits:"
     << right << setw(45) << totalCredit << "\n";
cout << left << setw(30) << "Total Points:"
     << right << setw(45) << setprecision(2) << totalPoints << "\n";
cout << left << setw(30) << "Semester GPA: "
     << right << setw(45) << setprecision(2) << gpa << "\n";
cout << left <<  setw(30) << "Standing: "
     << right << setw(45) << standing << "\n";
cout << string(90, '=') << "\n";
return 0;
}

/* Tun Tun (Jonathan) Aung -- 3/7/26
 * Reflection and challenges: WIthin this group, my role is to take care of the main.cpp, which
 * poses few challenges such as working with what others have done and making sure that I am
 * recognizing public and private data and understanding how to format them.
 * Additionally, everyone worked at a different pace so there are also diffculties trying to move
 * forward without having other member done their part. Alot of place holders were used at _wfindfirstbut
 * since its diffcult to know how other members will work on their code.
 * E.g. I wasn't sure if I am responsible to calculate the gpa and standing in the main or
 * if member from student class is going to be working with it. (Avoiding redundancy)
 * */