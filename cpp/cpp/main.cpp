// shat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "student.h"
#include "roster.h"

int main()
{
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jordan,Killinger,jkill48@wgu.edu,17,25,35,42,SOFTWARE"
    };

    Roster roster;

    for (int i = 0; i < 5; i++) {
        roster.parseString(studentData[i]);
    }

    cout << "Display all students:" << endl;

    roster.printAllStudents();

    cout << endl;

    cout << "Display invalid emails:" << endl;
    roster.printInvalidEmails();
    cout << endl;

    for (int i = 0; i < 5; i++) {
        roster.printAverageDaysInCourse(roster.studentRoster[i]->getID());
    }
    cout << endl;

    cout << "Showing students from degree program: SOFTWARE" << endl;

   roster.printByDegreeProgram(SOFTWARE);

    cout << endl;

    cout << "Removing A3" << endl;
    roster.removeStudent("A3");
    roster.printAllStudents();
    cout << endl;

    cout << "Removing A3 again";
    roster.removeStudent("A3");

    cout << "Program finished" << endl;

    return 0;
}