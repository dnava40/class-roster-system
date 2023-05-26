//
//  student.cpp
//  Programming Project
//
//  Created by Dylan Navarro on 4/21/21.
//

#include <stdio.h>
#include "student.h"
#include <iostream>
using std::cout;
string StudentDegreeProgramToString(DegreeProgram degreeProgram) {
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

string Student::GetStudentID() {
    return studentID;
}
void Student::SetStudentID(string ID) {
    studentID = ID;
}
string Student::GetFirstName() {
    return firstName;
}
void Student::SetFirstName(string fName) {
    firstName = fName;
}
string Student::GetLastName() {
    return lastName;
}
void Student::SetLastName(string lName) {
    lastName = lName;
}
string Student::GetEmailAddress() {
    return emailAddress;
}
void Student::SetEmailAddress(string eAddress) {
    emailAddress = eAddress;
}
string Student::GetAge() {
    return age;
}
void Student::SetAge(string newAge) {
    age = newAge;
}
string Student::GetNumDays1() {
    return numDays[0];
}
string Student::GetNumDays2() {
    return numDays[1];
}
string Student::GetNumDays3() {
    return numDays[2];
}
void Student::SetNumDays(string array[]) {
    numDays[0] = array[0];
    numDays[1] = array[1];
    numDays[2] = array[2];
}
void Student::SetNumDays1(string numDays1) {
    numDays[0] = numDays1;
}
void Student::SetNumDays2(string numDays2) {
    numDays[1] = numDays2;
}
void Student::SetNumDays3(string numDays3) {
    numDays[2] = numDays3;
}
DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}
void Student::SetDegreeProgram(DegreeProgram program) {
    degreeProgram = program;
}
Student::Student(string ID, string fName, string lName, string eAddress, string age, DegreeProgram dProgram, string days[]) {
    studentID = ID;
    firstName = fName;
    lastName = lName;
    emailAddress = eAddress;
    this->age = age;
    degreeProgram = dProgram;
    numDays[0] = days[0];
    numDays[1] = days[1];
    numDays[2] = days[2];
}
Student::Student() {
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";
    age = "";
    degreeProgram = NONE;
    numDays[0] = "";
    numDays[1] = "";
    numDays[2] = "";
}
void Student::print() {
    if (studentID != "") {
        cout << studentID << " \t";
        cout << "First Name: " << firstName << " \t";
        cout << " Last name: " << lastName << " \t";
        cout << " Age: " << age << " \t";
        cout << " Days In Course: {" << numDays[0] << ", " << numDays[1] << ", " << numDays[2] << "} \t";
        cout << " Degree Program: " << StudentDegreeProgramToString(degreeProgram) << std::endl;
    }
}
