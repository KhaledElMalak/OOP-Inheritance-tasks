#include"Student.h"
#include"Teacher.h"

#include<iostream>
#include<string>

using std::cout;
using std::endl;

int main()
{
	Teacher T(1000, "Mathematics", 10, "Khaled", 30);
	Student S(85.55 , 50 , "Ali" , 21 );

	S.displayStudentInfo();
	cout << endl << endl;
	T.displayTeacherInfo();


	return 0;
}