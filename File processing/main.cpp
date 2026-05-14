#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Product {

public:

Product(int id = 0, const string& n = "") { ID = id; Name = n; }
virtual void display_info() const {
	cout << "\n\nThe ID : " << ID << endl
		<< "The Name : " << Name << endl;
}


int get_ID() const { return ID; }
string get_Name() const { return Name; }

void setID(int id) { ID = id; }
void setName(const string& n) { Name = n; }

private:

	int ID;
	string Name;
};

//----------------------

class Item:public Product {public:

Item(double p = 0.00, int q = 0, int id = 0, const string& n = "") :Product(id, n) { price = p; Quantity = q; }

void display_info() const override {

	Product::display_info();

	cout << "The Price : " << price << endl
		<< "The Quantity : " << Quantity << endl;
}

void increaseQuantity(int ammount) { Quantity += ammount; }

void setPrice(double p) { price = p; }
void setQuantity(int q) { Quantity = q; }
int getQuantity() const { return Quantity; }
	double getPrice() const { return price; }

private:

		double price;
		int Quantity;

};

//------------------------


class StoreList {

public:

StoreList()
{
	t = new Item[15];
	Count = 0;
}

void LoadItemsInfo()
{
	ifstream in;

	in.open("Items.txt");
	if (in.fail())
		cout << "Error ! File not found !" << endl;

	else {
		int id, q;
		double p;
		string n;

		while (in >> id >> n >> p >> q) {

			t[Count].setID(id);
			t[Count].setName(n);
			t[Count].setPrice(p);
			t[Count].setQuantity(q);
			cout << endl << endl;


			Count++;
		}

		cout << "Data Loaded Sucessfully ! " << endl;
	}
	in.close();
}

void ViewList()
{
	if (Count == 0)
		cout << "List is Emplty" << endl;

	for (int i = 0; i < Count; i++)
		t[i].display_info();
	cout << endl << "=======" << endl;
}


void RestockItemByID(int id, int ammount)
{
	for (int i = 0; i < Count; i++)
	{
		if (id == t[i].get_ID())
			t[i].increaseQuantity(ammount);
	}
}

bool CheckItemExists(int id)
{
	bool found = false;

	for (int i = 0; i < Count; i++)
		if (id == t[i].get_ID()) { found = true; break; }

	return found;
}

void saveInfoToFile()
{
	ofstream out;

	out.open("Items2.txt");

	for (int i = 0; i < Count; i++) {
		out << "ID : " << t[i].get_ID() << '\t'
			<< "The Name :" << t[i].get_Name() << '\t'
			<< "The Price : " << t[i].getPrice() << '\t'
			<< "The Quantity : " << t[i].getQuantity() << endl << endl;
	}

	out.close();
}

	   ~StoreList() { delete[]t; }

private:

	Item* t;
	int Count;

	};

		Item* t;
		int Count;
		int main() {

			StoreList SL;

			int choice;

			while (true)
			{
				cout << "\n\n==== Menu Driven ==== \n\n"
					<< "1.Load Data From File .\n"
					<< "2.View Items List .\n"
					<< "3.Restock By ID . \n "
					<< "4.Check if Item exists .\n"
					<< "5.save information to file .\n"
					<< "6.exit.\n\n"
					<< "Your Choice :";
				cin >> choice;


				switch (choice)
				{

				case 1: {
					SL.LoadItemsInfo();
					break;
				}
				case 2: {
					SL.ViewList();
					break;
				}
				case 3: {

					int id, ammount;

					cout << "The ID :";
					cin >> id;
					cout << "\nThe ammount : ";
					cin >> ammount;
					SL.RestockItemByID(id, ammount);
					break;
				}
				case 4:
				{
					int id;
					cout << "Enter the ID : ";
					cin >> id;

					if (SL.CheckItemExists(id))
						cout << "\nId is Found ! " << endl;
					else
						cout << "ID is not Found ! " << endl;

					break;

				}
				case 5: {

					SL.saveInfoToFile();

					break;
				}

				case 6:
					exit(0);

				default:

					cout << "Invalid Choice ! " << endl;
				}
			}
			return 0;
		}
