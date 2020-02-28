#include <iostream>
using namespace std;


bool checkPrime(unsigned long n)
{

	bool isPrime = true;

	for (unsigned long i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
}

void goldbahTheory(unsigned long n)
{
	for (unsigned long i = 2; i < n; i++)
	{
		bool isPrimeI = checkPrime(i);
		if (isPrimeI)
		{
			for (unsigned long j = i; j < n; j++)
			{
				bool isPrimeJ = checkPrime(j);
				if (isPrimeJ)
				{
					if (i + j == n)
					{
						cout << "(" << i << ", " << j << ") ";
					}
				}
				else
				{
					continue;
				}
			}
		}
		else
		{
			continue;
		}
		
	}
}


int main()
{
	cout << "Input an even number greater than 2: ";
	unsigned long n;
	cin >> n;
	if (n % 2 != 0)
	{
		cout << "Are you joking with me, Euler? This number is not even!";
	}
	else if (n == 2)
	{
		cout << "Are you joking with me, Euler? I told you to try with a number greater than 2!";
	}
	else
	{
		goldbahTheory(n);
	}
	return 0;
}

