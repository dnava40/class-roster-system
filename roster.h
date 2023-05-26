//
//  roster.h
//  Programming Project
//
//  Created by Dylan Navarro on 4/21/21.
//

#ifndef roster_h
#define roster_h
#include "student.h"
#endif /* roster_h */
class Roster {
public:
    void ParseRosterString(const string rosterString[]);
    void add(string studentID, string firstName, string lastName, string emailAddress, string age, string daysInCourse1, string daysInCourse2, string daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void PrintAverageDaysInCourse(string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degreeProgram);
    void populate();
    string accessor(int i);
    void depopulate();
private:
    Student * classRosterArray[10];
};

const string studentData[5] =
{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Dylan,Navarro,dnava40@wgu.edu,20,14,32,63,SOFTWARE"};
