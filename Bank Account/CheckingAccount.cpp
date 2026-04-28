#include"BankAccount.h"
#include"CheckingAccount.h"
#include<iostream>
#include<string>
using namespace std;


CheckingAccount::CheckingAccount(double mf, string h, int n, double b) 
	: BankAccount(h, n, b) { Monthlyfee = mf; }


void CheckingAccount::calculateMonthlyUpdate() { Balance -= Monthlyfee; } // why it is not overrided ?

void CheckingAccount::display()const
{ BankAccount::display(); cout << "\n This account is a checking account " << endl; }


