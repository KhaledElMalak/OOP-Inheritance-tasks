#pragma once
#include"BankAccount.h"
#include<string>


class CheckingAccount : public BankAccount {

public :

	CheckingAccount(double mf = 0.00, std::string h="Unknown", int n=0, double b=0.00);
	void calculateMonthlyUpdate();
	void display() const;

private :

	double Monthlyfee;

};
