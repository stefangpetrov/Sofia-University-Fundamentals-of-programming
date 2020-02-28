
#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Input a 9-digit number: ";
	cin >> number;

	int numberLast = number % 10;
	number = number / 10;

	int cardId = number % 100000;

	int cardIdFirst = number % 10;
	number = number / 10;

	int cardIdSecond = number % 10;
	number = number / 10;

	int cardIdThird = number % 10;
	number = number / 10;

	int cardIdFourth = number % 10;
	number = number / 10;

	int cardIdFifth = number % 10;
	number = number / 10;

	int cardDegree = number % 10;
	number = number / 10;

	int numberSecond = number % 10;
	number = number / 10;

	int cardVersion = number % 10;
	number = number / 10;

	bool isLegit = true;
	bool isMale = false;
	bool hasDarkHair = false;
	bool hasDarkEyes = false;

	
	int result;
	
	

	if (number != 0)
	{
		isLegit = false;
		cout << "Invalid card number";
	}
	else if (cardVersion >= 1 && cardVersion <= 9)
	{
		if (cardIdFirst != 0 || cardIdSecond != 0 || cardIdThird != 0 || cardIdFourth != 0 || cardIdFifth != 0)
		{
			if (numberSecond >= 0 && numberSecond <= 7)
			{
				int mask = 1;
				mask = mask << 2;
				if (mask & numberSecond)
				{
					hasDarkEyes = true;
					
				}
				mask = mask >> 1;
				if (mask & numberSecond)
				{
					hasDarkHair = true;
					
				}
				mask = mask >> 1;
				if (mask & numberSecond)
				{
					isMale = true;

				}
				
			}
			else
			{
				isLegit = false;
				cout << "Imitative";
			}

			if (isLegit)
			{
				int sumOdd = cardVersion + cardDegree + cardIdFourth + cardIdSecond + numberLast;
				int sumEven = numberSecond + cardIdFifth + cardIdThird + cardIdFirst;
				int multiplySums = sumOdd * sumEven;

				if (hasDarkHair && hasDarkEyes)
				{
					result = multiplySums | 0xCAFE;
				}
				else if (!hasDarkEyes && !hasDarkHair)
				{
					result = multiplySums | 0xBAB;
				}
				else
				{
					result = multiplySums | 0xC001;
				}
				
				if (isMale)
				{
					result = result ^ 0xC0DE;
				}
				else
				{
					result = result ^ 0xFACE;
				}

				int mask = 15;//000000.....1111 
				result = result & mask;

				if (result > 10)
				{
					result = abs(result) % 10;
				}

				if (result != numberLast)
				{
					isLegit = false;
					cout << "Imitative";
				}
			}

		}
		else
		{
			cout << "Invalid card number";
			isLegit = false;
		}
	}
	else
	{
		cout << "Invalid card number";
		isLegit = false;
	}
	if (isLegit)
	{
		cout << "Authentic";
	}


	return 0;





}