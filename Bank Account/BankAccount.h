#pragma once
#include<string>
class BankAccount {



protected :

	std::string Acoountholder;
	int accountNumber;
	double Balance;


public:

	BankAccount(std ::string h , int n, double b); // default argument .
	// no need for setters and getters for protected data members .
	// instead off , we need checkers .

	void deposite( const double ); // it is not used . why to define ?
	void withdrew( const double ); // it is not used . why to define ?
	void display() const ;
	void calculateMonthlyUpdate() const ;

};