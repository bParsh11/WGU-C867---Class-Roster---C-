#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <array>
using namespace std;

int main()
{
 
    cout <<"Course Title: C867 - SCRIPTING AND PROGRAMMING - APPLICATIONS"<< endl;
    cout << "Programming Language Used: C++ " << endl;
    cout << "Student ID: 001435403" << endl;
    cout << "Student Name: Brendon Parshall" << endl;
    cout << "   " << endl;
    cout << "   " << endl;


  
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Brendon,Parshall,bparsh2@wgu.edu,23,30,60,90,SOFTWARE"
    };

    
    Roster * classRoster = new Roster(5);
    for (int i = 0; i < 5; i++) {
        classRoster->parse(studentData[i]);
    };

 
    //functions
    classRoster->printAll();
    cout << endl;
    cout << endl;
  
    classRoster->printInvalidEmails();

    for (int i = 0; i < 5; i++) {

        classRoster->printAverageDaysInCourse(classRoster->GetStudentID(i));
    }
    cout << endl;
    cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;
    cout << endl;
    
    classRoster->remove("A3");
    cout << endl;
    cout << endl;
  
    classRoster->printAll();
    cout << endl;
    cout << endl;
  
    classRoster->remove("A3");
    cout << endl;

    

   //destructor
    classRoster->~Roster();
    delete classRoster;

}
