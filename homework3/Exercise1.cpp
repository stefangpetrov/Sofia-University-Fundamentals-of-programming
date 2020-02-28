#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	while (n <= 0)
	{
		cout << "Input a number: ";
		cin >> n;
	}

	int currentNumber = 1;

	
	for (int i = 1; i <= n; i++)
	{
		if (i <= 6)
		{
			cout << i << " ";
			currentNumber++;
		}
		else
		{
			while (true)
			{
				bool hasOther = false;
				for (int j = 7; j <= currentNumber; j++)
				{
					if (j % 2 != 0 && j % 3 != 0 && j % 5 != 0 && currentNumber % j == 0)
					{
						hasOther = true;
						break;
					}
					else
					{
						continue;
					}
				}

				if (!hasOther)
				{
					cout << currentNumber << " ";
					currentNumber++;
					break;
				}
				currentNumber++;
			}
		}
		
	}
}
