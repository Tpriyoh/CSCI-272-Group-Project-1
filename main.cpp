#include "Course.h" 
#include <vector> //need this to store many courses.

int main()  {

vector<Course> courses; // a vector to hold all courses from the users entries.
string name(""), grade("");
int numOfCourses(0), credits(0); //made int and string vales = to 0 or blank to 
//prevent random autofill.

cout << "How many courses did you take? ";
cin >> numOfCourses; //total courses taken.
cin.ignore(); //clears new line so that getline works later.

for(int i = 0; i < numOfCourses; ++i) { //loop for every course mentioned.

cout << "Course Name: ";
getline(cin, name);

cout << "Credit Hours: ";
cin >> credits;
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

for(int i = 0; i < courses.size(); ++i) {
    courses[i].display(); // will print Course name, credit, gradeLetter, gradeNum, and total in 1 line.
}


return 0;
}
