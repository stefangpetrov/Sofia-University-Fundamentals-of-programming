#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;



const char* exclamations[] = { "SHOK", "MALEE", "KO STAA", "AUUUU", "MAIKO MILA" };
const char* objectSubject[] = { "baba", "dqdo", "tate", "mama", "gosho" };
const char* actions[] = { "tarashi", "tyrsi", "vika", "bie", "ddz" };

int strLen(const char* arr)
{
    int count = 0;
    while (arr[count] != '\0')
    {
        count++;
    }
    return count;
}

void isObjectOrSubject(bool** arr, int size)
{
    for (size_t i = 0; i < size; i++)// na [i][0] sedi dali e obekt, a na [i][1] sedi dali e subekt
    {
        arr[i] = new bool[2];
        
        int isObject = rand() % 2;
        int isSubject = rand() % 2;
        if (isObject == 0 && isSubject == 0)//shte e obekt i subekt ako i dvete sa nuli
        {
            arr[i][0] = true;
            arr[i][1] = true;
            continue;
        }
        else if (isObject == 0)
        {
            arr[i][0] = false;
        }
        else if(isObject == 1)
        {
            arr[i][0] = true;
        }

        else if (isSubject == 0)
        {
            arr[i][1] = false;
        }
        else if(isSubject == 1)
        {
            arr[i][1] = true;
        }
        
    }
}

void makeHeading(bool** IsObjectSubject)
{
    unsigned short pickExclamation = rand() % 5;
    unsigned short exclamationLen = strLen(exclamations[pickExclamation]);

    unsigned short pickExclamationMarks = rand() % 8 + 3;

    unsigned short pickObject;
    do
    {
        pickObject = rand() % 5;
    } while (IsObjectSubject[pickObject][0] != true);
    unsigned short objectLen = strLen(objectSubject[pickObject]);

    unsigned short action = rand() % 5;
    unsigned short actionLen = strLen(actions[action]);

    unsigned short pickSubject;
    do
    {
        pickSubject = rand() % 5;
    } while (IsObjectSubject[pickSubject][1] != true);
    unsigned short subjectLen = strLen(objectSubject[pickSubject]);


    int headingLen = exclamationLen + pickExclamationMarks + objectLen + actionLen + subjectLen;

    char* heading = new char[headingLen + 4];//+3 za prazni mesta, + 1 za "\0"
    unsigned int index = 0;

    for (size_t i = 0; i < exclamationLen; i++)
    {
        heading[index] = exclamations[pickExclamation][i];
        index++;
    }
    for (size_t i = 0; i < pickExclamationMarks; i++)
    {
        heading[index] = '!';
        index++;
    }
    heading[index] = ' ';
    index++;

    heading[index] = objectSubject[pickObject][0] - 32;
    index++;
    for (size_t i = 1; i < objectLen; i++)
    {
        heading[index] = objectSubject[pickObject][i];
        index++;
    }
    heading[index] = ' ';
    index++;

    for (size_t i = 0; i < actionLen; i++)
    {
        heading[index] = actions[action][i];
        index++;
    }
    heading[index] = ' ';
    index++;

    for (size_t i = 0; i < subjectLen; i++)
    {
        heading[index] = objectSubject[pickSubject][i];
        index++;
    }
    heading[index] = '\0';

    cout << heading << endl;
    delete[] heading;
}

void deleteBoolMatrixes(bool** M, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] M[i];
    }
    delete[] M;
}


int main()
{
    
    unsigned int N;
    do
    {
        cout << "Enter a number of headings: ";
        cin >> N;

    } while (N == 0);

 
    srand(time(NULL));

    bool** IsObjectSubject = new bool* [5];
    isObjectOrSubject(IsObjectSubject, 5);

    for (size_t i = 0; i < N; i++)
    {
        makeHeading(IsObjectSubject);
    } 
    
    deleteBoolMatrixes(IsObjectSubject, 5);

    
}

