//
//  main.cpp
//  Programming Project
//
//  Created by Dylan Navarro on 4/21/21.
//

#include <iostream>
#include "roster.h"
using namespace std;
int main() {
    cout << "C867 - Scripting and Programming Applications" << "\n" << "Programming Language: C++" << "\n" << "\n" << "Name: Dylan Navarro" << endl;
    
    Roster classRoster;
    classRoster.populate();
    classRoster.ParseRosterString(studentData);
    classRoster.printAll();
    classRoster.PrintInvalidEmails();
    for (int i = 0; i < 10; ++i) {
        classRoster.PrintAverageDaysInCourse(classRoster.accessor(i));
    }
    classRoster.PrintByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    classRoster.depopulate();
    return 0;
}
 

