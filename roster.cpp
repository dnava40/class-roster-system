//
//  roster.cpp
//  Programming Project
//
//  Created by Dylan Navarro on 4/21/21.
//
#include "roster.h"
#include <iostream>
using std::cout;
using std::endl;
DegreeProgram convert(string program) {
    if (program == "SECURITY") {
        return SECURITY;
    }
    if (program == "NETWORK") {
        return NETWORK;
    }
    if (program == "SOFTWARE") {
        return SOFTWARE;
    }
    else {
        return NONE;
    }
}
string DegreeProgramToString(DegreeProgram degreeProgram) {
    if (degreeProgram == SECURITY) {
        return "Security";
    }
    if (degreeProgram == NETWORK) {
        return "Network";
    }
    if (degreeProgram == SOFTWARE) {
        return "Software";
    }
    if (degreeProgram == NONE) {
        return "None";
    }
    else {
        return "Error";
    }
}
void Roster::ParseRosterString(const string rosterString[]) {
    for (int i = 0; i < 5; ++i) {
        size_t rhs = rosterString[i].find(",");
        classRosterArray[i]->SetStudentID(rosterString[i].substr(0, rhs));
        
        size_t lhs = rhs + 1;
        rhs = rosterString[i].find(",", lhs);
        classRosterArray[i]->SetFirstName(rosterString[i].substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = rosterString[i].find(",", lhs);
        classRosterArray[i]->SetLastName(rosterString[i].substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = rosterString[i].find(",", lhs);
        classRosterArray[i]->SetEmailAddress(rosterString[i].substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = rosterString[i].find(",", lhs);
        classRosterArray[i]->SetAge(rosterString[i].substr(lhs, rhs - lhs));
        
        string tempArray[3];
        
        lhs = rhs + 1;
        rhs = rosterString[i].find(",", lhs);
        tempArray[0] = rosterString[i].substr(lhs, rhs - lhs);
        
        lhs = rhs + 1;
        rhs = rosterString[i].find(",", lhs);
        tempArray[1] = rosterString[i].substr(lhs, rhs - lhs);
        
        lhs = rhs + 1;
        rhs = rosterString[i].find(",", lhs);
        tempArray[2] = rosterString[i].substr(lhs, rhs - lhs);
        classRosterArray[i]->SetNumDays(tempArray);
        
        lhs = rhs + 1;
        rhs = rosterString[i].find(",", lhs);
        classRosterArray[i]->SetDegreeProgram(convert(rosterString[i].substr(lhs, rhs - lhs)));
    }
}
void Roster::add(string studentID, string firstname, string lastName, string emailAddress, string age, string daysInCourse1, string daysInCourse2, string daysInCourse3, DegreeProgram degreeProgram) {
    bool studentCreated = false;
    for (int i = 0; i < 10; ++i) {
        if (studentID == classRosterArray[i]->GetStudentID() && studentCreated == false) {
            classRosterArray[i]->SetFirstName(firstname);
            classRosterArray[i]->SetLastName(lastName);
            classRosterArray[i]->SetEmailAddress(emailAddress);
            classRosterArray[i]->SetAge(age);
            classRosterArray[i]->SetNumDays1(daysInCourse1);
            classRosterArray[i]->SetNumDays2(daysInCourse2);
            classRosterArray[i]->SetNumDays3(daysInCourse3);
            classRosterArray[i]->SetDegreeProgram(degreeProgram);
            studentCreated = true;
        }
        else {
            if (classRosterArray[i]->GetStudentID() == "" && studentCreated == false) {
                classRosterArray[i]->SetStudentID(studentID);
                classRosterArray[i]->SetFirstName(firstname);
                classRosterArray[i]->SetLastName(lastName);
                classRosterArray[i]->SetEmailAddress(emailAddress);
                classRosterArray[i]->SetAge(age);
                classRosterArray[i]->SetNumDays1(daysInCourse1);
                classRosterArray[i]->SetNumDays2(daysInCourse2);
                classRosterArray[i]->SetNumDays3(daysInCourse3);
                classRosterArray[i]->SetDegreeProgram(degreeProgram);
                studentCreated = true;
            }
        }
    }
}
void Roster::remove(string studentID) {
    bool studentDeleted = false;
    for (int i = 0; i < 10; ++i) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            classRosterArray[i]->SetStudentID("");
            classRosterArray[i]->SetFirstName("");
            classRosterArray[i]->SetLastName("");
            classRosterArray[i]->SetEmailAddress("");
            classRosterArray[i]->SetAge("");
            classRosterArray[i]->SetNumDays1("");
            classRosterArray[i]->SetNumDays2("");
            classRosterArray[i]->SetNumDays3("");
            classRosterArray[i]->SetDegreeProgram(NONE);
            studentDeleted = true;
        }
    }
    if (studentDeleted == false) {
        cout << "Error: Student with that ID not found." << endl;
    }
}
void Roster::printAll() {
    for (int i = 0; i < 10; ++i) {
        classRosterArray[i]->print();
        }
        
    }
void Roster::PrintAverageDaysInCourse(string studentID) {
    bool foundStudent = false;
    for (int i = 0; i < 10; ++i) {
        if (((classRosterArray[i]->GetStudentID()) == studentID) && (foundStudent == false) && (classRosterArray[i]->GetStudentID() != "")) {
            string num1 = classRosterArray[i]->GetNumDays1();
            string num2 = classRosterArray[i]->GetNumDays2();
            string num3 = classRosterArray[i]->GetNumDays3();
            int int1 = stoi(num1);
            int int2 = stoi(num2);
            int int3 = stoi(num3);
            cout << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << "'s Average Days in Course: " << ((int1 + int2 + int3)/3) << "\n";
            foundStudent = true;
        }
    }
}
void Roster::PrintInvalidEmails() {
    bool foundAt;
    bool foundPeriod;
    bool foundSpace;
    cout << "Invalid Emails: ";
    for (int i = 0; i < 10; ++i) {
        foundAt = false;
        foundPeriod = false;
        foundSpace = false;
        if ((classRosterArray[i]->GetStudentID()) == "") {
            cout << endl;
            break;
        }
        string email = "";
        email = classRosterArray[i]->GetEmailAddress();
        if ((email.find('@')) != string::npos) {
            foundAt = true;
        }
        if ((email.find('.')) != string::npos) {
            foundPeriod = true;
        }
        if ((email.find(' ')) != string::npos) {
            foundSpace = true;
        }
        if (!foundAt || !foundPeriod || foundSpace) {
            cout << email << " ";
        }
    }
}
void Roster::PrintByDegreeProgram(DegreeProgram degreeprogram) {
    cout << "Students in Degree Program: " << DegreeProgramToString(degreeprogram) << endl;
    for (int i = 0; i < 10; ++i) {
        if ((classRosterArray[i]->GetDegreeProgram()) == degreeprogram) {
            cout << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << endl;
        }
    }
}
void Roster::populate() {
    for (int i = 0; i < 10; ++i) {
        classRosterArray[i] = new Student;
    }
}
string Roster::accessor(int i) {
    return classRosterArray[i]->GetStudentID();
}
void Roster::depopulate() {
    for (int i = 0; i < 10; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
        }
}
