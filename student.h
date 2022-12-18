/*
* File: student.h
* Author: Jon Lindemann
*
* Created on August 13th, 2022
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

class Student
{
public:
	const static int daysInCourseNum = 3;

private:				// create variables
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	DegreeProgram degreeProgram;

public:
	Student(); // Default constructor
	// Full constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	~Student();

	// Getters
	string getID();
	string getfirstName();
	string getlastName();
	string getEmail();
	int getAge();
	int getdays1();
	int getdays2();
	int getdays3();
	DegreeProgram getdegreeprogram();

	// Setters
	void setID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setAge(int age);
	void setdays1(int daysInCourse1);
	void setdays2(int daysInCourse2);
	void setdays3(int daysInCourse3);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader(); //static method (shared by all objects) - display column categories

	void print(); // displays the student info
};

#endif 