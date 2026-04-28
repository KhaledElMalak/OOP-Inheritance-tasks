#pragma once
#include"BankAccount.h"
#include<string>


class SavingsAccount : public BankAccount {

private :

	double InterestRate;

public : 

	SavingsAccount( double ist = 0.00  , std::string h = "Unknwon", int n = 0, double b =0.00);

	void calculateMonthlyUpdate(); // override .
	void display() const ; // override ;
};