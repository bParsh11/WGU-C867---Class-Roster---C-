#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

//default constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse[0] = 0;
	this->daysInCourse[1] = 0;
	this->daysInCourse[2] = 0;
	this->degreeProgram;
}
//parameter constructor

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}

//setters

void Student::setID(string sID) {
	this->studentID = sID;

	return;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;


}

void Student::setLastName(string lastName) {
	this->lastName = lastName;

	
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;

}

void Student::setAge(int studentAge) {
	this->age = studentAge;

	
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	for (int i = 0; i < 3; i++)
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;


	
}



void Student::setDegreeProgram(DegreeProgram degreeprogram) {
	this->degreeProgram = degreeprogram;

	
}

//getters

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysInCourse() {
	return daysInCourse;
}


DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

//print - in case you're bored

void Student::printID() {
	cout << studentID;

	return;
}

void Student::printFirstName() {
	cout << firstName << endl;

	return;
}

void Student::printLastName() {
	cout << lastName << endl;

	return;
}

void Student::printEmailAddress() {
	cout << emailAddress << endl;

	return;
}

void Student::printAge() {
	cout << age << endl;

	return;
}

void Student::printDaysToComp() {
	cout << daysInCourse[0] << " " << daysInCourse[1] << " " << daysInCourse[2] << endl;

	return;
}

void Student::printDegreeProgram() {
	string degreeString;
	if (degreeProgram == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	
	cout << degreeString << endl;

	return;
}

//print all

void Student::print() {
	string degreeString;
	if (degreeProgram == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else {
		degreeString = "ERROR";
	}

	cout << studentID
		<< "   First Name: " << getFirstName()
		<< "   Last Name: " << getLastName()
		<< "   Age: " << getAge() << "  "
		<< "Days in courses: {" << getDaysInCourse()[0] << " " << getDaysInCourse()[1] << " " << getDaysInCourse()[2] << "} Degree Program: " << degreeString << " "<< endl;

	return;
}