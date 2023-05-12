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
char** readMap()
{
    ///
    /// open file 
    ///
    std::ifstream mapTmp("mapa.txt");
    
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
    std::ifstream mapFile("mapa.txt");
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
std::string** readStatus()
{
    ///
    /// open file
    ///
    std::ifstream tmp("status.txt");    
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
void buildCharacter(int choice) {

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
std::ofstream rozkazyTmp("rozkazy.txt");
std::ofstream historiaTmp("historia.txt", std::ios::app);

///
/// choice to build character
///
switch (choice)
{
case 1:
{   
    rozkazyTmp << "1 " << "B " << "K";
    historiaTmp << "1 " << "B " << "K" << std::endl;
    break;
}
case 2:
{
    rozkazyTmp << "1 " << "B " << "S";
    historiaTmp << "1 " << "B " << "S" << std::endl;
    break;
}
case 3:
{
    rozkazyTmp << "1 " << "B " << "A";
    historiaTmp << "1 " << "B " << "A" << std::endl;
    break;
}
case 4:
{
    rozkazyTmp << "1 " << "B " << "P";
    historiaTmp << "1 " << "B " << "P" << std::endl;
    break;
}
case 5:
{
    rozkazyTmp << "1 " << "B " << "R";
    historiaTmp << "1 " << "B " << "R" << std::endl;
    break;
}
case 6:
{
    rozkazyTmp << "1 " << "B " << "C";
    historiaTmp << "1 " << "B " << "C" << std::endl;
    break;
}
case 7:
{
    rozkazyTmp << "1 " << "B " << "W";
    historiaTmp << "1 " << "B " << "W" << std::endl;
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
    std::ifstream tmp("helperp1.txt");    
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
    /// add values to array
    ///
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
    read helper file
*/
std::string* readOrders()
{
    ///
    /// open file
    ///
    std::ifstream tmp("rozkazy.txt");    
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