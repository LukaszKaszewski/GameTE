#include <iostream>
#include <cstdlib> // exit(0)
#include <fstream> // wsppraca z plikami
#include <algorithm> // count
#include <string>   
#include <ctime>  
#include "header1.h"
#include "file1.cpp"

knight k1;
swordman s2;
archer a3;
pikeman p4;
ram r5;
catapult c6;
worker w7;

int main(int argc, char const *argv[])
{
    int rounds;
    ///
    /// read from map file
    ///
    std::ifstream mapTmp("mapa.txt");    
    std::string line;
    int rows = 0;
    int cols = 0;
    // check map size
    while (std::getline(mapTmp, line))
    {
        rows++;
        cols = line.length();        
    }
    ///
    // file close
    ///
    mapTmp.close();

    char** mapItems = readMap();
    ///
    /// show map
    ///
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            char item = mapItems[i][j];
    //         std::cout << item;
        }
    //     std::cout << "    " << i + 1 << std::endl;
    }

    ///
    /// reaqd fro status file
    ///
    std::string** statusTmp = readStatus();

    rows = 2000;
    cols = 7;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::string item = statusTmp[i][j];
            // std::cout << item << " ";
        }
        // std::cout << std::endl;
    }

    ///
    /// read helper file
    ///
    int* helperTmp = readHelperP1();
    srand(time(NULL));
    int bld = (std::rand() % 7) + 1;
    // std::cout << "helper: " << helperTmp[0] << " " << helperTmp[1] << std::endl;
    int helperVal1Counter = helperTmp[0];
    int helperVal2BT = helperTmp[1];
    int helperVal3ID = helperTmp[2];
    int helperVal4Choice = helperTmp[3];
    int helperVal5Rounds = helperTmp[4];
    helperVal5Rounds++;

    ///
    /// game start
    ///
    if (helperVal1Counter == 0 && helperVal2BT == 0)
        {
            std::ofstream hlp("helperp1.txt");
            switch (bld)
            {
            case 1:
                hlp << k1.buildTime << " " << k1.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
                break;
            case 2:
                hlp << s2.buildTime << " " << s2.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
                break;
            case 3:
                hlp << a3.buildTime << " " << a3.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
                break;
            case 4:
                hlp << p4.buildTime << " " << p4.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
                break;
            case 5:
                hlp << r5.buildTime << " " << r5.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
                break;
            case 6:
                hlp << c6.buildTime << " " << c6.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
                break;
            case 7:
                hlp << w7.buildTime << " " << w7.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
                break;
            default:
                break;
            }
            hlp.close();
        } else if (helperVal1Counter == 0) {
        ///
        /// open file
        ///    
        std::ofstream hlp("helperp1.txt");
        std::ofstream order("rozkazy.txt");
        
        ///
        /// create character if when base dont build nothing
        ///
        buildCharacter(helperVal4Choice);
        
        switch (helperVal4Choice)
        {
        case 1:
            hlp << k1.buildTime << " " << k1.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
            break;
        case 2:
            hlp << s2.buildTime << " " << s2.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
            break;
        case 3:
            hlp << a3.buildTime << " " << a3.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
            break;
        case 4:
            hlp << p4.buildTime << " " << p4.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
            break;
        case 5:
            hlp << r5.buildTime << " " << r5.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
            break;
        case 6:
            hlp << c6.buildTime << " " << c6.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
            break;
        case 7:
            hlp << w7.buildTime << " " << w7.buildTime << " " << helperVal3ID + 1 << " " << bld << " " << helperVal5Rounds;
            break;
        default:
            break;
        }
        ///
        /// file close
        ///
        hlp.close();
        order.close();
        
        } else {
            ///
            /// war zone
            ///

            helperVal1Counter--;
            std::ofstream tmp("helperp1.txt");
            tmp << helperVal1Counter << " " << helperVal2BT << " " << helperVal3ID << " " << helperVal4Choice << " " << helperVal5Rounds;
            tmp.close();
        }
    return 0;
}

