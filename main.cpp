#include "Course.h" 

int main()  {
    
 Course math("Calc 2", 3, "c-"); 
    
    cout << "Course: " << math.getName() << endl;
    cout << "Credits: " << math.getCredits() << endl;
    cout << "Grade: " << math.getGrade() << endl;
    cout << "Grade Points: " << math.getGradePoints() << endl;
    cout << "Total Points:" << math.getTotalPoints() << endl;
    
    return 0;
}
