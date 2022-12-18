/*
* File: student.cpp
* Author: Jon Lindemann
*
* Created on August 13th, 2022
*/

#include "student.h"


Student::Student() // Constructor with no parameter - sets all values to default
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse1 = 0;
	this->daysInCourse2 = 0;
	this->daysInCourse3 = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;

}
// Full constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse1 = daysInCourse1;
	this->daysInCourse2 = daysInCourse2;
	this->daysInCourse3 = daysInCourse3;
	this->degreeProgram = degreeProgram;

}

Student::~Student() {}

// Getters or Accessors
string Student::getID() { return this->studentID; }
string Student::getfirstName() { return this->firstName; }
string Student::getlastName() { return this->lastName; }
string Student::getEmail() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int Student::getdays1() { return this->daysInCourse1; }
int Student::getdays2() { return this->daysInCourse2; }
int Student::getdays3() { return this->daysInCourse3; }
DegreeProgram Student::getdegreeprogram() { return this->degreeProgram; }

// Setters or Mutators
void Student::setID(string studentID) { this->studentID = studentID; }
void Student::setfirstName(string firstName) { this->firstName = firstName; }
void Student::setlastName(string lastName) { this->lastName = lastName; }
void Student::setemailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setdays1(int daysInCourse1) { this->daysInCourse1 = daysInCourse1; }
void Student::setdays2(int daysInCourse2) { this->daysInCourse2 = daysInCourse2; }
void Student::setdays3(int daysInCourse3) { this->daysInCourse3 = daysInCourse3; }
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// Print header row to display categories - separated by tabs

void Student::printHeader()
{
	cout << "Student ID\t";
	cout << "First Name\t";
	cout << "Last Name\t";
	cout << "Email\t";
	cout << "Age\t";
	cout << "Days in Course\t";
	cout << "Degree Program";
	cout << endl;
}

void Student::print() // print method - separated by tabs
{
	cout << this->studentID << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->emailAddress << '\t';
	cout << this->age << '\t';
	cout << this->daysInCourse1 << ", ";
	cout << this->daysInCourse2 << ", ";
	cout << this->daysInCourse3 << '\t';
	cout << DegreeProgramStrings[(int)this->degreeProgram];
	cout << endl;
}