#include <iostream>
using namespace std;

long min(unsigned long a, unsigned long b)
{
	if (a <= b)
	{
		return a;
	}
	return b;
}
long max(unsigned long a, unsigned long b)
{
	if (a >= b)
	{
		return a;
	}
	return b;
}

void getSumInOtherBases()//2.1
{
	long number;
	cin >> number;
	int base;
	cin >> base;
	int result = 0;
	while (number != 0)
	{
		result += number % base;
		number = number / base;
	}
	cout << result;
}


void biggestCommonDivider()//2.2
{
	unsigned long firstNum, secondNum;
	cin >> firstNum >> secondNum;

	unsigned long minimum = min(firstNum, secondNum);
	unsigned long commonDivider = 1;
	for (long i = 1; i <= minimum; i++)
	{
		if (firstNum % i == 0 && secondNum % i == 0)
		{
			commonDivider = i;
		}
	}
	cout << commonDivider;
}

double power(double a, unsigned long b)//2.3
{
	double multiplier = a;
	for (int i = 1; i < b; i++)
	{
		a = a * multiplier;
	}
	return a;
}

bool isGreen(long number)//2.4
{
	long result = 0;
	long clone = number;
	while (number != 0)
	{
		short current = number % 10;
		result += power(current, 3);
		number /= 10;
	}
	if (result == clone)
	{
		return true;
	}
	return false;
}

long sumGreens(long m, long n)//2.5
{
	long minimum = min(m, n);
	long maximum = max(m, n);

	long sumGreens = 0;
	for (long i = minimum; i <= maximum; i++)
	{
		if (isGreen(i))
		{
			sumGreens += i;
		}
	}

	return sumGreens;
}

bool isRed(long number)//2.6
{
	int sumDigits = 0;
	long clone = number;
	while (number != 0)
	{
		sumDigits += number % 10;
		number /= 10;
	}
	for (long i = 1; i <= clone; i++)
	{
		if (sumDigits * i == clone)
		{
			return true;
		}
	}
	return false;
}
long sumReds(long m, long n)//2.5
{
	long minimum = min(m, n);
	long maximum = max(m, n);

	long sumReds = 0;
	for (long i = minimum; i <= maximum; i++)
	{
		if (isRed(i))
		{
			sumReds += i;
		}
	}

	return sumReds;
}

void sumDifference(long m, long n)//2.7
{
	long sumGreenNums = sumGreens(m, n);
	long sumRedNums = sumReds(m, n);

	cout << abs(sumGreenNums - sumRedNums);
}

long factorial(long number)
{
	long result = 1;
	for (long i = number; i >= 1; i--)
	{
		result *= i;
	}
	return result;
}

double sumFromGivenFormula(double x, long firstN)//2.8
{
	double result = 1;
	for (long i = 1; i < firstN; i++)
	{
		if (i % 2 != 0)
		{
			double poweredX = power(x, 2 * i);
			result -= (poweredX / factorial(2 * i));
		}
		else
		{
			double poweredX = power(x, 2 * i);
			result += (poweredX / factorial(2 * i));
		}
	}
	return result;
}

double findSinX(double x, long firstN)//2.9.1
{
	double cos = sumFromGivenFormula(x, firstN);
	cos = cos * cos;
	double poweredSinx = 1 - cos;
	if (x < 0)
	{
		return -sqrt(poweredSinx);
	}
	return sqrt(poweredSinx);
}

double findTgX(double x, long firstN)//2.9.2
{
	double cosX = sumFromGivenFormula(x, firstN);
	double sinX = findSinX(x, firstN);
	return sinX / cosX;
}

double findCoTgX(double x, long firstN)//2.9.3
{
	double cosX = sumFromGivenFormula(x, firstN);
	double sinX = findSinX(x, firstN);
	return cosX / sinX;
}
int main()
{
	
	//getSumInOtherBases();//2.1

	//biggestCommonDivider();//2.2

	/*
	long a;
	unsigned long b;
	cin >> a >> b;
	cout<<power(a, b);//2.3
	*/


	/*
	//2.4
	long greenNumber;
	cin >> greenNumber;
	if (isGreen(greenNumber))
	{
		cout << greenNumber << " is green";
	}
	else
	{
		cout << greenNumber << " is not green";
	}
	*/

	/*
	//2.5
	long m, n;
	cin >> m >> n;
	cout << sumGreens(m, n);
	*/

	/*
	//2.6
	long redNumber;
	cin >> redNumber;
	if (isRed(redNumber))
	{
		cout << redNumber << " is red";
	}
	else
	{
		cout << redNumber << " is not red";
	}
	*/

	/*
	//2.7
	long M, N;
	cin >> M >> N;
	sumDifference(M, N);
	*/

	
	double x;
	long firstN;
	cin >> x >> firstN;
	cout << sumFromGivenFormula(x, firstN) << endl;//2.8
	
	
	cout << findSinX(x, firstN) << endl;//2.9.1
	cout << findTgX(x, firstN) << endl;//2.9.2
	cout << findTgX(x, firstN) << endl;//2.9.3
	

}

