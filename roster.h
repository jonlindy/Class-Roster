/*
* File: roster.h
* Author: Jon Lindemann
*
* Created on August 13th, 2022
*/
#ifndef ROSTER_H
#define ROSTER_H

#include <sstream>
#include "student.h"
#include <stdio.h>
#include <string>

class Roster
{
public:
	int lastIndex = -1; // declare starting position
	const static int numStudents = 5;
	Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr }; // declared statically

public:
	//Roster();   // Constructor
	//Roster(int max);

	void parse(string row);
	// Add Student to Roster 
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);
	void remove(string studentID); // Finds and removes Student from Roster by ID. If ID does not exist - function prints error "Student was not found."
	void printAll(); // Displays all Students in Data table
	void printAverageDaysInCourse(string studentID); // Prints student's average days in a course. Student identified by studentID
	void printInvalidEmails(); // verifies email addresses include '@' and '.' and no ' ' and displays all invalids
	void printByDegreeProgram(DegreeProgram degreeProgram); // prints student's degree program - specified by enum

	~Roster();

};

#endif 
