/* Name: Tun Tun (Jonathan) Aung
 * Course: CSCI 272(1)
 * Professor: Avijit Roy
 * Date: Spring 2026
 * Team Project 1
 * Member: Tanzin Priyoh, Tun Tun (jonathan) Aung, Miguel Llapa, Bilal Ahmed
*/
#include <limits> //cite: for purpose of .begin() .end(), introduced through claude, further learning done through stackoverflow post on syntax especially the idea of why != instead of ==.
#include <algorithm>
#include "Student.h"//Only need this file since my teammate have pretty much included everything else
int main()  {
    cout << string(62, '=') << "\n"; //format line
    cout << setw(42) << "Student Grade Report\n";
    cout << string(62, '=') << "\n"; //formatting

    //vector<Course> courses; // a vector to hold all courses from the users entries.// we already have this in student.h dont need it here
    string name(""), grade("");
    int numOfCourses(0), credits(0), totalCredit(0); //made int and string vales = to 0 or blank to

    cout << "Student Name: :" ; //Prompt user to enter name
    getline(cin, name);
    Student student(name); //Create student object using teammate's student class. Will own all courses // Moved the line down so the student name actually prints on the report card since we are using the student.h file


    cout << "How many courses did you take?(1-10): ";
    //While loop was study and referenced through combination of stackoverflow and claude ai for logic understanding
    while (!(cin >> numOfCourses)|| numOfCourses <=1 || numOfCourses >= 10) { //validate bad input, this says, keep asking for input until there is no empty input and its within 1 <= x <= 10
        cin.clear(); //reset cin so it can be used again
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //learned in class, trying this, prof says this flushes the bad input during class. basically after every cin >>, theres left over '\n', in buffer. this .ignore(...) helps us ignore it
        cout <<" Invalid input. Enter a number between 1 and 10: ";
    }
    cin.ignore(); //clears leftover newline
    for(int i = 0; i < numOfCourses; ++i) { //loop for every course mentioned.

        cout << "Course Name: ";
        getline(cin, name);

        cout << "Credit Hours: ";
        while (!(cin >> credits) || credits <0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //build a habit of using this after every cin.
            cout << "Invalid input, put in number greater than 0: ";
        }
        totalCredit += credits;
        cin.ignore(); //added again so getline works once more when i call it again.

        vector<string> validGrade = {"A","a","A-","a-","B+","b+","B","b","B-","b-","C+","c+","C","c","C-","c-","D","d","F","f"};
        cout << "Letter Grade(A, A-, B+, B, B-, C+, C, C-, D, F): ";
        getline(cin, grade);
        while (find(validGrade.begin(), validGrade.end(), grade)== validGrade.end()) { //This says to use .find() go through the entier validGrade list, if it finds it, the while loop breaks, but if it reaches the end (validGrade.end() == True, then ask again
            cout << " Invalid grade input, use either {A, A-, B+, B, B-, C+, C, C-, D, F} \n";
            cout << "Letter Grade: ";
            getline(cin, grade);
        }
        //once a course object is made its given data is added to this vector
        //and pushed to the back of the list.

        //courses.push_back(Course(name, credits, grade)); //Tanzin's code
        student.addCourse(Course(name, credits, grade));

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
    student.displayReportCard();


    }


// I (Bilal) Worked on fixing the errors and made the extra credit sorting algorithum.
// Id say the hard part for me was the intitial errors that I into where the code wasnt working due to getCourse and getGrade function not being called properly untill i deleted them and the function was running without a problem.
// There were some extremely minor errors that were causing issue aswell. It took me a while to realise i can just use the ctrl+f command to make sure were calling the right function.
// The final issue that I had was with sorting where I first tried for loops but they were kind of confusing. I watched a video on youtube where it showed me asimple sort library that pretty much does it for me.



/* Tun Tun (Jonathan) Aung -- 3/7/26
 * Reflection and challenges:
 * 1. WIthin this group, my role is to take care of the main.cpp, which
 * poses few challenges such as working with what others have done and making sure that I am
 * recognizing public and private data and understanding how to format them.
 * Additionally, everyone worked at a different pace so there are also diffculties trying to move
 * forward without having other member done their part. Alot of place holders were used at _wfindfirstbut
 * since its diffcult to know how other members will work on their code.
 * E.g. I wasn't sure if I am responsible to calculate the gpa and standing in the main or
 * if member from student class is going to be working with it. (Avoiding redundancy)
 *
 * 2. Trying to come up with ways to use while loop to error proof each input intake and their scenarios.
 *
 * 3. Understanding the use of cin.clear() and cin.ignore(numeric_limits<streamsize>::max(), '\n') as this is my firs
 * time using this.
 *
 * 4.While loop was not covered in class but the concept was introduced to me before through prior classes, however syntax and use were different
 * i used resoures like claude ai and stackoverflow to understand. AI to provide detail break down examples, and stackoverflow to see realworld
 * nuance.
 * */