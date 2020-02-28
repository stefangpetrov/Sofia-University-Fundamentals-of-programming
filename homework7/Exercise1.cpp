#include <iostream>
#include<ctime>
#include<cmath>

using namespace std;

int main()
{
    srand(time(NULL));
    unsigned long long key = rand() * pow(2, rand() % 49) + 1;//%49 ?????? ?? ??????? ??????? ????? 0-48, ??? ???? %48 ???? ?? ??????? 48, ???? ? ?? ???? ????? :)
    cout << key << endl;
    
    unsigned long long first = 0;

    unsigned long long result;
    int countStandart = 0;
    unsigned long long biggest = 9223372036854775807;

    
    while (first <= biggest)
    {
        countStandart++;
        result = first + ((biggest - first) / 2);
        cout << "result -> " << result << endl;

        if (result == key)
        {
            break;
           
        }
        else if(result < key)
        {
            first = result + 1;
            cout << "The current result is less than the key"<<endl;
            
        }
        else
        {
            cout << "The current result is more than the key" << endl;
            biggest = result - 1;
        }
  
        
    }
    
    cout << result << " " << countStandart << " times were needed so the key could be matched with the standard algoritm" << endl << endl << endl;
    

    unsigned long countRandomized = 0;
    first = 0;
    biggest = 9223372036854775807;
    


    while (first <= biggest)//izvinqvam se za tova izvrashtenie no drugo ne izmislih za tezi random tyrseniq
    {
        countRandomized++;
        if (biggest / 2 > first)//pyrvo namalqme kraq kolkoto mojem
        {
            do
            {
                result = biggest / (rand() % 32767 + 1);
            } while (first > result);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 17) * 32767 > first)//posle premestvame nachaloto s golemi chisla, taka che da ne stane
        {                                              // overlap i nachaloto da stane poveche ot kraq, ne che ima nqkva seriozna logika 
            do
            {
                result = first + rand() * pow(10, 17);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 16) * 32767 > first)
        {                                               
            do
            {
                result = first + rand() * pow(10, 16);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 15) * 32767 > first)
        {                                              
            do
            {
                result = first + rand() * pow(10, 15);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 15) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10, 14);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 13) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10, 13);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10,12) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10,12);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 11) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10, 11);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 10) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10, 10);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 9) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10, 9);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 8) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10, 8);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 7) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10, 7);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 6) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10, 6);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 6) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10, 6);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 5) * 32767 > first)
        {
            do
            {
                result = first + rand() * pow(10, 5);
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 4) * 32767 > first)
        {
        do
        {
            result = first + rand() * pow(10, 4);
        } while (result < first || result > biggest);
        cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 3) * 32767 > first)
        {
        do
        {
            result = first + rand() * pow(10, 3);
        } while (result < first || result > biggest);
        cout << "result -> " << result << endl;
        }
        else if (biggest - pow(10, 2) * 32767 > first)
        {
        do
        {
            result = first + rand() * pow(10, 2);
        } while (result < first || result > biggest);
        cout << "result -> " << result << endl;
        }
        else if (biggest - 10 * 32767 > first)
        {
        do
        {
            result = first + rand() * 10;
        } while (result < first || result > biggest);
        cout << "result -> " << result << endl;
        }
        else
        {
            do
            {
                result = first + rand();
            } while (result < first || result > biggest);
            cout << "result -> " << result << endl;
        }
        

        if (result == key)
        {
            break;

        }
        else if (result < key)
        {
            first = result + 1;
            cout << "The current result is less than the key" << endl;

        }
        else
        {
            cout << "The current result is more than the key" << endl;
            biggest = result - 1;
        }


    }
    cout << result << " " << countRandomized << " times were needed so the key could be matched with the randomized algoritm";

}

