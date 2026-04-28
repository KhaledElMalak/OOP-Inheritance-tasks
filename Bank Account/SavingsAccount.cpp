
#include"SavingsAccount.h"
#include<string>
#include<iostream>
using namespace std;

SavingsAccount::SavingsAccount(double ist , string h, int n, double b)
	: BankAccount(h ,n ,b)
{
	InterestRate = ist;
}
void SavingsAccount::calculateMonthlyUpdate() { Balance += InterestRate; } // mathematically right for interest ?...
void SavingsAccount::display() const
{ BankAccount::display(); cout << "\n This account is a savings account ." << endl; } // what is Type of Account ?!

