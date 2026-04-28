#include"Person.h"

#include<string>
#include<iostream>

using std::cout;
using std::endl;
using std::string;


Person::Person(const string& n, const int a) :name(n) { setAge(a); }

void Person::setName(const string& n) { name = n; }
void Person::setAge(const int a) { age=(a>0?a:10); }

string Person::getName()const { return name; }
int Person::getAge()const { return age; }

void Person::displayBasicInfo()const {

	cout << "The Name : " << name << endl
		<< "The Age  : " << age << endl;
}

bool Person::isAdult()const { if (age >= 18)return true;else return false; }

