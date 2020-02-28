#include <iostream>
#include<bitset>
using namespace std;

int main()
{
	short n = 0;
	while (n < 1 || n > 31)
	{
		cout << "Input n between 1 and 31: ";
		cin >> n;
	}

	short currentNumberInOrder = 0;
	int id;

	cin >> id;
	currentNumberInOrder = id;
	cout << "1 ";

	int onesCount = 1;
	int resultBits = 1;

	short leftSideZeros = 0;
	short rightSideZeros = 0;
	
	for (int i = 0; i < n - 1; i++)
	{
		//bitset<32> numberAsBinary(resultBits);
		//cout << numberAsBinary << endl;
		cin >> id;
		if (id >= currentNumberInOrder)
		{
			currentNumberInOrder = id;
			cout << "1 ";
			onesCount++;
			resultBits = resultBits << 1;
			resultBits = resultBits | 1;
		}
		else
		{
			cout << "0 ";
			resultBits = resultBits << 1;
		}
			
	
	}
	//bitset<32> numberAsBinary(resultBits);
	//cout << numberAsBinary << endl;

	if (onesCount % 2 != 0)
	{
		
		onesCount = onesCount / 2 + 1;
		
	}
	else
	{
		onesCount = onesCount / 2;
	}

	int mask = 1;
	mask = mask << n - 1;
	//bitset<32> numberAsBinar(mask);
	//cout << numberAsBinar << endl;

	short positionForRightZeros = 1;
	for (int i = 1; i <= onesCount; i++)
	{
		while (true)
		{
			positionForRightZeros++;
			int resultFromBitOperation = mask & resultBits;

			if (resultFromBitOperation != 0)
			{
				mask = mask >> 1;
				break;
			}
			else
			{
				leftSideZeros++;
			}

			mask = mask >> 1;
		}
	}
	for (int i = positionForRightZeros; i <= n; i++)
	{
		int resultFromBitOperation = mask & resultBits;

		if (resultFromBitOperation != 0)
		{
			mask = mask >> 1;
			continue;
		}
		else
		{
			rightSideZeros++;
		}

		mask = mask >> 1;
	}

	
	if (leftSideZeros > rightSideZeros)
	{
		cout << "Left side: " << leftSideZeros;
	}
	else if (leftSideZeros < rightSideZeros)
	{
		cout << "Right side: " << rightSideZeros;
	}
	else
	{
		cout << "Both sides: " << rightSideZeros;
	}
}
