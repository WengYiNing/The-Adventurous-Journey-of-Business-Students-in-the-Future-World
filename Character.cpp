//
//  Character.cpp
//  程式設計期末專案
//
//  Created by 翁翊寧 on 2023/12/9.
//

#include "Character.h"
#include <iostream>
#include <string>
#include "Item.h"
// #include "player.h"

using namespace std;

Character::Character (const string & n) : name(n)
{
    attackIndex = 0;
    health = 0;
    itemCnt = 0;
    
    for(int i = 0; i < itemCap; i++)
    {
        itemArray[i]= nullptr;
    }
}

Character::Character()
{
    name = "";

    attackIndex = 0;
    health = 0;
    itemCnt = 0;
    
    for(int i = 0; i < itemCap; i++)
    {
        itemArray[i]= nullptr;
    }
}

Character::Character(const Character &c)
{
    name = c.name;
    attackIndex = c.attackIndex;
    health = c.health;
    itemCnt = c.itemCnt;
    
    for(int i = 0; i < itemCnt; i++)
    {
        delete itemArray[i];
        itemArray[i] = new Item(*(c.itemArray[i]));
    }
}

void Character::operator=(const Character &c)
{
    name = c.name;
    attackIndex = c.attackIndex;
    health = c.health;
    itemCnt = c.itemCnt;
    
    for(int i = 0; i < itemCnt; i++)
    {
        delete itemArray[i];
        itemArray[i] = new Item(*(c.itemArray[i]));
    }
    
}

void Character::hurt(int damage)
{
    this->health -= damage;
}
