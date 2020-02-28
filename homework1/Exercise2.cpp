#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Input a 9-digit number: ";
	cin >> number;

	number = number / 10;//first number is not needed so i skip it
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
	number = number / 100;//divide by 100 because second number is not needed and i skip it

	int cardVersion = number % 10;

	if (cardVersion >= 1 && cardVersion <= 9)
	{
		if (cardIdFirst != 0 || cardIdSecond != 0 || cardIdThird != 0 || cardIdFourth != 0 || cardIdFifth != 0)
		{
			switch (cardDegree)
			{
			case 0:
				cout << "{ " << '\"' << "card_version" << '\"' << ": " << cardVersion << ", " << '\"' << "owner_spec" << '\"' << ": " << '\"' << "Informatics" << '\"' << ", " << '\"' << "owner_id" << '\"' << ": " << cardId << " }";
				break;

			case 1:
				cout << "{ " << '\"' << "card_version" << '\"' << ": " << cardVersion << ", " << '\"' << "owner_spec" << '\"' << ": " << '\"' << "Computer Science" << '\"' << ", " << '\"' << "owner_id" << '\"' << ": " << cardId << " }";
				break;

			case 2:
				cout << "{ " << '\"' << "card_version" << '\"' << ": " << cardVersion << ", " << '\"' << "owner_spec" << '\"' << ": " << '\"' << "Informational Systems" << '\"' << ", " << '\"' << "owner_id" << '\"' << ": " << cardId << " }";
				break;

			case 3:
				cout << "{ " << '\"' << "card_version" << '\"' << ": " << cardVersion << ", " << '\"' << "owner_spec" << '\"' << ": " << '\"' << "Software Engineering" << '\"' << ", " << '\"' << "owner_id" << '\"' << ": " << cardId << " }";
				break;

			case 4:
				cout << "{ " << '\"' << "card_version" << '\"' << ": " << cardVersion << ", " << '\"' << "owner_spec" << '\"' << ": " << '\"' << "Informatics" << '\"' << ", " << '\"' << "owner_id" << '\"' << ": " << cardId << " }";
				break;

			case 5:
				cout << "{ " << '\"' << "card_version" << '\"' << ": " << cardVersion << ", " << '\"' << "owner_spec" << '\"' << ": " << '\"' << "Mathematics" << '\"' << ", " << '\"' << "owner_id" << '\"' << ": " << cardId << " }";
				break;

			case 6:
				cout << "{ " << '\"' << "card_version" << '\"' << ": " << cardVersion << ", " << '\"' << "owner_spec" << '\"' << ": " << '\"' << "Statistics" << '\"' << ", " << '\"' << "owner_id" << '\"' << ": " << cardId << " }";
				break;

			case 8:
				cout << "{ " << '\"' << "card_version" << '\"' << ": " << cardVersion << ", " << '\"' << "owner_spec" << '\"' << ": " << '\"' << "Mathematics and Informatics" << '\"' << ", " << '\"' << "owner_id" << '\"' << ": " << cardId << " }";
				break;

			default:
				cout << "Invalid card number";
				break;
			}
		}
		else
		{
			cout << "Invalid card number";
		}
	}
	else
	{
		cout << "Invalid card number";
	}
	return 0;
	

	


}