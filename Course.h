#include <iostream>
#include <string>
using namespace std;


// the course blueprint
class Course {
    //private data only accessable to the class
private:
    string name; //ex math, english, science etc...
    int credits; //how many credits its worth.
    string grade; //letter grades only.
    
public:
//public data, built a constructor to make private data accessable we must identify the name,credits,grade in int main later.
    Course(string n, int c, string g) {
        name = n;
        credits = c;
        grade = g;
    } 
    
    //const getters - wont let others modify the classes data.
    // the const at the end means the function wont affect anything else.
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
    //error note: didnt add grade == after ||->(or) makinng everything default to 4.0
    //but I added the or just incase the user uses either a capital or lowercase letter.
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
    
};

