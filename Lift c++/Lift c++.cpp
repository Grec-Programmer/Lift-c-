#include <iostream>
#include <string>

using namespace std;

class Lift
{
	int etag[10] = {0,1,2,3,4,5,6,7,8,9};
	int min = etag[1];
	int max = etag[9];
	int button_etag = etag[1];
	string a = "on";
public:
	Lift()
	{
		cout << "Лифт включен и находится на " << button_etag << " этаже"<<endl;
	}
	void ON_Lift()
	{
		cout << "Чтобы выключить лифт введите off, чтобы включить введите on";
		cin >> a;
	}
	void Vizov_lift()
	{
		while (a != "on")
		{
		cout << "Лифт выключен!\n Ехать никуда не будем!!!" << endl;
		ON_Lift();
		}
			for (int i = min; i < max; i++)
			{
				if (button_etag == i)
				{
					cout << "Лифт уже тут!!!" << endl;
					cout << "На какой этаж едем? ";
					Etag();
					cout << "Вы приезхали на " << button_etag << " этаж" << endl;
					break;
				}
				else
				{
					cout << "Лифт едет к вам!!!"<< endl;
					i = button_etag;
					cout << "Лифт уже тут!!!" << endl;
					cout << "На какой этаж едем? ";
					Etag();
					cout << "Вы приехали на " << button_etag << " этаж" << endl;
					break;
				}
			}
	}
	void Etag()
	{
			cout << "Введите номер этажа ";
			cin >> button_etag;
			Stoper();
	}
	bool button(string a)
	{
		if (a == "on")
			return true;
		else return false;
	}
	void Work_Lift()
	{
		if (button(a))
			cout << "Лифт включен!"<<endl;
		else while(a != "on")
		{
			cout << "Лифт выключен!\n Ехать никуда не будем!!!"<<endl;
			ON_Lift();
		}
	}
	void Stoper()
	{
		while (button_etag < min or button_etag > max)
		{
			cout << "Лифт не поедет на этот этаж!!!"<<endl;
			cout << "Введите номер этажа ";
			cin >> button_etag;
		}
	}
	void Etag_Now()
	{
		for (int i = min; i < max; i++)
		{
			if (button_etag == i)
			{
				cout << "Лифт сейчас на " << i << " этаже" << endl;
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Lift Vasiliy;
	int menu;
	do
	{
		cout << "[1]Вызвать лифт\n[2]Узнать этаж, на котором стоит лифт\n[3]Состояние лифта\n[4]Выключить/Включить\n[5]Выход"<<endl;
		cin >> menu;
		if (menu == 1)
		{
			Vasiliy.Etag();
			Vasiliy.Vizov_lift();
		}
		if (menu == 2)
		{
			Vasiliy.Etag_Now();
		}
		if (menu == 3)
		{
			Vasiliy.Work_Lift();
		}
		if (menu == 4)
			Vasiliy.ON_Lift();
	} while (menu != 5);
}
