#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <array>
#include <string>
using namespace std;


//class constructor
Roster::Roster(int classSize) {
	this->classSize = classSize;
	this->ind = 0;
	for (int i = 0; i < classSize; i++) {
		this->classRosterArray[i] = new Student;
	}
	return;
}

string Roster::GetStudentID(int index) {

	string sID = classRosterArray[index]->getStudentID();
	return sID;
}


//parse method
void Roster::parse(string studentDataTable) {

	string sID, firstname, lastname, emailAddress;
	int studentAge, daysInCourse1, daysInCourse2, daysInCourse3;

	if (ind < classSize) {

		classRosterArray[ind] = new Student();

		int i = studentDataTable.find(",");
		sID = studentDataTable.substr(0, i);
		classRosterArray[ind]->setID(sID);

		int d = i + 1;
		i = studentDataTable.find(",", d);
		firstname = studentDataTable.substr(d, i - d);
		classRosterArray[ind]->setFirstName(firstname);

		d = i + 1;
		i = studentDataTable.find(",", d);
		lastname = studentDataTable.substr(d, i - d);
		classRosterArray[ind]->setLastName(lastname);

		d = i + 1;
		i = studentDataTable.find(",", d);
		emailAddress = studentDataTable.substr(d, i - d);
		classRosterArray[ind]->setEmailAddress(emailAddress);

		d = i + 1;
		i = studentDataTable.find(",", d);
		studentAge = stoi(studentDataTable.substr(d, i - d));
		classRosterArray[ind]->setAge(studentAge);

		d = i + 1;
		i = studentDataTable.find(",", d);
		daysInCourse1 = stoi(studentDataTable.substr(d, i - d));

		d = i + 1;
		i = studentDataTable.find(",", d);
		daysInCourse2 = stoi(studentDataTable.substr(d, i - d));

		d = i + 1;
		i = studentDataTable.find(",", d);
		daysInCourse3 = stoi(studentDataTable.substr(d, i - d));
		classRosterArray[ind]->setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);

		d = i + 1;
		i = studentDataTable.find(",", d);
		string type = studentDataTable.substr(d, i - d);
		if (type == "SOFTWARE") {
			classRosterArray[ind]->setDegreeProgram(SOFTWARE);
		}
		else if (type == "SECURITY") {
			classRosterArray[ind]->setDegreeProgram(SECURITY);
		}
		else if (type == "NETWORK") {
			classRosterArray[ind]->setDegreeProgram(NETWORK);
		}
		else {
			cout << "Degree not found" << endl;
		}
		ind++;
	}
	return;
}
//add Student Object to roster method

void Roster::add(string studentID, string firstName, string lastName, string email, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[classSize] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
};




//remove student from roster
void Roster::remove(string id) {

	bool foundStudent = false;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (id == classRosterArray[i]->getStudentID()) {
			classRosterArray[i] = nullptr;
			foundStudent = true;
			break;
		}
	}
	if (foundStudent == false) {
		cout << "Error: Student " << id << " Not Found." << endl;
	}
	else if (foundStudent == true) {
		cout << "Student " << id << " removed." << endl;
	}
	return;
}
//print all
void Roster::printAll() {
	cout << "All current students: " << endl;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] == nullptr)
		{
			continue;
		}
		else {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
	return;
}
//print average number of days
void Roster::printAverageDaysInCourse(string id) {
	for (int i = 0; i < classSize; i++) {
		if (id == classRosterArray[i]->getStudentID()) {
				cout << id << "" << "'s average days in course:" <<
					((classRosterArray[i]->getDaysInCourse()[0] +
						classRosterArray[i]->getDaysInCourse()[1] +
						classRosterArray[i]->getDaysInCourse()[2]) / 3)
					<< endl;

		}
	}
	return;
}
//print invalid emails

void Roster::printInvalidEmails() {
	for (int i = 0; i < classSize; ++i) {
		string emailAd = classRosterArray[i]->getEmailAddress();
		if ((emailAd.find('@') == string::npos) ||  (emailAd.find(' ') != string::npos) || (emailAd.find('.') == string::npos)) {
			cout<<"Invalid Email Addresses:" << classRosterArray[i]->getStudentID() << " email address " << emailAd << " is invalid." << endl;
		}
	}
	cout << endl;
	return;
}



//print students with specified degree program
void Roster::printByDegreeProgram(DegreeProgram degPro) {
	string degreeString;
	if (degPro == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degPro == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degPro == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else {
		degreeString = "ERROR";
	}
	cout << "Students with degree program: " << degreeString << endl;
	int numStudents = 0;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degPro) {
			classRosterArray[i]->print();
			++numStudents;
		}
	}
	if (numStudents == 0) {
		cout << "ERROR" << endl;
	}
	return;
}
//destructor
Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	};

	
}