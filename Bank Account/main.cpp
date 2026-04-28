#include"CheckingAccount.h"
#include"SavingsAccount.h"

#include<iostream>
#include<string>

using namespace std;


int main() {


	SavingsAccount sv1 (0.2 , "Adam",55250,2000);
	CheckingAccount ch1 (50 , "Ali",55251,4000);


	sv1.calculateMonthlyUpdate();
	ch1.calculateMonthlyUpdate();

	sv1.display();
	cout <<endl<< endl;
	ch1.display();

	return 0;
}