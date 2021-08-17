#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <dos.h>
#include <vector>
#include <cmath>
using namespace std;
//class mainMenu;
void admin();
void us();
string i;
class editMenu
{
	protected:
		char loginfile[10]="login.txt";
		char productfile[16]="productlist.txt";
		string x;
public:
		editMenu()
		{
	
		}
	void set(string y)
	{
		x = y;
	}
	string get()
	{
		return x;
	}
	void delproduct();
	void addProduct();
	void history();
	
};
class mainMenu:public editMenu
{
	friend class customer;
public:

	void admin();
	void list_products();

	mainMenu(){}
	~mainMenu(){}

};

class customer
{
	vector < string > cart;
	mainMenu* obj;
public:
	void purchase();
	void debit();
	void credit();
	void cash();
	int bill;
	string name;
	long int contact;
	string db;
	long int ccv;
	string address;
	customer()
	{
		obj = new mainMenu;
		bill = 0;
	}
	~customer()
	{
		delete obj;
	}
	
};
void customer::purchase()
{
	int q;
	int a;
	int price;
	bool ok = 0;
	
	cout << "\t\t\t\t|----------------------------------------|" << endl;
	cout << "\t\t\t\t|                                        |" << endl;
	cout << "\t\t\t\t|             Welcome Customer!          |" << endl;
	cout << "\t\t\t\t|                                        |" << endl;
	cout << "\t\t\t\t|----------------------------------------|" << endl;

	cout << "" << endl;
	cout << "enter your name" << endl;
	cin >> name;
	cout << "20% discount on purchase over 100" << endl;

	string product;

	ifstream in;
	ifstream fin;
	
	
	
		cout << " " << endl;
		cout << "\t\t\tPURCHASE [1]" << endl;
		cout << "\t\t\tEXIT [2]" << endl;
		cin >> a;
		
		switch (a)
		{
		case 1:
		line2:obj->x = 1;
			in.open(obj->productfile);
			fin.open("price.txt");
			cout << "enter the product" << endl;
			cin >> product;
			while (getline(in, i) && fin>>price)
			{
				
				
				
				if (product == i)
				{
					cart.push_back(product);
					ok = 1;
					break;
					
				}
				
					
			}
			
			if (ok)
			{
				cout << "enter the quantity" << endl;
				cin >> q;
				in.seekg(0, ios::beg);
				bill += price * q;
				
				cout << "do you want to buy more? [3]" << endl;
				cin >> a;
				if (a == 3)
				{
					in.close();
					fin.close();
					goto line2;
				}

				else
				{

					cout << "total bill=" << bill << endl;

					if (bill >= 100)
					{
						
						bill = bill - bill * 0.2;
						cout << "Bill after discount is:" << bill << endl;
					}
					ofstream his;
					his.open("history.txt",ios::app);
					his << "customer name=" << name << endl;
					his << "items=\t" << endl;
					for (auto i = cart.begin(); i != cart.end(); ++i)
						his << *i << " " << endl;
					his << "Total bill=" << bill << endl;
					his.close();
					
				}
			}
			

		
		}
	
		in.close();
		fin.close();
		

		cout << "" << endl;
		cout << "\t\t\t\tHow would you like to pay" << endl;
		cout << "\t\t\t\t1 DEBIT CARD" << endl;
		cout << "\t\t\t\t2 EASY PAISA" << endl;
		cout << "\t\t\t\t3 CASH ON DELIVERY" << endl;
		int A;
		cin >> A;
		switch (A)
		{
		case 1:
			system("cls");
			debit();
			break;
		case 2:
			system("cls");
			credit();
			break;
		case 3:
			system("cls");
			cash();
			break;
		}
			


				


}
void customer::debit()
{
	cout << "\n\t\t\t\tEnter name:";
	cin >> name;
	cout << "\n\t\t\t\tEnter number:";
	cin >> contact;
line:
	cout << "\n\t\t\t\tEnter Debit card number(****-****-****-****):";
	cin >> db;
	int z = db.length();
	if (z > 19 || z < 19)
	{
		cout << "\n\t\t\t\tEnter again:";
		goto line;
	}
	cout << "\n\t\t\t\tEnter CVV Code:";
	cin >> ccv;
	cout << "\n\t\t\t\tPayment Successfull!";
	exit(0);
}
void customer::credit()
{
	cout << "\n\t\t\t\tEnter name:";
	cin >> name;
	cout << "\n\t\t\t\tEnter number:";
	cin >> contact;
line:
	cout << "\n\t\t\t\tEnter Credit card number(****-****-****-****):";
	cin >> db;
	int z = db.length();
	if (z > 19 || z < 19)
	{
		cout << "\n\t\t\t\tEnter again:";
		goto line;
	}
	cout << "\n\t\t\t\tEnter CVV Code:";
	cin >> ccv;
	cout << "\n\t\t\t\tPayment Successfull!";
	exit(0);
}
void customer::cash()
{

	cout << "\n\t\t\t\tEnter Fist Name:";
	cin >> name;
	cout << "\n\t\t\t\tEnter Last Name:";
	cin >> name;
	cout << "\n\t\t\t\tEnter number:";
	cin >> contact;
	cout << "\n\t\t\t\tEnter Address:";
	cin >> address;
	exit(0);
}
void mainMenu::admin()
{
	
	

	cout << "\t\t\t\t|----------------------------------------|" << endl;
	cout << "\t\t\t\t|                                        |" << endl;
	cout << "\t\t\t\t|             Welcome Admin!             |" << endl;
	cout << "\t\t\t\t|                                        |" << endl;
	cout << "\t\t\t\t|----------------------------------------|" << endl;


line:
	
		string un, pw;
		cout << "enter username:"; cin >> un;
		cout << "enter password:"; cin >> pw;

		ifstream file(loginfile, ios::in);
		if (!file)
		{
			cerr << "file does not exist" << endl;
		}

	

		string name, pass;
		getline(file, name);
		getline(file, pass);


		if (un == name && pw == pass)
		{
			system("cls");
			system("color A");
			cout << "login successfull" << endl;
			cout << "" << endl;
			cout << "Add an item to the product list               [1]" << endl;
			cout << "Delete an item from the list                  [2]" << endl;
			cout << "View customer history                         [3]" << endl;
			cout << "" << endl;
			int j;
			cin >> j;
			if (j == 1)
			{
				addProduct();
			}
			else if (j == 2)
			{
				delproduct();
			}
			else if (j == 3)
			{
				system("cls");
				history();
			}
			else
				exit(0);
		}
		else
		{
			system("color C");
			cout << "wrong credentials" << endl;
			goto line;
		}
	
	
		
	
}
void editMenu::addProduct()
{
	system("cls");
	cout << "enter the product you want to add" << endl;
	int procount=0;
	int temp;
	cin >> x;
	ifstream in;
	ofstream out;
	//in.open(productfile);
	if (!in)
	{
		cerr << "The file does not exist";
	}
	in.seekg(0, ios::beg);
	bool ok = 1;
line:ok = 1;
	in.open(productfile);

	//in.seekg(0, ios::beg);
		//ok = 1;
		while (!in.eof())
		{
			getline(in, i);
			//procount++;       //to count products
			if (i == x)
			{
			
				ok = 0;
			}
			
		}
		
		
		if (ok)
		{
			out.open(productfile, ios::app);
			out << x << endl;
			out.close();
			ofstream out1("price.txt", ios::app);
			cout << "enter product price" << endl;
			cin >> temp;
			out1 << temp << endl;
			cout << "product " << x << " added!" << endl;
			out1.close();
			//return;
		}
		if (!ok)
		{
			procount = 0;
			cout << "\nAlready exist\n";
			cin >> x;
			//in.seekg(0, ios::beg);
			in.close();
			goto line;
		}
		
		//cout << "number of products:" << procount - 2 << endl;
		
	
	
}
void editMenu::delproduct()
{
	system("cls");
	cout << "enter the product you want to delete" << endl;
	cout << "press (a) to exit" << endl;
	ifstream in;
	ifstream p;
	in.open(productfile);
	p.open("price.txt");
	int temp;
	ofstream out("temp.txt");
	ofstream temp1("tempprice.txt");
	cin >> x;
	while (1)
	{
		if (x == "a")
		{
			break;
		}
		while (getline(in, i) && p >> temp)
		{
			if (i != x )
			{
				out<<i<<endl;
			
				temp1 << temp << endl;
			}
		}
		temp1.close();
		in.close();
		out.close();
		in.open("temp.txt");
		out.open(productfile);
		while (getline(in, i))
		{
			
			if (i != x)
			{
				out<<i<<endl;
			}
		}
		p.close();
		in.close();
		out.close();
		remove("price.txt");
		int k=rename("tempprice.txt", "price.txt");
		return;
	}
}
void editMenu::history()
{
	string history;
	ifstream his;
	his.open("history.txt");
	while (!his.eof())
	{
		getline(his, history);
		cout << history << endl;
		cout << "" << endl;
		//cout << "*********************" << endl;
	}
	his.close();
}
void mainMenu::list_products()
{
	cout << "\t\t\t\t|----------------------------------------|" << endl;
	cout << "\t\t\t\t|                                        |" << endl;
	cout << "\t\t\t\t|             PRODUCT LIST               |" << endl;
	cout << "\t\t\t\t|                                        |" << endl;
	cout << "\t\t\t\t|----------------------------------------|" << endl;


	ifstream list(productfile);
	if (!list)
	{
		cerr << "file not found" << endl;
	}

	while (!list.eof())
	{
		getline(list, i);
		cout << i << endl;
	}
	
	mainMenu p;
	cout << "press 1 EXIT" << endl;
	int i;
	cin >> i;
	system("cls");
	if (i == 1)
		 return;
}

