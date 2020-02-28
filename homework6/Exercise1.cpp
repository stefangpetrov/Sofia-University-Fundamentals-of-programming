#include <iostream>
using namespace std;

const short  MAX_SIZE = 100;
int rowMult(int arr[][MAX_SIZE], int m, int index)
{
	int mult = 1;
	for (int i = 0; i < m; i++)
	{
		mult *= arr[index][i];

	}
	return mult;
}
int colMult(int arr[][MAX_SIZE], int n, int index)
{
	int mult = 1;
	for (int i = 0; i < n; i++)
	{
		mult *= arr[i][index];

	}
	return mult;
}

int main()
{
	unsigned short n, m;
	do
	{
		cout << "Input n <= 100: ";
		cin >> n;
	} while (n > 100);
	do
	{
		cout << "Input m <= 100: ";
		cin >> m;
	} while (m > 100);

	int arr[MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	bool isEqual = false;
	for (int i = 0; i < n; i++)
	{
		int currentRowMult = rowMult(arr, m, i);
		for (int j = 0; j < m; j++)
		{
			int currentColMult = colMult(arr, n, j);
			if (currentRowMult == currentColMult)
			{
				isEqual = true;
				cout << i << ", " << j << endl;
			}
		}

	}

	if (!isEqual)
	{
		cout << "No match!";
	}
}

