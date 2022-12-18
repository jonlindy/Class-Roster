/*
* File: main.npp
* Author: Jon Lindemann
*
* Created on August 13th, 2022
*/
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main()
{
    cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS - C867\n"
        << "Programming Language: C++\n"
        << "StudentID: 009173156\n"
        << "Name: Jon Lindemann" << endl;
    cout << endl;

    const string studentData[] =    // student data string to parse
    {

        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jon,Lindemann,jlin216@wgu.edu,29,3,20,15,SOFTWARE"

    };

    const int numStudents = 5;  // set array size

    Roster roster;  // Creates roster and parses data;

    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying all students:" << endl;   // Display all Students in Roster table
    roster.printAll();
    cout << endl;

    cout << "Displaying students with INVALID email addresses:" << endl;  // Display invalid email addresses
    roster.printInvalidEmails();
    cout << endl;

    cout << "Displaying average days in course for each student: " << endl; // Display average days in course for each student
    for (int i = 0; i < numStudents; i++) roster.printAverageDaysInCourse(roster.classRosterArray[i]->getID());
    cout << endl;

    cout << "Displaying all students in SOFTWARE degree program:" << endl;
    roster.printByDegreeProgram(SOFTWARE);  // Displays students in SOFTWARE degree program
    cout << endl;

    roster.remove("A3");                    // Remove student A3 then display updated Roster
    cout << endl;

    roster.printAll();
    cout << endl;

    roster.remove("A3");                    // Attempt to remove student A3 - print Error message
    cout << endl;

    cout << "This concludes the program. Destructor will be called." << endl;
    return 0; // Destructor executes     
}