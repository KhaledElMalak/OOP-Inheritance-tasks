#include"Student.h"

#include<string>
#include<iostream>

using std::cout;
using std::endl;
using std::string;

Student::Student(const double gpa , const int ch , const std::string&n,const int a)
	:Person(n,a),GPA(gpa),completedHours(ch){}

bool Student::isGraduating()const { if (completedHours >= 167) return  true; else return  false; }
void Student::studyHours(const int hours) { completedHours += hours; }
void Student::displayStudentInfo()const {

	Person::displayBasicInfo();
	cout << "The GPA  : " << GPA << endl
		<< "The completed hours : " << completedHours << endl;
}

