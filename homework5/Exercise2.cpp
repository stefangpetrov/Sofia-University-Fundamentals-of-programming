#include <iostream>
#include <ctime>
using namespace std;

const int MAX_SIZE = 10000;
bool isPrime(short n)
{
	bool isPrime = true;
	for (int i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	if (n == 1 || n == 0)
	{
		return false;
	}
	if (isPrime)
	{
		return true;
	}
	return false;
}

void bestStartingPosition(int track[MAX_SIZE], short trackLength)
{
	short bestStartIndex = 0;
	short bestStartCount = 0;
	short consecutiveZeros = 0;


	for (int i = 0; i < trackLength; i++)
	{
		short currentBestStartIndex = i;
		short currentBestStartCount = 0;
		if (track[i] == 1)
		{
			currentBestStartCount++;
			for (int j = i + 1; j < trackLength; j++)
			{
				if (track[j] == 1)
				{
					currentBestStartCount++;
					consecutiveZeros = 0;
					i++;
				}
				else
				{
					if (consecutiveZeros < 4 && consecutiveZeros + 1 != 4)
					{
						consecutiveZeros++;
						currentBestStartCount++;
						i++;
					}
					else
					{
						consecutiveZeros = 0;
						currentBestStartCount -= 3;
						i++;
						break;
					}

				}

			}
		}
		else
		{
			continue;
		}
		if (currentBestStartCount > bestStartCount)
		{
			bestStartCount = currentBestStartCount;
			bestStartIndex = currentBestStartIndex;
		}

		
	}

	cout << "Best   starting   position   is " << bestStartIndex << " and   the   run   length   is " << bestStartCount << " steps" << endl;
}

void longestPlatform(int track[MAX_SIZE], short trackLength)
{
	short largestPlatform = 0;
	short largestPlatformIndex = 0;


	for (int i = 0; i < trackLength; i++)
	{
		short currentLargestPlatform = 0;
		short currentLargestPlatformIndex = i;
		for (int j = i; j < trackLength; j++)
		{
			if (track[j] == 1)
			{
				currentLargestPlatform++;

				i++;
			}
			else
			{
				break;
			}

		}
		if (currentLargestPlatform > largestPlatform)
		{
			largestPlatform = currentLargestPlatform;
			largestPlatformIndex = currentLargestPlatformIndex;
		}
		
	}



	cout << "Longest platform   starts   from   position " << largestPlatformIndex << " and   has   length   of " << largestPlatform << " steps." << endl;

}

void primePlatforms(int track[MAX_SIZE], short trackLength)
{
	short primeCount = 0;
	short primeArr[MAX_SIZE];
	short primeArrIndex = 0;

	for (int i = 0; i < trackLength; i++)
	{
		short currentPlatform = 0;
		for (int j = i; j < trackLength; j++)
		{
			if (track[j] == 1)
			{
				currentPlatform++;

				i++;
			}
			else
			{
				break;
			}

		}
		if (isPrime(currentPlatform))
		{
			primeCount++;
			primeArr[primeArrIndex] = currentPlatform;
			primeArrIndex++;
		}
	}

	cout << "There   are " << primeCount << "  prime-length   platforms.   Their   lengths:   ";
	for (int j = 0; j < primeArrIndex; j++)
	{
		cout << primeArr[j] << " ";

	}
	cout << endl;
}

void newPlatforms(int track[MAX_SIZE], short trackLength)
{
	short newPlatformsCount = 0;
	short newPlatformsLength = 0;
	for (int i = 0; i < trackLength; i++)
	{

		short consecutiveZeros = 0;
		for (int j = i; j < trackLength; j++)
		{
			if (track[j] == 0)
			{
				consecutiveZeros++;

				i++;
			}
			else
			{
				break;
			}

		}
		if (consecutiveZeros > 3)
		{
			newPlatformsCount++;
			newPlatformsLength += (consecutiveZeros - 3);
		}

	}

	cout << "Mario   needs " << newPlatformsCount << " new   platforms   with   total   length " << newPlatformsLength << ".";
}
int main()
{
	short trackLength;
	cin >> trackLength;
	
	srand(time(NULL)); 
	
	
	int track[MAX_SIZE] = { 1, 0, 1, 1, 1, 1, 0, 0, 0, 0 };


	if (trackLength > 0 && trackLength < MAX_SIZE)
	{
		
		for (int i = 0; i < trackLength; i++)
		{
			cin >> track[i];
		}
	}
	else if (trackLength == 0)
	{
		
		trackLength = 10;
		for (int i = 0; i < 10; i++)
		{
			cout << track[i] << " ";
		}
	}
	else
	{
		trackLength = (rand() % 91) ;//направих го от 10 до 100 че иначе не знам как щяхте да го проверявате до 10000 :)
		cout << trackLength << endl;

		for (int i = 0; i < trackLength; i++)
		{
			track[i] = rand() % 2;
			cout << track[i]<<" ";
		}
	}

	
	bestStartingPosition(track, trackLength);
	longestPlatform(track, trackLength);
	primePlatforms(track, trackLength);
	newPlatforms(track, trackLength);
}
