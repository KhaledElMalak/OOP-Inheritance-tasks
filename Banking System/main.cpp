#include"All.h"

#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void UpdateCounter(int& counter) { counter++; }

int main() {

	UserAccount* arr[50];

	int counter = 0;
	int choice;

	while (true) {

		cout << "\n\n===== Main Menu ===== \n\n"
			<< "1.Add User Account .\n"
			<< "2.Add Student Account .\n"
			<< "3.Add Business Account .\n"
			<< "4.Display All Accounts Information .\n"
			<< "5.Make Payment by UserID .\n"
			<< "6.Show Account with highest Balance . \n"
			<< "7.Exit .\n\n"
			<< " Your choice Please : ";

		cin >> choice;

		switch (choice) {

		case 1:
		{
			string n;
			long int id;
			double b;


			cout << "The User Name : \n";
			cin >> n;
			cout << "The UserID : \n";
			cin >> id;
			cout << "The Balance : \n";
			cin >> b;


			arr[counter] = new UserAccount(n, id, b);

			UpdateCounter(counter);

			break;
		}

		case 2:
		{

			string n;
			long int id;
			double b, DR;
			bool isF;



			cout << "The User Name : \n";
			cin >> n;
			cout << "The UserID : \n";
			cin >> id;
			cout << "The Balance : \n";
			cin >> b;
			cout << "The Discount Rate : \n";
			cin >> DR;
			cout << "Is Foreign ? answer with 1 or 0 : \n";
			cin >> isF;


			arr[counter] = new StudentAccount(DR, isF, n, id, b);

			UpdateCounter(counter);

			break;
		}

		case 3:
		{

			string n;
			long int id;
			double b, TR, MSF;


			cout << "The User Name : \n";
			cin >> n;
			cout << "The UserID : \n";
			cin >> id;
			cout << "The Balance : \n";
			cin >> b;
			cout << "The Tax Rate : \n";
			cin >> TR;
			cout << "The Monthly Service Fees : \n";
			cin >> MSF;



			arr[counter] = new BusinessAccount(TR, MSF, n, id, b);

			UpdateCounter(counter);

			break;

		}
		case 4:

		{

			for (int i = 0;i < counter; i++)
			{
				cout << "The " << i + 1 << " Account info \n";
				arr[i]->display_Info();
			}

			break;
		}


		case 5:
		{
			long int id;
			double ammount;

			cout << "The UserID please : ";
			cin >> id;

			for (int i = 0; i < counter; i++)
			{
				if (id == arr[i]->get_ID())
				{
					cout << "User found . \n The ammount of payment : ";
					cin >> ammount;
					arr[i]->makePayement(ammount);
					cout << " Payment Successful ! \n";
				}

				else { cout << " No User ID found ! \n"; }
			}

			break;
		}

		case 6:

		{
			int max = 0;
			for (int i = 1; i < counter; i++)
			{
				if (arr[max]->get_Balance() < arr[i]->get_Balance()) { max = i; }
			}
			cout << " It is the " << max + 1 << "Account with " << arr[max]->get_Balance() << endl;
			break;
		}

		case 7:
		{ exit(0); }

		defalut:
			cout<<" Choice is wrong . Try again please \n";

		}
		}
		
	
	return 0;
}