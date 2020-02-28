#include <iostream>
#include<string>
using namespace std;
#pragma warning(disable:4996)//davashe mi greshki za strtok i v stackoverflow pisheshe da go zabranq taka, ne znam kakvo tochno pravi...

void initMatrix(char** matrix, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new char[10];
    }
}
void deleteMatrix(char** matrix, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

char* checkBegining(char* path)
{
    char* delimiter = new char;
    *delimiter = path[0];
    cout << *delimiter;
    if (path[0] == '/')
    {
        if (path[1] != '/')
        {
            return delimiter;
        }
        else
        {
            return nullptr;
        }
    }
    else if (path[0] == '\\')
    {
        if (path[1] == '\\' && path[2] != '\\')
        {
            return delimiter;
        }
        else
        {
            return nullptr;
        }
    }
}

bool checkPathTokens(char* token, int size, char* delimiter)
{
    if (token[0] < 'A' || token[0] > 'z')
    {
        return false;
    }
    
    bool isGood = true;

    for (size_t i = 1; i < size; i++)
    {
        if ((token[i] > 'A' && token[i] < 'z') || token[i] == '_' || (token[i] > '0' && token[i] < '9'))
        {
            
        }
        else
        {
            return false;
        }
    }

    

    return isGood;
}

bool checkExtension(char* extension, char** extensions, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(extensions[i], extension) == 0)
        {
            return true;
        }
    }
    return false;
}

int countDelimiters(char* path, int size, char* delimiter)
{
    int count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (*delimiter == path[i])
        {
            count++;
        }
    }

   return count;
}

int main()
{ 
    int n;
    cout << "Number of extensions: ";
    cin >> n;

    char** extensions = new char* [n];
    initMatrix(extensions, n);

    for (size_t i = 0; i < n; i++)
    {
        cout << "-Enter file extension: ";
        cin >> extensions[i];
    }

    char* checkDot;
    char* token;

    
    while (true)
    {
        char* path = new char[100];
        cout << "Add file by path: ";
        cin >> path;

        char* delimiter;
        delimiter = checkBegining(path);

        int delimiterCounter = 0;//broq kolko '/' ili '\\' trqbva da ima

        int countDelimiterss;//kolko sa vavedeni vsashnost naprimer  -> ////////Path///////game.exe -> demek sledq za greshki

        bool goodInput = false;
        bool goodExtension = false;

        if (delimiter != nullptr)
        {
            countDelimiterss = countDelimiters(path, strlen(path), delimiter);
            token = strtok(path, delimiter);

            while (token != NULL)
            {
                delimiterCounter++;

                checkDot = strstr(token, ".");
                if (checkDot && !strtok(NULL, delimiter))
                {
                    goodExtension = checkExtension(checkDot, extensions, n);
                    char* getWordBeforeExt = strtok(token, ".");
                    goodInput = checkPathTokens(getWordBeforeExt, strlen(getWordBeforeExt), delimiter);
                    break;
                }
                else
                {
                    goodInput = checkPathTokens(token, strlen(token), delimiter);
                }
                 
                if(!goodInput)
                {
                    break;
                }
                
                token = strtok(NULL, delimiter);
            }         
        }       

        if (*delimiter == '\\')
        {
            delimiterCounter *= 2;
        }
        if (delimiterCounter != countDelimiterss)
        {
            goodInput = false;
        }

        if (!goodInput)
        {
            cout << "- error! Wrong input. Try again." << endl;
        }
        else if (!goodExtension)
        {
            cout << "- error! The cloud does not recognise this file extension. Try again." << endl;
        }
        else
        {
            char yesNo;
            cout << "- Success! File successfully uploaded!";
            cout << "Do you want to add more files? [y | n]." << endl;
            cin >> yesNo;
            if (yesNo == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }

        delete[] path;

    }

    deleteMatrix(extensions, n);
    
}

