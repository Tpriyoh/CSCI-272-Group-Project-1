#include "Course.h"
#include <vector>
#include <cctype> //forces everything to be uppercase letter.
#include <iomanip> // for formatting output


int main()  {
	cout << string(62, '=') << "\n"; //format line
	cout << setw(42) << "Student Grade Report\n";
	cout << string(62, '=') << "\n"; //formatting


	int numberofCourses;
	cout <<"How many courses did you take between 1-10: ";
	cin >> numberofCourses;

	while (cin.fail() || numberofCourses < 1 || numberofCourses > 10) {
		cin.clear(); //removes error from incorrect input for reattempt

		cin.ignore(); //removes whatever they typed if it was not a number.

		cout << "Invalid Input. Please enter a number between 1-10: ";
		cin >> numberofCourses;
	}

	cin.ignore();
	
	

	vector<Course> courses; // a vector to hold all courses from the users entries.
	string name(""), grade("");
	int credits(0), totalCredit(0); //made int and string vales = to 0 or blank to
    //prevent random autofill.
    double totalPoints(0.0), gpa(0.0);

	




	for(int i = 0; i < numberofCourses; ++i) { //loop for every course mentioned.

		cout << "Course Name: ";
		getline(cin, name);
		
		
		

		cout << "Credit Hours: ";
		cin >> credits;

		while(cin.fail() || credits < 0) {
			cin.clear();
			cin.ignore();
			cout <<"Invalid input. Enter a 0 or a positive number: ";
			cin >> credits;
		}
		cin.ignore(); //added again so getline works once more when i call it again.
		totalCredit += credits;
		
		
		

		cout << "Letter Grade: ";
		getline(cin, grade);

		for(int j = 0; j < grade.size(); ++j) {
			grade[j] = toupper(grade[j]);
		}

        //keeps checking if the grade isnt one of the following ones. if invalid it will say invalid entry.
        //if grade DOES = "A" the loop stops right there and spits out that result
        //if it equals nothing on that list it will push the error.
		while (grade != "A" && grade != "A-" && grade != "B+" && grade != "B" &&
		        grade != "B-" && grade != "C+" && grade != "C" && grade != "C-" &&
		        grade != "D" && grade != "F") {

			cout << "Invalid Entry. What is your 'letter' grade: ";
			getline(cin, grade);

		}
		
		
		

        //once a course object is made its given data is added to this vector
        //and pushed to the back of the list.
		courses.push_back(Course(name, credits, grade));

		cout << endl; //added so theres a clear space when a new courses info is being requested.

	    } //end of loop



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
