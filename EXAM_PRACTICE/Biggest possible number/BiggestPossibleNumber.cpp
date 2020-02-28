#include <iostream>
using namespace std;

int power(int x, int y)
{
    int n = x;
    for (size_t i = 0; i < y - 1; i++)
    {
        n *= x;
    }
    return n;
}
int resize(int num, int current, int& count)
{
    int countWhere = 0;
    int copy = num;
    while (num != 0)
    {
        int digit = copy % 10;
        if (digit == current)
        {
            int ostatuk;
            if (countWhere == 0)
            {
                ostatuk = num % 10;
                num /= 10;
                return num;
            }
            else
            {
                ostatuk = num % power(10, countWhere + 1);
                num = num / power(10, countWhere + 1);
                
            }

            if (num == 0)
            {
                num = ostatuk % power(10, count - 1);
                
                return num;
            }
            else
            {
                int copy2 = num;
                int numCount = 0;
                while (copy2 != 0)
                {
                    copy2 /= 10;
                    numCount++;
                }
                ostatuk = ostatuk % power(10,countWhere);
                num = num * power(10, count - numCount - 1);
                num += ostatuk;
                count--;
                return num;
            }
        }
        copy /= 10;
        countWhere++;
    }
}
int main()
{
    unsigned num;
    cin >> num;
    
    unsigned copy = num;
    int count = 0;
    while (copy != 0)
    {
        copy /= 10;
        count++;
    }
    
    int currentCount = count;
    copy = num;

    while(num != 0)
    {
        copy = num;
        int currentBig = copy % 10;
        copy /= 10;
        while (copy != 0)
        {
            int temp = copy % 10;

            if (temp > currentBig)
            {
                currentBig = temp;
            }
            copy /= 10;
        }
        num = resize(num, currentBig, count);
        cout << currentBig;
    }
    
    
}
