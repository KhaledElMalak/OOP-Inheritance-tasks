#include"All.h"

#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

// Class Base : UserAccount implementation .

UserAccount::UserAccount(const string& UN , const long int id , const double b )
	:UserName(UN) , UserID(id) , Balance (b){ }

void UserAccount::display_Info()const {

	cout <<"\n\nThe User Name : " << UserName << endl
		 << "The User ID  : " << UserID << endl
		 << "The Balance  : " << Balance << endl;
}

bool UserAccount::makePayement(double ammount )
{
	if (ammount >= 0 && ammount <= Balance)
	{
		Balance -= ammount;
		return true;
	}

	else
		return false;
}

double UserAccount::updateBalance() { return Balance; }
long int UserAccount::get_ID() const { return UserID; }
double UserAccount::get_Balance() const { return Balance; }

UserAccount::~UserAccount(){}


//---------------------------------------------------------------------

// Class Derived 1 : StudentAccount implementation .




StudentAccount::StudentAccount(const double DR , const bool isF, const string& UN , const long int id , const double b )
	: UserAccount(UN , id , b ) , DiscountRate(DR) , isForeign (isF){ }


void StudentAccount::display_Info()const {
	UserAccount::display_Info();
	cout << "The Discount Rate : " << DiscountRate << endl
		<< "Is Foreign : " << isForeign << endl;
}

double StudentAccount::CalculateDiscount() { if (checkDiscount()) return DiscountRate * Balance; else return 0; }

bool StudentAccount::checkDiscount() const { if (DiscountRate > 0 && DiscountRate <= 0.3)return true;else return false; }

double StudentAccount::updateBalance()
{

	if (checkDiscount()) { Balance -= CalculateDiscount(); return Balance; }  

	else
		return Balance;
}



StudentAccount::~StudentAccount(){}


//----------------------------------------------------------------
// Class Derived 2 : BusinessAccount implementation.


BusinessAccount::BusinessAccount(const double TR , const double MSF,const string& UN, const long int id, const double b)
	:UserAccount(UN , id , b) , TaxRate(TR) , MonthlyServiceFee(MSF){ }

void BusinessAccount::display_Info() const
{
	UserAccount::display_Info();
	cout << "The Tax Rate : " << TaxRate << endl
		<< "The Monthly Service Fees : " << MonthlyServiceFee << endl;
}


double BusinessAccount::CalculateFees() const { return ((TaxRate + MonthlyServiceFee)/100) * Balance; }
double BusinessAccount::updateBalance() { Balance -= CalculateFees(); return Balance; }

BusinessAccount::~BusinessAccount(){}

