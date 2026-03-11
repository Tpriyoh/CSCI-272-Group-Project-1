/* 
Name: Tanzin Priyoh
Course: CSCI 272(1)
Group Project 1
*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// the course blueprint
class Course {
    //private data only accessable to the class
private:
    string name; //ex math, english, science etc...
    int credits; //how many credits its worth.
    string grade; //letter grades only.
    
public:
// Default constructor useful for arrays:
Course() {
    name = "";
    credits = 0;
    grade = "";
}
//public data, built a constructor to make private data accessable we must identify the name,credits,grade in int main later.
    Course(string n, int c, string g) {
        name = n;
        credits = c;
        grade = g;
    } 
    
    //const getters - wont let others modify the classes data.
    //using const at the end makes the function read only so you don't accidentally change your data
    //it stops bugs and is a good habit or so i was told by Claud AI 
    string getName() const {
        return name;
    }
    int getCredits() const {
        return credits;
    }
    string getGrade() const {
        return grade;
    }
    
    // converting letter grades to points
    //error note: didnt add grade == after ||  makinng everything default to 4.0
    //but I added the or just incase the user uses either a capital or lowercase letter.
    // we later fixed this problem using <cctype> making all lowercase letters default to capital letters.
    double getGradePoints() const {
        if (grade == "A" || grade == "a") return 4.0;
        if (grade == "A-" || grade == "a-") return 3.7;
        if (grade == "B+" || grade == "b+") return 3.3;
        if (grade == "B" || grade == "b") return 3.0;
        if (grade == "B-" || grade == "b-") return 2.7;
        if (grade == "C+" || grade == "c+") return 2.3;
        if (grade == "C" || grade == "c") return 2.0;
        if (grade == "C-" || grade == "c-") return 1.7;
        if (grade == "D" || grade == "d") return 1.0;
        if (grade == "F" || grade == "f") return 0.0;
        return 0.0; //if none of the above match.
    }
    
    //needed for student.h to calculate total points.
    double getTotalPoints() const {
        return credits * getGradePoints();
    }
    
    
    //cleaner display function for all data on a formatted line.
    //Refrence https://en.cppreference.com/w/cpp/io/manip/setw
    //had issues where if the setw size was too small letters would output without any spacing. like setw(5)
    void display() const {
        cout << left << setw(30) << name
        << right << setw(15) << credits
        << setw(15) << grade << fixed << setprecision(2)
        << setw(15) << getGradePoints()
        << setw(15) << getTotalPoints() << endl;
    }
};

/*
Tanzin Priyoh --- 3/7/26
The difficult parts for me were figuring out where const belonged in the getter functions
because I kept getting errors until I figured out it belongs after you make the paramater list.
For setw() I had a problem with numbers printing next to eachother because I used a small range like setw(5)
instead of  giving it more room inbetween entries.
Next I had a problem with the getGradePoints() function because I wrote (grade == "A" || "a") which made the entire list 
default to 4.0 everytime you ran the code.
And in int main() I used #include <cctype> to force all lowercase letters to become uppercase unlike here because I
forgot about how to originally do that until I looked up a website for how it worked.
*/
