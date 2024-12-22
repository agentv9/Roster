#pragma once

#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

using namespace std;

class Roster {
	public:
		Roster();
		~Roster();
		void parseString(string data);
		void addStudent(string id, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeprogram);
		void removeStudent(string id);
		void printAllStudents();
		void printAverageDaysInCourse(string id);
		void printInvalidEmails();
		void printByDegreeProgram(Degree degree);
		Student* studentRoster[5];
	private:
		int totalStudents = 0;
		int nextid = 0;
};


#endif // !ROSTER_H