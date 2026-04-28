#pragma once

#include"Person.h"

#include<string>


class Student :public Person {

public:

	Student(const double = 0.00, const int = 0, const std::string & = "Unknown", const int = 10);

	bool isGraduating()const;
	void studyHours(const int);
	void displayStudentInfo()const;

private:

	double GPA;
	int completedHours;
};
