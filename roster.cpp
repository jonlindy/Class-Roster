/*
* File: roster.cpp
* Author: Jon Lindemann
*
* Created on August 13th, 2022
*/

#include "roster.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;


// Roster::Roster() {}

// PARSE METHOD - Using find & substr between commas
void Roster::parse(string studentData)
{

	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stod(studentData.substr(lhs, rhs - lhs));

	DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
	if (studentData.back() == 'Y') degreeProgram = DegreeProgram::SECURITY;
	else if (studentData.back() == 'K') degreeProgram = DegreeProgram::NETWORK;

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram); // Object created
	// cout << "Student added to class roster at Row " << lastIndex + 1 << endl; // updates to row of current Student (i+1)
}




void Roster::printAll() // Prints header and ALL students
{
	Student::printHeader();  // Function definied in Student class
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();  // Each student prints in loop
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) // Print Students of specified Degree
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
		if (Roster::classRosterArray[i]->getdegreeprogram() == degreeProgram)  // Finds students of given degree and prints
			classRosterArray[i]->print();
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)    // Loop through students
	{
		if (Roster::classRosterArray[i]->getID() == studentID)   // Find matching ID
		{
			cout << studentID << ": ";
			cout << ((classRosterArray[i]->getdays1() +             // Adds # days for each course, divides by 3.0 for float division
				classRosterArray[i]->getdays2() +
				classRosterArray[i]->getdays3()) / 3.0)
				<< endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::lastIndex; i++)  // Loop through students
	{
		string email = Roster::classRosterArray[i]->getEmail(); // Get Student's email   
		if ((email.find('@') == string::npos && email.find('.') == string::npos) || email.find(' ') != string::npos) // Finds spaces and checks for @ and .
			cout << "Invalid email address: " << email << endl;  // Print invalids
	}
}

void Roster::remove(string studentID)
{
	bool removed = false;
	for (int i = 0; i <= Roster::lastIndex; i++)   // Loop through students
	{
		if (classRosterArray[i]->getID() == studentID)    // Find matching ID
		{
			removed = true;
			Student* temp = classRosterArray[i];			// Swap Student-to-remove with last Student
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temp;		// Reduce lastIndex to remove last Student
			Roster::lastIndex = Roster::lastIndex - 1;
		}
	}
	if (removed)
	{
		cout << "Student " << studentID << " has been removed." << endl;
	}
	else {
		cout << "Error: Student " << studentID << " not found." << endl;
		Roster::lastIndex++;
	}

}

Roster::~Roster()	// Destructor 
{
	for (int i = 0; i < numStudents; i++)   // Destructor loop uses const numStudents in order to delete ALL Students
	{
		cout << "Destructor called for " << classRosterArray[i]->getID() << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;  // set to null after deletion
	}
}