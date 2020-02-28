#include <iostream>
using namespace std;

int main()
{
	short number;
	cout << "Input a number: ";
	cin >> number;

	if (number > 0 && number <= 3000)
	{
		while (number >= 1)
		{
			if (number - 1000 >= 0)
			{
				number -= 1000;
				cout << "M";
			}
			else if (number - 900 >= 0)
			{
				number -= 900;
				cout << "CM";
			}
			else if (number - 500 >= 0)
			{
				number -= 500;
				cout << "D";
			}
			else if (number - 400 >= 0)
			{
				number -= 400;
				cout << "CD";
			}
			else if (number - 100 >= 0)
			{
				number -= 100;
				cout << "C";
			}
			else if (number - 90 >= 0)
			{
				number -= 90;
				cout << "XC";
			}
			else if (number - 50 >= 0)
			{
				number -= 50;
				cout << "L";
			}
			else if (number - 40 >= 0)
			{
				number -= 40;
				cout << "XL";
			}
			else if (number - 10 >= 0)
			{
				number -= 10;
				cout << "X";
			}
			else if (number - 9 >= 0)
			{
				number -= 9;
				cout << "IX";
			}
			else if (number - 5 >= 0)
			{
				number -= 5;
				cout << "V";
			}
			else if (number - 4 >= 0)
			{
				number -= 4;
				cout << "IV";
			}
			else if (number - 1 >= 0)
			{
				number -= 1;
				cout << "I";
			}
		}
	}
	else
	{
		cout << "Invalid number!";
	}
	
	return 0;
}

