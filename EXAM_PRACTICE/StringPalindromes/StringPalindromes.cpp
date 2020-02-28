#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    char a[100];
    cin.getline(a, 100);
    
    int len = strlen(a);
    int countSkipable = 0;;
    

    for (size_t i = 0; i < len; i++)
    {
        if (a[i] == '?' || a[i] == ' ' || a[i] == '.'
            || a[i] == '!' || a[i] == ',')
        {
            countSkipable++;
        }
    }

    int realLen = len - countSkipable;

    int indBegin = 0;
    int indEnd = len - 1;
    for (size_t i = 0; i < realLen/2; i++)
    {
        if (a[indBegin] == '?' || a[indBegin] == ' ' || a[indBegin] == '.'
            || a[indBegin] == '!' || a[indBegin] == ',')
        {
            i--;
            indBegin++;
            continue;
        }
        if (a[indEnd] == '?' || a[indEnd] == ' ' || a[indEnd] == '.'
            || a[indEnd] == '!' || a[indEnd] == ',')
        {
            i--;
            indEnd--;
            continue;
        }

        if (a[indBegin] != a[indEnd])
        {
            cout << "False";
            return 0;
        }
        indBegin++;
        indEnd--;
    }

    cout << "True";
    return 0;
}

