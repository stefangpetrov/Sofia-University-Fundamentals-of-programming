#include <iostream>
using namespace std;

bool recursiveDigitChecker(int n, int digit, int nCopy)
{
    nCopy = nCopy / 10;

    if (nCopy == 0)
    {
        n = n / 10;
        if (n == 0)
        {
            return true;
        }
        digit = n % 10;
        nCopy = n;
        return recursiveDigitChecker(n, digit, nCopy);
    }

    if (nCopy % 10 == digit)
    {
        return false;
    }

    return recursiveDigitChecker(n, digit, nCopy);
    
    
    
}

int main()
{
    int n;
    cin >> n;
    if (recursiveDigitChecker(n, n % 10, n))
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
}

