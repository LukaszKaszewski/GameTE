#include <iostream>
#include <cstdlib> // exit(0), abs
#include <fstream> // wsppraca z plikami
#include <algorithm> // count
#include <string>   
#include <ctime>  
#include <chrono>
#include <queue>
#include <vector>
#include <cmath>
#include "header1.h"
#include "file1.cpp"

knight k1;
swordman s2;
archer a3;
pikeman p4;
catapult c5;
ram r6;
worker w7;

/*!
A small game project
\date A.D. 2023
\author Lukasz Kaszewski
\link lukasz.kaszewski@10g.pl
*/

int main(int argc, char const *argv[])
{
    ///
    /// time couter
    ///
    std::chrono::steady_clock sc;
    auto start = sc.now();

    ///
    /// read size map file
    ///
    std::ifstream mapTmp(argv[1]);    
    std::string line;
    int rowsMap = 0;
    int colsMap = 0;
    // check map size
    while (std::getline(mapTmp, line))
    {
        rowsMap++;
        colsMap = line.length();        
    }
    ///
    // file close
    ///
    mapTmp.close();

    char** mapItems = readMap(argv[1]);
    ///
    /// show map
    ///
    for (int i = 0; i < rowsMap; i++)
    {
        for (int j = 0; j < colsMap; j++)
        {
            char item = mapItems[i][j];
            //  std::cout << item;
        }
        //  std::cout << "    " << i + 1 << std::endl;
    }

    ///
    /// reaqd from status file
    ///
    std::string** statusTmp = readStatus(argv[2]);

    int rowsStat = 2000;
    int colsStat = 7;
    std::string item;

    for (int i = 0; i < rowsStat; i++)
    {
        for (int j = 0; j < colsStat; j++)
        {
            item = statusTmp[i][j];
            // std::cout << item << " ";
        }
        // std::cout << std::endl;
    }

    ///
    /// find base ID
    ///
    std::string baseID;

    if ((statusTmp[1][0] == "P" && statusTmp[1][1] == "B" && statusTmp[1][6] == "0")
    ||  (statusTmp[2][0] == "P" && statusTmp[2][1] == "B" && statusTmp[2][6] == "0"))
    {
        ///
        /// base ID
        ///
        if ((statusTmp[1][0] == "P") && (statusTmp[1][1] == "B"))
        {
            baseID = statusTmp[1][2];
        }
        if ((statusTmp[2][0] == "P") && (statusTmp[2][1] == "B"))
        {
            baseID = statusTmp[2][2];
        }
        

        int powerP = 0;
        int powerE = 0;
        for (int i = 3; i < rowsStat; i++)
        {            
            int choice;
            if (statusTmp[i][1] == "K") {
                choice = 1;
            } else if (statusTmp[i][1] == "S") {
                choice = 2;
            } else if (statusTmp[i][1] == "A") {
                choice = 3;
            } else if (statusTmp[i][1] == "P") {
                choice = 4;
            } else if (statusTmp[i][1] == "C") {
                choice = 5;
            } else if (statusTmp[i][1] == "R") {
                choice = 6;
            } else if (statusTmp[i][1] == "W") {
                choice = 7;
            }
            ///
            /// fire power (me)
            ///
            if (statusTmp[i][0] == "P")
            {
                switch (choice)
                {
                case 1:
                    powerP += k1.medDmg;
                    break;
                case 2:
                    powerP += s2.medDmg;
                    break;
                case 3:
                    powerP += a3.medDmg;
                    break;
                case 4:
                    powerP += p4.medDmg;
                    break;
                case 5:
                    powerP += c5.medDmg;
                    break;
                case 6:
                    powerP += r6.medDmg;
                    break;
                case 7:
                    powerP += w7.medDmg;
                    break;                    
                default:
                    break;
                }
            }

            ///
            /// fire power (enemy)
            ///
            if (statusTmp[i][0] == "E")
            {
                switch (choice)
                {
                case 1:
                    powerE += k1.medDmg;
                    break;
                case 2:
                    powerE += s2.medDmg;
                    break;
                case 3:
                    powerE += a3.medDmg;
                    break;
                case 4:
                    powerE += p4.medDmg;
                    break;
                case 5:
                    powerE += c5.medDmg;
                    break;
                case 6:
                    powerE += r6.medDmg;
                    break;
                case 7:
                    powerE += w7.medDmg;
                    break;                    
                default:
                    break;
                }                          
            }                
        }
        // std::cout << "PowerP: " << powerP << std::endl;
        // std::cout << "PowerE: " << powerE << std::endl;
        // std::cout << "Base ID: " << baseID << std::endl;
        int gold = stoi(statusTmp[0][0]);
        if (powerP <= powerE)
        {            
            if (gold >= k1.cost)
            {
                buildCharacter(1, argv[3], baseID);
            } else {
                goto attack;
            }
        } else {
            if (gold >= w7.cost)
            {
                buildCharacter(7, argv[3], baseID);
            } else {
                goto attack;
            }            
        }
        // std::cout << "Scenariusz budowania" << std::endl;
    } else {
        if ((statusTmp[1][0] == "P" && statusTmp[1][3] == "0" && statusTmp[1][4] == "0")
        ||  (statusTmp[2][0] == "P" && statusTmp[2][3] == "0" && statusTmp[2][4] == "0"))
        {
            attack:
            ///
            /// find gold and barriers
            ///
            int goldCounter = 0;
            int barrierCounter = 0;
            for (int i = 0; i < rowsMap; i++)
            {
                for (int j = 0; j < colsMap; j++)
                {
                    char item = mapItems[i][j];
                    // std::cout << item;
                    if (item == '6')
                    {
                        goldCounter++;
                    }
                    if (item == '9')
                    {
                        barrierCounter++;
                    }
                }
                //  std::cout << "    " << i + 1 << std::endl;
            }
            // std::cout << "Zloto: " << goldCounter << std::endl;
            // std::cout << "Przeszkody: " << barrierCounter << std::endl;

            ///
            /// gold/barriers coordinates
            ///
            int goldTmp = 0;
            int goldTab[goldCounter][2];
            int barrierTmp = 0;
            int barrierTab[barrierCounter][2];
            int myBase[1][1];
            int enemyBase[1][1];
            for (int i = 0; i < rowsMap; i++)
            {
                for (int j = 0; j < colsMap; j++)
                {
                    char item = mapItems[i][j];
                    // std::cout << item;
                    if (item == '6')
                    {
                        goldTab[goldTmp][0] = i;
                        goldTab[goldTmp][1] = j;
                        goldTmp++;
                    }
                    if (item == '9')
                    {
                        barrierTab[barrierTmp][0] = i;
                        barrierTab[barrierTmp][1] = j;
                        barrierTmp++;
                    }
                    if (item == '1')
                    {
                        myBase[0][0] = i;
                        myBase[0][1] = j;
                    }
                    if (item == '2')
                    {
                        enemyBase[0][0] = i;
                        enemyBase[0][1] = j;
                    }
                    
                }
                //  std::cout << "    " << i + 1 << std::endl;
            }
            ///
            /// show gold
            ///
            // for (int i = 0; i < goldCounter; i++)
            // {
            //     for (int j = 0; j < 2; j++)
            //     {
            //         std::cout << goldTab[i][j] << " ";
            //     }
            //         std::cout << std::endl;
            // }

            ///
            /// show barriers
            ///
            // for (int i = 0; i < barrierCounter; i++)
            // {
            //     for (int j = 0; j < 2; j++)
            //     {
            //         std::cout << barrierTab[i][j] << " ";
            //     }
            //         std::cout << std::endl;
            // }

            ///
            /// show base
            ///
            // std::cout << "My base: " << myBase[0][0] << " " << myBase[0][1] << std::endl;
            // std::cout << "My base: " << enemyBase[0][0] << " " << enemyBase[0][1] << std::endl;

            ///
            /// my army, enemy army
            ///
            int myArmyCounter = 0;
            int enemyArmyCounter = 0;
            for (int i = 3; i < rowsStat; i++)
            {            
                if (statusTmp[i][0] == "P")
                {
                    myArmyCounter++;
                }
                if (statusTmp[i][0] == "E")
                {
                    enemyArmyCounter++;
                }
            }
            // std::cout << "Ilosc mojej armi: " << myArmyCounter << std::endl;
            int myArmy = 0;
            int myArmyTmp[myArmyCounter][4];
            int enemyArmy = 0;
            int enemyArmyTmp[enemyArmyCounter][4];
            for (int i = 3; i < rowsStat; i++)
            {            
                if (statusTmp[i][0] == "P")
                {
                    myArmyTmp[myArmy][0] = i;
                    myArmyTmp[myArmy][1] = stoi(statusTmp[i][2]);
                    myArmyTmp[myArmy][2] = stoi(statusTmp[i][3]);
                    myArmyTmp[myArmy][3] = stoi(statusTmp[i][4]);
                    myArmy++;
                }
                if (statusTmp[i][0] == "E")
                {
                    enemyArmyTmp[enemyArmy][0] = i;
                    enemyArmyTmp[enemyArmy][1] = stoi(statusTmp[i][2]);
                    enemyArmyTmp[enemyArmy][2] = stoi(statusTmp[i][3]);
                    enemyArmyTmp[enemyArmy][3] = stoi(statusTmp[i][4]);
                    enemyArmy++;
                }
            }
            // for (int i = 0; i < myArmyCounter; i++)
            // {
            //     std::cout << myArmyTmp[i] << std::endl;
            // }
            // for (int i = 0; i < enemyArmyCounter; i++)
            // {
            //     std::cout << enemyArmyTmp[i] << std::endl;
            // }
            srand(time(NULL));
            int whoAttack = (std::rand() % myArmyCounter);
            // std::cout << "Atakujacy: " << whoAttack << std::endl;
            // std::cout << "Atakujacy poz: " << myArmyTmp[whoAttack][0] << std::endl;
            // std::cout << "Atakujacy id: " << myArmyTmp[whoAttack][1] << std::endl;
            // std::cout << "Atakujacy row: " << myArmyTmp[whoAttack][2] << std::endl;
            // std::cout << "Atakujacy col: " << myArmyTmp[whoAttack][3] << std::endl;

            ///
            /// read map
            ///
            std::ifstream mapFile(argv[1]); // ??? segmentation fault (core dumped) ???
            if (!mapFile)
            {
                std::cout << "Cos tu jest nie tak!!!\nsegmentation fault (core dumped)" << std::endl;
                return 1;
            }
            
            std::vector<std::vector<char>> mapVector;
            std::string line;

            while (std::getline(mapFile, line))
            {
            std::vector<char> row(line.begin(), line.end());
            mapVector.push_back(row);
            }
            mapFile.close();

            int rowsV = mapVector.size();
            int colsV = mapVector[0].size();


            if(statusTmp[myArmyTmp[whoAttack][0]][1] == "W")
            {
                // std::cout << "Worker" << std::endl;
            ///
            /// distance to gold
            ///
                int minDist;
                int minId;
                int distance[goldCounter];
                for (int i = 0; i < goldCounter; i++)
                {
                    distance[i] = abs(myArmyTmp[whoAttack][2] - goldTab[i][0])
                            + abs(myArmyTmp[whoAttack][3] - goldTab[i][1]);
                    // std::cout << distance[i] << std::endl;
                    if (distance[i] < 2)
                    {
                        break;
                    }                
                }
                minDist = distance[0];
                for (int i = 0; i < goldCounter; i++)
                {
                    if (minDist>distance[i])
                    {
                        minDist = distance[i];
                        minId = i;
                    }                    
                }

                // std::cout << "Min: " << minDist << std::endl;
                // std::cout << "Min: " << minId << std::endl;
                point start(myArmyTmp[whoAttack][2], myArmyTmp[whoAttack][3]);
                // point target();

            } else {
            // std::cout << "Not worker" << std::endl;
            ///
            /// distance to enemy
            ///
                // for (int i = 0; i < enemyArmyCounter; i++)
                // {
                //     int distance = 0;
                //     distance = abs(myArmyTmp[whoAttack][2] - enemyArmyTmp[i][2])
                //             + abs(myArmyTmp[whoAttack][3] - enemyArmyTmp[i][3]);
                //     std::cout << distance << std::endl;
                //     if (distance < 5)
                //     {
                //         break;
                //     }                
                // }
            }

            // std::cout << "Zaczynam z gory" << std::endl;
        }

        if ((statusTmp[1][0] == "P" && statusTmp[1][3] == "31" && statusTmp[1][4] == "31")
        ||  (statusTmp[2][0] == "P" && statusTmp[2][3] == "31" && statusTmp[2][4] == "31"))
        {
            // std::cout << "Zaczynam z dolu" << std::endl;
        }
        

        // baseID = statusTmp[i][2];
        // std::cout << "Scenariusz ataku" << std::endl;
    }       

        ///
        /// time
        ///
        auto end = sc.now();
        auto timeSpan = static_cast<std::chrono::duration<double>>(end - start);
        std::cout << timeSpan.count() << " sec." << std::endl;        

    return 0;
}