#include <iostream>
using namespace std;


int getMaxInd(int* rooms, int roomsCount)
{
    int maxInd = 0;
    for (size_t i = 1; i < roomsCount; i++)
    {
        if (rooms[i] > rooms[maxInd])
        {
            maxInd = i;
        }
    }

    return maxInd;
}

void addRoom(int* rooms, int& roomsCount, int currentMaxInd)
{
    for (size_t i = 0; i < roomsCount - 1; i++)
    {
        if (i == currentMaxInd)
        {
            for (size_t j = roomsCount - 1; j >= currentMaxInd + 2; j--)
            {
                rooms[j] = rooms[j - 1];
            }
        }
    }
    rooms[currentMaxInd] = rooms[currentMaxInd] / 2;
    rooms[currentMaxInd + 1] = rooms[currentMaxInd];
}

void getNewRooms(int* rooms, int* newRooms, int roomsCount)
{
    for (size_t i = 0; i < roomsCount; i++)
    {
        newRooms[i] = rooms[i];
    }
}

void printRooms(int* rooms, int roomsCount)
{
    cout << "[";
    for (size_t i = 0; i < roomsCount - 1; i++)
    {
        cout << rooms[i] << ", ";
    }
    cout << rooms[roomsCount - 1] << "]" << endl;
}

void commandA(int*& rooms, int& roomsCount, int& roomCapacity, int soldiers)
{
    if (roomsCount + soldiers > roomCapacity)
    {
        roomCapacity = (roomsCount + soldiers) * 2;

        
        int* newRooms = new int[roomCapacity];

        getNewRooms(rooms, newRooms, roomsCount);
        delete[] rooms;

        rooms = newRooms;
    }
    for (size_t i = 0; i < soldiers; i++)
    {
        int currentMaxInd = getMaxInd(rooms, roomsCount);
        if (rooms[currentMaxInd] == 2)
        {
            cout << "Try again after Hoth" << endl;
            break;
        }
        roomsCount++;
        addRoom(rooms, roomsCount, currentMaxInd);
        //printRooms(rooms, roomsCount);
        
        
    }
    
}

void handleCommand(int*& rooms, int& roomsCount, int& roomCapacity, char command)
{
    if (command == 'A')
    {
        int soldiers;
        cin >> soldiers;
        commandA(rooms, roomsCount, roomCapacity, soldiers);
        //printRooms(rooms, roomsCount);
    }
    else if (command == 'P')
    {
        printRooms(rooms, roomsCount);
    }
}

int main()
{
    
    int roomsCount;
    do
    {
        cin >> roomsCount;
    } while (roomsCount < 4 || roomsCount > 1024);

    int roomCapacity = 2 * roomsCount;
    int* rooms = new int[roomCapacity];

    for (size_t i = 0; i < roomsCount; i++)
    {
        do
        {
            cin >> rooms[i];
        } while (rooms[i] % 2 != 0 && (rooms[i] < 2 || rooms[i] > 256));
        
    }
   
    char command;
    cin >> command;
    while (command != 'E')
    {
        handleCommand(rooms, roomsCount, roomCapacity, command);
        cin >> command;
    }


    delete[] rooms;
}

