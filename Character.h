//
//  Character.h
//  程式設計期末專案
//
//  Created by 翁翊寧 on 2023/12/7.
//

#ifndef Character_h
#define Character_h

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

const int itemCap = 6;

class Character
{
protected :
    string name ;

    int attackIndex;
    int health;
    
    int itemCnt;
    Item* itemArray[itemCap];
    
public :
    Character (const string & n);
    Character();
    Character(const Character &c);
    void operator=(const Character &c);
    virtual ~Character()
    {
        for(int i = 0; i < itemCnt; i++)
            delete itemArray[i];
    }
    
    string getName () const
    {
        return name ;
    }
    
    void setAttackIndex(int attackI)
    {
        attackIndex = attackI;
    }
    
    int getAttackIndex () const
    {
        return attackIndex;
    }
    
    void setHealth(int health)
    {
        this->health = health;
    }
    
    int getHealth () const
    {
        return health ;
    }
    
    void earnItem(const Item &i)
    {
        itemArray[itemCnt] = new Item(i);
        itemCnt++;
    }
    
    virtual void attack ( Character & target ) = 0;
    void hurt(int damage);
};

#endif /* Character_h */
