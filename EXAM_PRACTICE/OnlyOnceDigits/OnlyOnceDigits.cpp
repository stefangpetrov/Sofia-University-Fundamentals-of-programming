#include <iostream>
using namespace std;


int main()
{
    unsigned long num;
    cin >> num;

    while (num != 0)
    {
        unsigned long copy = num / 10;
        int digit = num % 10;

        while (copy != 0)
        {
            int copyDigit = copy % 10;
            if (copyDigit == digit)
            {
                cout << "False";
                return 0;
            }
            copy /= 10;
        }
        num /= 10;

    }

    cout << "True";

}
