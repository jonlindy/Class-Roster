/*
* File: degree.h
* Author: Jon Lindemann
*
* Created on August 13th, 2022
*/
#ifndef DEGREE_H
#define DEGREE_H
#include <string>

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE }; //created DegreeProgram data type
static const std::string DegreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" }; // for output

#endif