int main()
{
	mainMenu obj;
	customer obj1;
	void us();
	{
		system("cls");
		int count;
		for (count = 0; count < 1; count++)
		{
			Sleep(50);
			cout << "\n\n\n\n";
			Sleep(50);
			cout << "\t\t\t|----------------------------------------------------------------|" << endl;
			Sleep(50);
			cout << "\t\t\t|                       OOP PROJECT                              |" << endl;
			Sleep(50);
			cout << "\t\t\t|                                                                |" << endl;
			Sleep(50);
			cout << "\t\t\t|                Muhammad Mohtashim 20K-0462                     |" << endl;
			Sleep(50);
			cout << "\t\t\t|               Muhammad Ameer Ali Khan 20k-0498                 |" << endl;
			Sleep(50);
			cout << "\t\t\t|                                                                |" << endl;
			Sleep(50);
			cout << "\t\t\t|----------------------------------------------------------------|" << endl;
			Sleep(50);
			cout << "\n\n\n\n";
		}
	}

	while (1)
	{	
		system("color 70");
		cout << "\t\t\t\t\tWELCOME TO SALES MANAGEMENT SYSTEM" << endl;
		cout << " " << endl;
		cout << "IF YOU WANT TO ACCESS THE ADMIN PRESS 1" << endl;
		cout << "IF YOU WANT TO ACCESS THE PRODUCT LIST PRESS 2" << endl;
		cout << "IF YOU WANT TO PURCHASE ITEMS PRESS 3" << endl;
		cout << "press 4 to exit" << endl;

		int choice;
		cin >> choice;
		if (choice == 1)
			obj.admin();
		else if (choice == 2)
			obj.list_products();
		else if (choice == 3)
			obj1.purchase();
		else if(choice==4)
		{
			break;
		}

	}
	
}

