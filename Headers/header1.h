#ifndef HEADER1_H_INCLUDED
#define HEADER1_H_INCLUDED

///
/// character knight structure 
///
struct knight
{
    int hp = 70;
    int speed = 5;
    int cost = 400;
    int attackRange = 1;
    int buildTime = 5;
};

///
/// character swordman structure 
///
struct swordman
{
    int hp = 60;
    int speed = 2;
    int cost = 250;
    int attackRange = 1;
    int buildTime = 3;
};

///
/// character archer structure 
///
struct archer
{
    int hp = 40;
    int speed = 2;
    int cost = 250;
    int attackRange = 5;
    int buildTime = 3;
};

///
/// character pikeman structure 
///
struct pikeman
{
    int hp = 50;
    int speed = 2;
    int cost = 200;
    int attackRange = 2;
    int buildTime = 3;
};

///
/// character ram structure 
///
struct ram
{
    int hp = 90;
    int speed = 2;
    int cost = 500;
    int attackRange = 1;
    int buildTime = 4;
};

///
/// character catapult structure 
///
struct catapult
{
    int hp = 50;
    int speed = 2;
    int cost = 800;
    int attackRange = 7;
    int buildTime = 6;
};

///
/// character worker structure 
///
struct worker
{
    int hp = 20;
    int speed = 2;
    int cost = 100;
    int attackRange = 1;
    int buildTime = 2;
};

///
/// base structure 
///
struct base
{
    int hp = 200;
    int speed = 0;
};

char** readMap();
void freeMap(char**, int);
std::string** readStatus();
void makeCharacter(int);
int* readHelperP1();
std::string* readOrders();

#endif