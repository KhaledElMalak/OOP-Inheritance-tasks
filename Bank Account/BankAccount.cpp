#include"BankAccount.h"
#include<string>
#include<iostream>
using namespace std;



BankAccount::BankAccount(string h , int n  , double b )
{
	Acoountholder = h;
	accountNumber = n;
	Balance = b;
}

void BankAccount::deposite( const double ammount) // to add money to the balance . 
{
	Balance += ammount;
}

void BankAccount::withdrew(const double ammount) // to subtract from balance .
{
	if (ammount <= Balance)
		Balance -= ammount;

	else
		cout << " Balance is not enough ." << endl;
}

void BankAccount::display() const // to show account details ( holder  , number , balance ) .
{
	cout << " The Account Holder  : \n" << Acoountholder << endl
		 << " The Account Number  : \n" << accountNumber << endl
		 << " The Account balance : \n" << Balance << endl;

}

void BankAccount::calculateMonthlyUpdate() const { cout << " No Monthly Update defined . " << endl; } // creepy someway ?!





