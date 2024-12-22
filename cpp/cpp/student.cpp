#include "student.h"
#include "degree.h"
#include <iostream>


using namespace std;

Student::Student(string id, string firstname, string lastname, string email, int age, int coursedays[], Degree degree) {
	setID(id);
	setFirstName(firstname);
	setLastName(lastname);
	setEmail(email);
	setAge(age);
	setDegree(degree);
	setCourseDays(coursedays);
};

Student::~Student() {};

//Getters
string Student::getID() { return ID; }

string Student::getFirstName() { return First_Name; }

string Student::getLastName() { return Last_Name; }

string Student::getEmail() { return Email; }

int Student::getAge() { return Age; }

Degree Student::getDegree() { return Student_Degree; }

int* Student::getCourseDays() { return CourseDays; }

//Setters
void Student::setID(string id) { ID = id; return;}

void Student::setFirstName(string name) { First_Name = name; return;}

void Student::setLastName(string name) { Last_Name = name; return;}

void Student::setEmail(string email) { Email = email; return;}

void Student::setAge(int age) { Age = age; return;}

void Student::setDegree(Degree degree) { Student_Degree = degree; return;}

void Student::setCourseDays(int coursedays[3]) {

	for (int i = 0; i < 3; i++) {
		CourseDays[i] = coursedays[i];
	}

	return; 
}

void Student::Print() {
	cout << getID() << "\t\t";
	cout << getFirstName() << "\t\t";
	cout << getLastName() << "       \t";
	cout << getEmail() << "     \t";
	cout << getAge() << "\t\t";
	cout << "{" << getCourseDays()[0] << "," << getCourseDays()[1] << "," << getCourseDays()[2] << "}" << "\t\t";
	cout << getDegreeName(getDegree()) << endl;

	return;
}