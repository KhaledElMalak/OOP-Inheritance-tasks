#include"Teacher.h"

#include<string>
#include<iostream>

using std::cout;
using std::endl;
using std::string;

Teacher ::Teacher(const double sal , const string & sub  , const int YearsExp , const string &n, const int a)
	:Person(n,a),salary(sal),subject(sub),yearsOfExperience(YearsExp){}

double Teacher::calculateBonus()const { if (yearsOfExperience > 5) return 300; else return 150; }
void Teacher::increaseSalary(const double ammount) { salary += ammount; }
bool Teacher::isSeniorTeacher()const { if (yearsOfExperience >= 10)return true; else return  false; }
void Teacher::displayTeacherInfo()const {

	Person::displayBasicInfo();
	cout << "The Salary   : " << salary << endl
		 << "The subject  : " << subject << endl
		 << "The Bonus    : " << calculateBonus() << endl;
}

