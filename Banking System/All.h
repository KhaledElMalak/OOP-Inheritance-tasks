#pragma once

#include<string>


// Class Base : UserAccount header. 

class UserAccount {

public:

	UserAccount(const std::string& UN = "", const long int id = 1111, const double b = 0.00);

	virtual void display_Info()const;

	virtual bool makePayement(double);

	virtual double updateBalance();

	 long int get_ID() const;
	 double get_Balance() const;

	virtual  ~UserAccount();

protected:

	std::string UserName;
	long int UserID;
	double Balance;
};

//--------------------------------------------------

// Class Derived 1 : StudentAccount header.


class StudentAccount :public UserAccount {


public:

	StudentAccount(const double DR = 0.00, const bool isF = true, const std::string& UN = "", const long int id = 1111, const double b = 0.00);

	virtual void display_Info()const override; 

	virtual double CalculateDiscount();

	bool checkDiscount() const ;

	double updateBalance() override;

	

	virtual ~StudentAccount();

private:

	double DiscountRate;
	bool isForeign;
};


//---------------------------------------------------

// Class Derived 2 : BusinessAccount header.


class BusinessAccount :public UserAccount {

public:

	BusinessAccount(const double TR = 0.00, const double MSF = 0.00, const std::string& UN = "", const long int id = 1111, const double b = 0.00);

	void display_Info() const override;

	virtual double CalculateFees() const;

	double updateBalance() override;

	

	virtual ~BusinessAccount();
private:

	double TaxRate;
	double MonthlyServiceFee;
};

