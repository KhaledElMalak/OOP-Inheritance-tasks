#pragma once
#include<string>

class Person {

public:

	Person(const std::string & = "Unknown", const int = 10);
	
	void setName(const std::string&);
	void setAge(const int);
	std::string getName()const;
	int getAge()const;

	void displayBasicInfo() const;
	bool isAdult()const;

protected :

	std::string name;
	int age;
};