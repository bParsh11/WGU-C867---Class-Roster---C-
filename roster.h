
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include <array>
#include "degree.h"

using namespace std;



class Roster {

public:
	
	Student* classRosterArray[5];
	Roster(int classSize);
	string GetStudentID(int index);
	void parse(string studentData);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	int classSize;
	int ind;
	void add(string studentID, string firstName, string lastName, string email,
		int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	~Roster();
};

#endif

