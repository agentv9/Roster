
#include <iostream>
#include "roster.h"

using namespace std;

Roster::Roster(){}
Roster::~Roster(){}

void Roster::parseString(string data) {
	
	string delimiter = ",";

	size_t pos = 0;
	string token;
	int i = 1;
	string id, name1, name2, emailAddress;
	int age, daysInCourse1, daysInCourse2, daysInCourse3;
	Degree degree;

	while ((pos = data.find(delimiter)) != string::npos) {
		token = data.substr(0, pos);
		
		if (i == 1) {
			id = token;
			i++;
		}else if (i == 2) {
			name1 = token;
			i++;
		}
		else if (i == 3) {
			name2 = token;
			i++;
		}
		else if (i == 4) {
			emailAddress = token;
			i++;
		}
		else if (i == 5) {
			age = stoi(token);
			i++;
		}
		else if (i == 6) {
			daysInCourse1 = stoi(token);
			i++;
		}
		else if (i == 7) {
			daysInCourse2 = stoi(token);
			i++;
		}
		else if (i == 8) {
			daysInCourse3 = stoi(token);
			i++;
		}
		data.erase(0, pos + delimiter.length());
	}

	if (data == "SECURITY") {
		degree = SECURITY;
	}else if (data == "NETWORK") {
		degree = NETWORK;
	}
	else {
		degree = SOFTWARE;
	}

	
	addStudent(id, name1, name2, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);

}

void Roster::addStudent(string id, string name1, string name2, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeprogram) {
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	studentRoster[nextid] = new Student(id, name1, name2, emailAddress, age, days, degreeprogram);
	nextid++;
	totalStudents++;
	return;
}

void Roster::removeStudent(string id) {
	bool located = false;
	
	for (int i = 0; i < totalStudents; i++) {
		if (studentRoster[i]->getID() == id) {
			delete studentRoster[i];
			located = true;
		
			for (int j = i; j < totalStudents - 1; j++) {
				studentRoster[j] = studentRoster[j + 1];
			}
			totalStudents--;
		}
	}

	if (located == false) {
		cout << "The student with the ID: " << id << " was not found." << endl;
	}

	return;
}

void Roster::printAllStudents() {
	for (int i = 0; i < totalStudents; i++) {
		studentRoster[i]->Print();
	}
	return;
}

void Roster::printAverageDaysInCourse(string id) {
	int totalDays = 0;
	int averageDays;

	for (int i = 0; i < totalStudents; i++) {
		if (studentRoster[i]->getID() == id) {
			totalDays = studentRoster[i]->getCourseDays()[0] + studentRoster[i]->getCourseDays()[1] + studentRoster[i]->getCourseDays()[2];
		}
	}

	averageDays = totalDays / 3;

	cout << "Student ID: " << id << ", Average days in course is: " << averageDays << endl;
	return;
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < totalStudents; i++) {
		string email = studentRoster[i]->getEmail();
		if (email.find(" ") != string::npos || email.find(".") == string::npos || email.find("@") == string::npos) {
			cout << email << " - Is invalid." << endl;
		}
	}
	return;
}

void Roster::printByDegreeProgram(Degree degree) {
	for (int i = 0; i < totalStudents; i++) {
		if (studentRoster[i]->getDegree() == degree) {
			studentRoster[i]->Print();
		}
	}
	return;
}