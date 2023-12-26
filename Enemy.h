#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>
#include "Character.h"
using namespace std;

class Enemy : public Character
{
private:
    
public:
    Enemy();
    Enemy(const string& n);
    Enemy(const string& n, int h);
    Enemy(const string& n, int at, int h);
    void attack(Character& target); //Attack Player
    void print();
    void print(int atorh); // 0: Print only attack index, 1: Print only health
};

#endif // ENEMY_H
