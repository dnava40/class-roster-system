//
//  student.h
//  Programming Project
//
//  Created by Dylan Navarro on 4/21/21.
//

#ifndef student_h
#define student_h
#include <string>
#include "degree.h"
using std::string;

#endif /* student_h */
class Student {
public:
    string GetStudentID();
    void SetStudentID(string ID);
    string GetFirstName();
    void SetFirstName(string fName);
    string GetLastName();
    void SetLastName(string lName);
    string GetEmailAddress();
    void SetEmailAddress(string eAddress);
    string GetAge();
    void SetAge(string newAge);
    string GetNumDays1();
    string GetNumDays2();
    string GetNumDays3();
    void SetNumDays(string array[]);
    void SetNumDays1(string numDays1);
    void SetNumDays2(string numDays2);
    void SetNumDays3(string numDays3);
    DegreeProgram GetDegreeProgram();
    void SetDegreeProgram(DegreeProgram program);
    Student(string ID, string fName, string lName, string eAddress, string age, DegreeProgram dProgram, string days[]);
    Student();
    void print();
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    string age;
    string numDays[3];
    DegreeProgram degreeProgram;
};
