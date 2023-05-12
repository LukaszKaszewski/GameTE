#include <iostream>
#include <cstdlib> // exit(0)
#include <fstream> // wsppraca z plikami
#include <algorithm> // count
#include <string>     
#include <unistd.h> // sleep
#include "header1.h"
#include "file1.cpp"

/*!
A small game project
\date A.D. 2023
\author Lukasz Kaszewski
\link lukasz.kaszewski@10g.pl
*/

int main(int argc, char const *argv[])
{
    int* helperTmp = readHelperP1();
    int helperVal = helperTmp[2];

    int rounds = 30;
    for (int i = 0; i < rounds; i++)
    {
        if (rounds < helperVal)
        {
            system("./p1.out");
            sleep(1);
            system("./p2.out");
            sleep(1);
        }      

        std::string* ordersTmp = readOrders();

        std::cout << ordersTmp[0];
        std::cout << ordersTmp[1];
        std::cout << ordersTmp[2] << std::endl;
    }

    return 0;
}
