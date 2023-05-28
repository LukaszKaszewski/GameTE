#include <iostream>
#include <cstdlib> // exit(0)
#include <fstream> // wsppraca z plikami
#include <algorithm> // count
#include <string>     
#include <unistd.h> // sleep
#include "header1.h"

/*!
    read map function
*/
char** readMap(std::string map)
{
    ///
    /// open file 
    ///
    std::ifstream mapTmp(map);
    
    std::string line;
    int rows = 0;
    int cols = 0;
    
    ///
    /// check file exists
    ///
    if (!mapTmp.good())
    {
        std::cout << "Nie ma takiego pliku." << std::endl;
        exit(0);
    }

    ///
    /// check map size
    ///
    while (std::getline(mapTmp, line))
    {
        rows++;
        cols = line.length();        
    }

    ///
    /// close file
    ///
    mapTmp.close();

    ///
    /// open file
    ///
    std::ifstream mapFile(map);
    char** mapItems = new char*[rows];

    ///
    /// allocate memory for each row
    ///
    for (int i = 0; i < rows; i++)
    {
        mapItems[i] = new char[cols];
    }

    ///
    /// read values and add to array
    ///
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mapFile >> mapItems[i][j];
        }        
    }
    
    ///
    /// close file
    ///
    mapFile.close();

    ///
    /// return the mapItems array
    ///
    return mapItems;
}

/*!
    free map memory
    \param char** mapItems
    \param int rows
*/
void freeMap(char** mapItems, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mapItems[i];
    }
    delete[] mapItems;
}

/*!
    read status file
*/
std::string** readStatus(std::string status)
{
    ///
    /// open file
    ///
    std::ifstream tmp(status);    
    std::string line;

    ///
    /// check file exists
    ///
    if (!tmp.good())
    {
        std::cout << "Nie ma takiego pliku." << std::endl;
        exit(0);
    }

    std::string** statusTmp = new std::string*[2000];

    ///
    /// allocate memory for each row
    ///
    for (int i = 0; i < 2000; i++)
    {
        statusTmp[i] = new std::string[7];
    }

    int row = -1;
    int col;
    
    ///
    /// check size
    ///
    while (std::getline(tmp, line))
    {
        col = 0;
        row++;
        for (int i = 0; i < line.length(); i++)
        {
            // std::cout << line[i] << std::endl;
            if (line[i] == 32)
            {
                col++;
                continue;
            }
            statusTmp[row][col] += line[i];
        }        
    }

    ///
    /// close file
    ///
    tmp.close();

    ///
    /// return statusTmp array
    ///
    return statusTmp;
}

/*!
    free status file memory
    \param string** statusTmp
*/
void freeStatus(std::string** statusTmp)
{
    for (int i = 0; i < 2000; i++)
    {
        delete[] statusTmp[i];
    }
    delete[] statusTmp;
}

/*!
    build character
*/
void buildCharacter(int choice, std::string orders, std::string baseID) {

knight k1;
swordman s2;
archer a3;
pikeman p4;
ram r5;
catapult c6;
worker w7;

///
/// file open
///
std::ofstream rozkazyTmp(orders);
std::ofstream historiaTmp("historia.txt", std::ios::app);

///
/// choice to build character
///
switch (choice)
{
case 1:
{   
    rozkazyTmp << baseID << " B " << "K";
    historiaTmp << baseID << " B " << "K" << std::endl;
    break;
}
case 2:
{
    rozkazyTmp << baseID << " B " << "S";
    historiaTmp << baseID << " B " << "S" << std::endl;
    break;
}
case 3:
{
    rozkazyTmp << baseID << " B " << "A";
    historiaTmp << baseID << " B " << "A" << std::endl;
    break;
}
case 4:
{
    rozkazyTmp << baseID << "B " << "P";
    historiaTmp << baseID << " B " << "P" << std::endl;
    break;
}
case 5:
{
    rozkazyTmp << baseID << "B " << "R";
    historiaTmp << baseID << " B " << "R" << std::endl;
    break;
}
case 6:
{
    rozkazyTmp << baseID << "B " << "C";
    historiaTmp << baseID << " B " << "C" << std::endl;
    break;
}
case 7:
{
    rozkazyTmp << baseID << " B " << "W";
    historiaTmp << baseID << " B " << "W" << std::endl;
    break;
}

default:
    break;
}

///
/// file close
///
rozkazyTmp.close();
historiaTmp.close();
}

/*!
    read helper file
*/
int* readHelperP1()
{
    ///
    /// open file
    ///
    std::ifstream tmp("lukaszkaszewski.txt");    
    std::string line;

    ///
    /// check file exist
    ///
    if(tmp.good()==false)
    {
        std::cout << "Nie ma takiego pliku." << std::endl;
        exit(0);
    }

    const int size = 5;
    int* array = new int[size];
    int count = 0;
    int x;
    
    ///
    /// add values to800 
    while (count < size && tmp >> x)
    {
        array[count++] = x;    
    }

    ///
    /// close file
    ///
    tmp.close();

    ///
    /// return array of values
    ///
    return array;
}

/*!
    read order file
*/
std::string* readOrders(std::string orders)
{
    ///
    /// open file
    ///
    std::ifstream tmp(orders);    
    std::string line;

    ///
    /// check file exists
    ///
    if (!tmp.good())
    {
        std::cout << "Nie ma takiego pliku." << std::endl;
        exit(0);
    }

    std::string* statusTmp = new std::string[4];

    int col;
    
    ///
    /// add values to array
    ///
    while (std::getline(tmp, line))
    {
        col = 0;
        for (int i = 0; i < line.length(); i++)
        {
            // std::cout << line[i] << std::endl;
            if (line[i] == 32)
            {
                col++;
                continue;
            }
            statusTmp[col] += line[i];
        }        
    }

    ///
    /// close file
    ///
    tmp.close();

    ///
    /// return the statusTmp array
    ///
    return statusTmp;
}

/*!
    update gold value - status file
*/
void goldUpdate(std::string statusFile, int gold, std::string newGold)
{
    std::ofstream statFile(statusFile, std::ios::in | std::ios::out);
        if (statFile.is_open())
        {
            if (gold >= 1000)
            {
                statFile.seekp(0);
                statFile << newGold;
                statFile.close();
            } else {
                statFile.seekp(0);
                statFile << newGold << " ";
                statFile.close();
            }
        }
}

/*!
    check point on map
*/
bool isValid(int x, int y, int rows, int cols, const std::vector<std::vector<char>>& map)
{
    return (x >= 0 && x < rows && y >= 0 && y < cols && map[x][y] != '#');
}

/*!
    route do target with numer of steps
*/
point moveToTarget(const point& start, const point& target, int steps) {
    double dx = target.x - start.x;
    double dy = target.y - start.y;

    double distance = std::abs(start.x - target.x) + std::abs(start.y - target.y);

    if (distance == 0) {
        return start;
    }

    double ratio = std::min(1.0, steps / distance);
    int newX = start.x + std::round(dx * ratio);
    int newY = start.y + std::round(dy * ratio);

    return point(newX, newY);
}

