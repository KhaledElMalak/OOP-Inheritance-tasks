#pragma once
#include"Person.h"

#include<string>

class Teacher :public Person {

public:

	Teacher(const double = 0.00, const std::string & sub = "Unknown", const int = 0, const std::string & n= "Unknown", const int = 10);

	double calculateBonus() const;
	void increaseSalary(const double);
	bool isSeniorTeacher()const;
	void displayTeacherInfo()const;

private:

	double salary;
	std::string subject;
	int yearsOfExperience;
};