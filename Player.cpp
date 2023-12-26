#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
using namespace std;

Player::Player() : Character()
{
    finKnowledge = 0;
    quantSkill = 0;
    commuSkill = 0;
    programSkill = 0;
    liverIndex = 0;
    lazyIndex = 0;
    roundCnt = 0;
}
Player::Player(const string& n) : Character(n) 
{
    finKnowledge = 0;
    quantSkill = 0;
    commuSkill = 0;
    programSkill = 0;
    liverIndex = 0;
    lazyIndex = 0;
    roundCnt = 0;
}
Player::Player(const Player& p) : Character(p)
{
    finKnowledge = p.finKnowledge;
    quantSkill = p.quantSkill;
    commuSkill = p.commuSkill;
    programSkill = p.programSkill;
    liverIndex = p.liverIndex;
    lazyIndex = p.lazyIndex;
    itemVector = p.itemVector;
    roundCnt = p.roundCnt;
}

void Player::operator=(const Player& p)
{
    Character::operator=(p);
    finKnowledge = p.finKnowledge;
    quantSkill = p.quantSkill;
    commuSkill = p.commuSkill;
    programSkill = p.programSkill;
    liverIndex = p.liverIndex;
    lazyIndex = p.lazyIndex;
    itemVector = p.itemVector;
    roundCnt = p.roundCnt;
}

void Player::addItem(const Item& item)
{
    itemVector.push_back(item);
}
void Player::addCapab(int capab, int addnum)
{
    switch(capab)
    {
        case 0:
            addfinKnowledge(addnum);
            break;
        case 1:
            addquantSkill(addnum);
            break;
        case 2:
            addcommuSkill(addnum);
            break;
        case 3:
            addprogramSkill(addnum);
            break;
        case 4:
            addliverIndex(addnum);
            break;
        case 5:
            addlazyIndex(addnum);
            break;
        default:
            throw("The capab is not in the range of 1 to 6");
    }
}

void Player::addCourse(int course)
{
    courseVector.push_back(course);
}

void Player::addRoundCnt(int round)
{
    roundCnt += round;
}

void Player::addfinKnowledge(int fk) {
    try 
    {
        finKnowledge += fk;
        if (finKnowledge > 100 || finKnowledge < 0) 
        {
            throw std::out_of_range("The player's finKnowledge is out of the range.");
        } 
    } 
    catch (const std::out_of_range& e) 
    {
        if (finKnowledge > 100) 
        {
            finKnowledge = 100;
        } 
        else 
        {
            finKnowledge = 0;
        }
    }
}

void Player::addquantSkill(int qs)
{
    try
    {
        quantSkill += qs;
        if(quantSkill > 100 || quantSkill < 0)
        {
            throw std::out_of_range("The player's quantSkill is out of the range.");
        }
    }
    catch(const std::out_of_range& e)
    {
        if(quantSkill > 100)
        {
            quantSkill = 100;
        }
        else
        {
            quantSkill = 0;
        }
    
    }
}
void Player::addcommuSkill(int cs)
{
    try
    {
        commuSkill += cs;
        if(commuSkill > 100 || commuSkill < 0)
        {
            throw std::out_of_range("The player's commuSkill is out of the range.");
        }
    }
    catch(const std::out_of_range& e)
    {
        if(commuSkill > 100)
        {
            commuSkill = 100;
        }
        else
        {
            commuSkill = 0;
        }
    }
}
void Player::addprogramSkill(int ps)
{
    try
    {
        programSkill += ps;
        if(programSkill > 100 || programSkill < 0)
        {
            throw std::out_of_range("The player's programSkill is out of the range.");
        }
    }
    catch(const std::out_of_range& e)
    {
        if(programSkill > 100)
        {
            programSkill = 100;
        }
        else
        {
            programSkill = 0;
        }
    }
}
void Player::addliverIndex(int li)
{
    try
    {
        liverIndex += li;
        if(liverIndex > 100 || liverIndex < 0)
        {
            throw std::out_of_range("The player's liverIndex is out of the range.");
        }
    }
    catch(const std::out_of_range& e)
    {
        if(liverIndex > 100)
        {
            liverIndex = 100;
        }
        else
        {
            liverIndex = 0;
        }
    }
}
void Player::addlazyIndex(int li)
{
    try
    {
        lazyIndex += li;
        if(lazyIndex > 100 || lazyIndex < 0)
        {
            throw std::out_of_range("The player's lazyIndex is out of the range.");
        }
    }
    catch(const std::out_of_range& e)
    {
        if(lazyIndex > 100)
        {
            lazyIndex = 100;
        }
        else
        {
            lazyIndex = 0;
        }
    } 
}

void Player::attack(Character& target)
{
    //If compilation is not possible, please modify it to call enemy.hurt.
    target.setHealth(target.getHealth() - this->getAttackIndex());
}
void Player::hurt(int damage)
{
    this->setHealth(this->getHealth() - damage);
}

bool Player::haveCourses(int opt) const{
    for(int i = 0; i < courseVector.size(); i++){
        if(opt - 1 == courseVector[i]){
            return true;
        }
    }
    return false;
}
void Player::schoolPrint()
{
    cout << "Name: " << getName() << endl;
    cout << "Finance Knowledge: " << getFinKnowledge() << endl;
    cout << "Quantitative Skill: " << getQuantSkill() << endl;
    cout << "Communication Skill: " << getCommuSkill() << endl;
    cout << "Programming Skill: " << getProgramSkill() << endl;
    cout << "Liver Index: " << getLiverIndex() << endl;
    cout << "Lazy Index: " << getLazyIndex() << endl;
}
void Player::companyPrint()
{
    cout << "Name: " << getName() << endl;
    cout << "Atteck Index: " << getAttackIndex() << endl;
    cout << "Health: " << getHealth() << endl;
}
