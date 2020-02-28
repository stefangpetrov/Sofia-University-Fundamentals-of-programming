#include <iostream>
#include <ctime>
using namespace std;

const int MAX_SIZE = 10;

bool isNotAlreadyBusy(char arr[][MAX_SIZE], unsigned short N, unsigned short X, unsigned short Y)
{
	if (arr[X - 1][Y - 1] == 'X' || arr[X - 1][Y - 1] == 'O')
	{
		return false;
	}
	return true;
}

bool winByRow(char arr[][MAX_SIZE], unsigned short N)
{
	
	for (int i = 0; i < N; i++)
	{
		bool allXRow = true;
		bool allORow = true;
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != 'X')
			{
				allXRow = false;
			}
			if (arr[i][j] != 'O')
			{
				allORow = false;
			}
		}
		if (allXRow || allORow)
		{
			return true;
		}
	}
	return false;
}

bool winByCol(char arr[][MAX_SIZE], unsigned short N)
{

	for (int i = 0; i < N; i++)
	{
		bool allXCol = true;
		bool allOCol = true;
		for (int j = 0; j < N; j++)
		{
			if (arr[j][i] != 'X')
			{
				allXCol = false;
			}
			if (arr[j][i] != 'O')
			{
				allOCol = false;
			}
		}
		if (allXCol || allOCol)
		{
			return true;
		}
	}
	return false;
}

bool winByDiagonal(char arr[][MAX_SIZE], unsigned short N)
{
	bool mainDiagonalX = true;
	bool mainDiagonalO = true;

	bool otherDiagonalX = true;
	bool otherDiagonalO = true;

	for (int i = 0; i < N; i++)
	{
		if (arr[i][i] != 'X')
		{
			mainDiagonalX = false;
		}
		if (arr[i][i] != 'O')
		{
			mainDiagonalO = false;
		}
		if (arr[N - 1 - i][i] != 'X')
		{
			otherDiagonalX = false;
		}
		if (arr[N - 1 - i][i] != 'O')
		{
			otherDiagonalO = false;
		}
	}
	if (mainDiagonalX || mainDiagonalO || otherDiagonalX || otherDiagonalO)
	{
		return true;
	}
	return false;
}

bool hasWonChess(char arr[][MAX_SIZE], unsigned short N)
{
	bool equalCol = winByCol(arr, N);
	bool equalRow = winByRow(arr, N);
	bool equalDiagonals = winByDiagonal(arr, N);

	if (equalCol || equalRow || equalDiagonals)
	{
		return true;
	}
	return false;
}

void printArr(char arr[][MAX_SIZE], unsigned short N)
{
	for (int i = 0; i < N; i++)
	{
		unsigned short currentX, currentY;
		for (int j = 0; j < N; j++)
		{
			cout << "[" << arr[i][j] << "] "; 
		}
		cout << endl;
	}
}

int main()
{
	srand(time(NULL));

	unsigned short gameMode;
	do
	{
		cout << "Choose game mode(1 - PvP, 2 - PvC, 3 - CvC) : ";
		cin >> gameMode;
	} while (gameMode > 3 || gameMode < 1);


	unsigned short N;
	do
	{
		cout << "Enter grid size: ";
		cin >> N;
	} while (N < 3 || N>9);

	char arr[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = ' ';
		}
	}

	bool hasWon = false;
	bool firstPlayerTurn = true;
	if (gameMode == 1)
	{
		
		for (int i = 0; i < N; i++)
		{
			unsigned short currentX, currentY;
			for (int j = 0; j < N; j++)
			{
				if (firstPlayerTurn)
				{
					cout << "It's first player's turn: " << endl;
				}
				else
				{
					cout << "It's second player's turn: " << endl;
				}
				bool isAvailable;
				do
				{
					cin >> currentX;
					cin >> currentY;
					isAvailable = isNotAlreadyBusy(arr, N, currentX, currentY);
				} while (currentX > N || currentX < 1 || currentY > N || currentY < 1 || !isAvailable);

				if (firstPlayerTurn)
				{
					firstPlayerTurn = false;
					arr[currentX - 1][currentY - 1] = 'X';
				}
				else
				{
					firstPlayerTurn = true;
					arr[currentX - 1][currentY - 1] = 'O';
				}

				printArr(arr, N);

				hasWon = hasWonChess(arr, N);
				if (hasWon)
				{
					if (firstPlayerTurn)//tuk player 2 pecheli zashtoto toggle-a shte e smenil na player 1
					{
						cout << "player 2 has won";
					}
					else
					{
						cout << "player 1 has won";
					}
					break;
				}

			}
			if (hasWon)
			{
				break;
			}
		}
	}
	else if (gameMode == 2)
	{
		for (int i = 0; i < N; i++)
		{
			unsigned short currentX, currentY;
			for (int j = 0; j < N; j++)
			{
				bool isAvailable;

				if (firstPlayerTurn)
				{
					cout << "It's first player's turn: " << endl;
					firstPlayerTurn = false;
					
					do
					{
						cin >> currentX;
						cin >> currentY;
						isAvailable = isNotAlreadyBusy(arr, N, currentX, currentY);
					} while (currentX > N || currentX < 1 || currentY > N || currentY < 1 || !isAvailable);
					arr[currentX - 1][currentY - 1] = 'X';
				}
				else
				{
					cout << "It's second player's turn: " << endl;
					firstPlayerTurn = true;
					do
					{
						currentX = rand() % N + 1;
						currentY = rand() % N + 1;
						cout << currentX << " " << currentY << endl;
						isAvailable = isNotAlreadyBusy(arr, N, currentX, currentY);
					} while (!isAvailable);
					arr[currentX - 1][currentY - 1] = 'O';
				}

				printArr(arr, N);

				hasWon = hasWonChess(arr, N);
				if (hasWon)
				{
					if (firstPlayerTurn)//tuk player 2 pecheli zashtoto toggle-a shte e smenil na player 1
					{
						cout << "player 2 has won";
					}
					else
					{
						cout << "player 1 has won";
					}
					break;
				}

			}
			if (hasWon)
			{
				break;
			}
		}
	}
	else
	{
	for (int i = 0; i < N; i++)
	{
		unsigned short currentX, currentY;
		for (int j = 0; j < N; j++)
		{
			bool isAvailable;
			if (firstPlayerTurn)
			{
				cout << "It's first player's turn: " << endl;
			}
			else
			{
				cout << "It's second player's turn: " << endl;
			}

			do
			{
				currentX = rand() % N + 1;
				currentY = rand() % N + 1;
				
				isAvailable = isNotAlreadyBusy(arr, N, currentX, currentY);
			} while (!isAvailable);
			cout << currentX << " " << currentY << endl;

			if (firstPlayerTurn)
			{
				firstPlayerTurn = false;
				arr[currentX - 1][currentY - 1] = 'X';
			}
			else
			{
				firstPlayerTurn = true;
				arr[currentX - 1][currentY - 1] = 'O';
			}

			printArr(arr, N);

			hasWon = hasWonChess(arr, N);
			if (hasWon)
			{
				if (firstPlayerTurn)//tuk player 2 pecheli zashtoto toggle-a shte e smenil na player 1
				{
					cout << "player 2 has won";
				}
				else
				{
					cout << "player 1 has won";
				}
				break;
			}

		}
		if (hasWon)
		{
			break;
		}
	}
	}
	if (!hasWon)
	{
		cout << "No one wins and there are no more free blocks. Play another game :).";
	}
	
}

