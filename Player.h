#ifndef player_H
#define player_H

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Enemy.h"
#include "Item.h"
using namespace std;

class Player : public Character
{
private:
    int finKnowledge;
    int quantSkill;
    int commuSkill;
    int programSkill;
    int liverIndex;
    int lazyIndex;
    vector<Item> itemVector;
    vector<int> courseVector;

    int roundCnt;

public:
    Player();
    Player(const string& n);
    ~Player(){};
    Player(const Player& p);
    void operator=(const Player& p);
    void addItem(const Item& item); // Obtain an item
    void addCapab(int capab, int addnum); // Acquire an ability
    void addCourse(int course); // Complete a course
    void addRoundCnt(int round); // Obtain the round count
    void attack(Character& target); // Attack the enemy
    void hurt(int damage); // Be attacked by the enemy

    void addfinKnowledge(int fk);
    void addquantSkill(int qs);
    void addcommuSkill(int cs);
    void addprogramSkill(int ps);
    void addliverIndex(int li);
    void addlazyIndex(int li);

    int getFinKnowledge() const
    {
        return finKnowledge;
    }
    
    int getQuantSkill() const
    {
        return quantSkill;
    }
    
    int getCommuSkill() const
    {
        return commuSkill;
    }
    
    int getProgramSkill() const
    {
        return programSkill;
    }
    
    int getLiverIndex() const
    {
        return liverIndex;
    }
    
    int getLazyIndex() const
    {
        return lazyIndex;
    }
    int getRoundCnt() const
    {
        return roundCnt;
    }
    vector<Item> getItemVector() const
    {
        return itemVector;
    }
    vector<int> getCourseVector() const
    {
        return courseVector;
    }

    bool haveCourses(int opt) const;
    void schoolPrint();
    void companyPrint();
};

#endif // Player_H
