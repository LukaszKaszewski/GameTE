#include <iostream>
#include <cstdlib> // exit(0)
#include <fstream> // wsppraca z plikami
#include <algorithm> // count
#include <string>   
#include "header1.h"

void readMap()
{
    // zmienna plikowa, otwarcie pliku
    std::ifstream mapTmp("mapa.txt");
    
    std::string line;
    int rows = 0;
    int cols = 0;

    // sprawdzenie czy plik istnieje
    if(mapTmp.good()==false)
    {
        std::cout << "Nie ma takiego pliku." << std::endl;
        exit(0);
    }

    // sprawdzenie rozmiarow mapy
    while (std::getline(mapTmp, line))
    {
        rows++;
        cols = line.length();        
    }
    
    // std::cout << "Wiersze: " << rows << std::endl;
    // std::cout << "Kolumny: " << cols << std::endl;

    // zamkniecie pliku
    mapTmp.close();

    // otwarcie pliku
    std::ifstream mapFile("mapa.txt");
    char mapItems[cols][rows];

    // odczyt wartosci z pliku i wrzucenie ich do tablicy
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mapFile >> mapItems[i][j];
        }        
    }
    
    // rysowanie mapy
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << mapItems[i][j];
        }
        std::cout << "    " << i + 1 << std::endl;        
    }

    // zamkniecie pliku
    mapFile.close();
}