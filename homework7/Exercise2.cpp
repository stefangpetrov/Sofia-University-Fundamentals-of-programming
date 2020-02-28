#include <iostream>
#include<ctime>
using namespace std;

const unsigned short MAX_SIZE = 100;

void inputDeck(unsigned short* deck)
{
    for (int i = 0; i < 52; i++)
    {
        cin >> deck[i];
    }
    cout << endl << endl;
}

void printDeck(unsigned short* deck)
{

    for (int i = 0; i < 52; i++)
    {
        cout << deck[i] << " ";
    }
    cout << endl << endl;
}

void printDeckWithHighlights(unsigned short* deck, int firstInd, int secondInd)
{
    for (int i = 0; i < 52; i++)
    {
        if (i == firstInd || i == secondInd)
        {
            cout << "(";
        }
        cout << deck[i];
        if (i == firstInd || i == secondInd)
        {
            cout << ")";
        }
        cout << " ";
    }
    cout << endl << endl;
}

void swap(unsigned short* deck, int a, int b)
{
    unsigned short temp = deck[a];
    deck[a] = deck[b];
    deck[b] = temp;
}

void generateDeck(unsigned short* deck)
{
    for (int i = 4; i >= 1; i--)
    {
        int currentCard = 2;
        for (int j = (4 - i) * 13; j < (4 - i) * 13 + 12; j++)
        {
            deck[j] = i * 100 + currentCard;
            currentCard++;
        }
    }

    deck[12] = 401;
    deck[25] = 301;
    deck[38] = 201;
    deck[51] = 101;

}

void randomizeDeck(unsigned short* deck)//просто използвам суапа и разменям рандом елементи друго не ми хрумна
{
    for (int i = 0; i < 52; i++)
    {
        int firstIndex = rand() % 52;
        int secondIndex = rand() % 52;
        swap(deck, firstIndex, secondIndex);
    }
}

void sortByPower(unsigned short* deck)
{
    int aceCount = 0;
    for (int i = 0; i < 48; i++)
    {
        unsigned short currentMinInd = i;
        if (deck[currentMinInd] % 100 == 1)//ако имаме асо :)
        {
            printDeckWithHighlights(deck, currentMinInd, 51 - aceCount);
            swap(deck, currentMinInd, 51 - aceCount);//Подреждам асата на последните 4 места от масива
            aceCount++;

            if (deck[currentMinInd] % 100 == 1)
            {
                i--;//ако е имало асо на това място, с което суапвам, връщам цикъла с 1 позиция за да сложим и това асо в края на масива като с aceCount предотвратявам безкраен цикъл 
                continue;
            }
            
        }
        for (int j = i + 1; j < 51; j++)
        {
            unsigned short currentChecker = deck[j] % 100;//стандартна сортировка на елементите, които не са аса според цифрите на единици и десетици(selection sort)
            if (deck[currentMinInd] % 100 > currentChecker && currentChecker != 1)
            {
                currentMinInd = j;
            }

        }

        if (currentMinInd != i)//стандартна сортировка на елементите, които не са аса според цифрите на единици и десетици(selection sort)
        {
            printDeckWithHighlights(deck, currentMinInd, i);
            swap(deck, currentMinInd, i);
        }
        
    }
}

void sortCurrent13(unsigned short* deck, int start, int end)
{
    
    for (int i = start; i < end; i++)//слагам асата в края. Докато се сетя да го изкарам отделно сигурно 2 часа мислих...
    {
        if (deck[i] % 100 == 1)
        {
            printDeckWithHighlights(deck, i, end);
            swap(deck, i, end);
            break;
        }
    }
    for (int i = start; i < end; i++)//останалите елементи претърпяват стандартен selection sort
    {
        unsigned short currentMinInd = i;
        
        for (int j = i + 1; j < end; j++)
        {
            unsigned short currentChecker = deck[j] % 100;
            if (deck[currentMinInd] % 100 > currentChecker)
            {
                currentMinInd = j;
            }

        }

        if (currentMinInd != i)
        {
            printDeckWithHighlights(deck, currentMinInd, i);
            swap(deck, currentMinInd, i);
        }
    }
}
void sortBySuit(unsigned short* deck)
{
    int currentCard = 0;
    for (int i = 4; i >= 1; i--)//от 4 до 1 тъй като  е спатия = 4 каро = 3 и тн
    {  
        for (int j = (4-i)*13; j < 52; j++)//тук сортирам всеки 13 елемента да са с 1 и съща цифра на 100-тиците
        {
            if (deck[j] / 100 == i)
            {
                printDeckWithHighlights(deck, j, currentCard);
                swap(deck, j, currentCard);
                currentCard++;
            }
            
        }
        
        sortCurrent13(deck, (4 - i) * 13, (4 - i) * 13 + 12);//от (4- i)*13 до (4 - i) * 13 + 12 са съответните 13 елемента
        
        
    }
}


int main()
{
    
    unsigned short* deck = new unsigned short[MAX_SIZE];
    srand(time(NULL));

   inputDeck(deck);//a podtochka
   
    sortByPower(deck);
    printDeck(deck);

    sortBySuit(deck);
    printDeck(deck);
    cout << "------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;

    generateDeck(deck);//b podtochka
    printDeck(deck);

    randomizeDeck(deck);
    printDeck(deck);

    sortByPower(deck);
    sortBySuit(deck);
    printDeck(deck);

    delete[] deck;
}

