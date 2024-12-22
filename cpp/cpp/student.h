#pragma once
#ifndef STUDENT_H 
#define STUDENT_H
#include <string>
#include "degree.h"

using namespace std;

class Student {
	public:

		Student(string id, string firstname, string lastname, string email, int age, int coursedays[], Degree degree);
		~Student();
		void Print();

		//Getters

		string getID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		Degree getDegree();
		int* getCourseDays();
		
		string getDegreeName(Degree degree) { return EnumStrings[degree]; }

		//Setters
		void setID(string id);
		void setFirstName(string name);
		void setLastName(string name);
		void setEmail(string email);
		void setAge(int age);
		void setDegree(Degree degree);
		void setCourseDays(int coursedays[3]);

	private:
		string ID;
		string First_Name;
		string Last_Name;
		string Email;
		int Age;
		Degree Student_Degree;
		int CourseDays[3];
		string EnumStrings[3] = { "SECURITY", "NETWORK", "SOFTWARE" };

};

#endif