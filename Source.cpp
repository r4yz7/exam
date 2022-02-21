#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
class Debet
{
	int pin=1111;//password 1111
	double cash;
	int day;
	int month;
public:
	Debet()
	{
		this->cash = 0;
		this->day = day;
		this->month = month;
	}
	Debet(double cash)
	{
		this->cash = cash;
	}
	void addMoney()
	{
		double m;
		cout << "Введите сумму на которую хотите пополнить: ";
		cin >> m;
		cash += m;
	}
	void print()
	{
		cout << "Ваш баланс: " << cash << "$" << endl;
	}
	void spend()
	{
		cout << "Введите стоимость покупки: ";
		int sp;
		string pok="pok.txt";
		cin >> sp;
		if (cash-sp<0)
		{
			cout << "Недостататочно денег на балансе\n";
		}
		else
		{
			cout << "Введите месяц: ";
			cin >> month;
			cout << "Введите день: ";
			cin >> day;
			cash -= sp;
			cout << "Покупка совершена!\n";
			fstream fout;
			fout.open(pok, ios::app);
			if (!fout.is_open())
			{
				exit(0);
			}
			else
			{
				fout << "Дата: " << day << "." <<  month << "\t" << "Покупки: " << sp << endl;
			}
			fout.close();
		}
		
	}
	int pincode()
	{
		int p;
		cout << "Введите пинкод: ";
		cin >> p;
		if (p==pin)
		{
			p = 1;
		}
		else
		{
			p = 0;
		}
		return p;
	}
	void show()
	{
		ifstream fin;
		fin.open("pok.txt");
		if (!fin.is_open())
		{
			cout << "Error\n";
			exit(0);
		}
		else
		{
			while (!fin.eof())
			{
				string str;
				getline(fin, str);
				cout << str << endl;
			}
		}
	}
	
	
};
class Credit
{
	int pin = 1111;
	double cash;
	int day;
	int month;
public:
	Credit()
	{
		this->cash = 0;
	}
	void addMoney()
	{
		double m;
		cout << "Введите сумму на которую хотите пополнить: ";
		cin >> m;
		cash += m;
	}
	void spend()
	{
		cout << "Введите стоимость покупки: ";
		int sp;
		string pok = "cred.txt";
		cin >> sp;
		
			cout << "Введите месяц: ";
			cin >> month;
			cout << "Введите день: ";
			cin >> day;
			cash -= sp;
			cout << "Покупка совершена!\n";
			fstream fout;
			fout.open(pok, ios::app);
			if (!fout.is_open())
			{
				exit(0);
			}
			else
			{
				fout << "Дата: " << day << "." <<  month << "\t" << "Покупки: " << sp << endl;
			}
			fout.close();
		
	}
	int pincode()
	{
		int p;
		cout << "Введите пинкод: ";
		cin >> p;
		if (p == pin)
		{
			p = 1;
		}
		else
		{
			p = 0;
		}
		return p;
	}
		void print()
		{
			cout << "Ваш баланс: " << cash << "$" << endl;
		}
		void show()
		{
			ifstream fin;
			fin.open("cred.txt");
			if (!fin.is_open())
			{
				cout << "Error\n";
				exit(0);
			}
			else
			{
				while (!fin.eof())
				{
					string str;
					getline(fin, str);
					cout << str << endl;
				}
			}
		}

};
void main()
{
	setlocale(LC_ALL, "RUS");
	int menu;
	Debet deb;
	Credit c;
	do
	{
		system("cls");
		cout << "Выберите карту:\n";
		cout << "0-exit\n1-Обычная карта\n2-кредитная\n";
		cout << "Выбор: ";
		cin >> menu;
		switch (menu)
		{case 1:
		{
			int ch;
			do
			{
				system("cls");
				deb.print();
				cout << "1-Пополнить счёт\n2-сделать покупку\n3-вывести информацию о покупках\n";
				cout << "Выбор: ";
				cin >> ch;
				switch (ch)
				{case 1:
				{
					if (deb.pincode()==0)
					{
						cout << "Не правильный пароль!";
					}
					else
					{
						deb.addMoney();
					}
					
				}break;
				case 2:
				{

					if (deb.pincode()==0)
					{
						cout << "Неправильный пароль\n";
					}
					else
					{
						deb.spend();
					}

				}break;
				case 3:
				{
					deb.show();
				}break;
				default:
					break;
				}
				system("pause");
			} while (ch!=0);

		}break;
		case 2:
		{
			int ch;
			do
			{
				system("cls");
				c.print();
				cout << "1-Пополнить счёт\n2-сделать покупку\n3-вывести информацию о покупках\n";
				cout << "Выбор: ";
				cin >> ch;
				switch (ch)
				{
				case 1:
				{
					if (c.pincode() == 0)
					{
						cout << "Не правильный пароль!";
					}
					else
					{
						c.addMoney();
					}

				}break;
				case 2:
				{

					if (c.pincode() == 0)
					{
						cout << "Неправильный пароль\n";
					}
					else
					{
						c.spend();
					}

				}break;
				case 3:
				{
					c.show();
				}break;
				default:
					break;
				}
				system("pause");
			} while (ch != 0);
		}break;
		case 0:
		{
			exit(0);
		}break;
		default:
			break;
		}
		system("pause");
	} while (menu!=0);
}