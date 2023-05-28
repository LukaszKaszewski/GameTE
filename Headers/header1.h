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
    int avgDmg = 37;
    int medDmg = 35;
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
    int avgDmg = 28;
    int medDmg = 30;
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
    int avgDmg = 14;
    int medDmg = 15;
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
    int avgDmg = 16;
    int medDmg = 15;
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
    int avgDmg = 41;
    int medDmg = 40;
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
    int avgDmg = 15;
    int medDmg = 10;
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
    int avgDmg = 5;
    int medDmg = 5;
};

///
/// base structure 
///
struct base
{
    int hp = 200;
    int speed = 0;
};

struct point
{
    int x;
    int y;

    point(int x, int y) : x(x), y(y) {}
};

char** readMap(std::string);
std::string** readStatus(std::string);
void buildCharacter(int, std::string, std::string);


int* readHelperP1();
void freeMap(char**, int);
void freeStatus(std::string**);;
std::string* readOrders(std::string);
void goldUpdate(std::string, int, std::string);

#endif