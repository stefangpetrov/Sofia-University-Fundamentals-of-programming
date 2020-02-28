#include <iostream>
using namespace std;

void professorXNumber(int n)
{
    
    if (n == 1)
    {
        cout << 1;
        return;
    }

    if (n < 1)
    {
        cout << endl;
    }

    professorXNumber(n - 1);
    cout << n;
    professorXNumber(n - 1);

}
int main()
{
    int n;
    cin >> n;
    professorXNumber(n);
}

