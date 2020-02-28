#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Input the highest degree of the polynom: ";
	cin >> n;

	const int MAX_SIZE = 1000;

	double arrCoeficients[MAX_SIZE];

	for (int i = 0; i <= n; i++)
	{
		double currentDegree;
		cin >> currentDegree;
		arrCoeficients[i] = currentDegree;

	}
	int derivative;
	cout << "Input which derivative you want to find: ";
	cin >> derivative;

	
	for (int i = 0; i < derivative; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arrCoeficients[j] = arrCoeficients[j] * (n - j);
		}
		arrCoeficients[n] = 0;
		n -= 1;
	}

	for (int i = 0; i < n; i++)
	{
		if (arrCoeficients[i] != 0)
		{
			cout << arrCoeficients[i] << "*X";
			if (n - i > 1)
			{
				cout << "^" << n - i;
			}
			if (i == n - 1 && arrCoeficients[n] == 0)
			{
				continue;
			}
			else
			{
				cout << " + ";
			}
			
		}
		
	}
	if (arrCoeficients[n] != 0)
	{
		cout << arrCoeficients[n];
	}

}

