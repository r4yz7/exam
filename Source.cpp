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
		cout << "������� ����� �� ������� ������ ���������: ";
		cin >> m;
		cash += m;
	}
	void print()
	{
		cout << "��� ������: " << cash << "$" << endl;
	}
	void spend()
	{
		cout << "������� ��������� �������: ";
		int sp;
		string pok="pok.txt";
		cin >> sp;
		if (cash-sp<0)
		{
			cout << "�������������� ����� �� �������\n";
		}
		else
		{
			cout << "������� �����: ";
			cin >> month;
			cout << "������� ����: ";
			cin >> day;
			cash -= sp;
			cout << "������� ���������!\n";
			fstream fout;
			fout.open(pok, ios::app);
			if (!fout.is_open())
			{
				exit(0);
			}
			else
			{
				fout << "����: " << day << "." <<  month << "\t" << "�������: " << sp << endl;
			}
			fout.close();
		}
		
	}
	int pincode()
	{
		int p;
		cout << "������� ������: ";
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
		cout << "������� ����� �� ������� ������ ���������: ";
		cin >> m;
		cash += m;
	}
	void spend()
	{
		cout << "������� ��������� �������: ";
		int sp;
		string pok = "cred.txt";
		cin >> sp;
		
			cout << "������� �����: ";
			cin >> month;
			cout << "������� ����: ";
			cin >> day;
			cash -= sp;
			cout << "������� ���������!\n";
			fstream fout;
			fout.open(pok, ios::app);
			if (!fout.is_open())
			{
				exit(0);
			}
			else
			{
				fout << "����: " << day << "." <<  month << "\t" << "�������: " << sp << endl;
			}
			fout.close();
		
	}
	int pincode()
	{
		int p;
		cout << "������� ������: ";
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
			cout << "��� ������: " << cash << "$" << endl;
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
		cout << "�������� �����:\n";
		cout << "0-exit\n1-������� �����\n2-���������\n";
		cout << "�����: ";
		cin >> menu;
		switch (menu)
		{case 1:
		{
			int ch;
			do
			{
				system("cls");
				deb.print();
				cout << "1-��������� ����\n2-������� �������\n3-������� ���������� � ��������\n";
				cout << "�����: ";
				cin >> ch;
				switch (ch)
				{case 1:
				{
					if (deb.pincode()==0)
					{
						cout << "�� ���������� ������!";
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
						cout << "������������ ������\n";
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
				cout << "1-��������� ����\n2-������� �������\n3-������� ���������� � ��������\n";
				cout << "�����: ";
				cin >> ch;
				switch (ch)
				{
				case 1:
				{
					if (c.pincode() == 0)
					{
						cout << "�� ���������� ������!";
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
						cout << "������������ ������\n";
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