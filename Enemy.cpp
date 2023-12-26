#include <iostream>
#include <string>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

Enemy::Enemy() : Character() {}

Enemy::Enemy(const string& n) : Character(n) {}

Enemy::Enemy(const string& n, int h) : Character(n)
{
    this->health = h;
}

Enemy::Enemy(const string& n, int at, int h) : Character(n)
{
    this->attackIndex = at;
    this->health = h;
}

void Enemy::attack(Character& target)
{
    target.setHealth(target.getHealth() - this->attackIndex);
}


void Enemy::print()
{
    cout << getName() << endl;
    cout << "Attack index:" << getAttackIndex() << endl;
    cout << "Health:" << getHealth() << endl;
}

void Enemy::print(int atorh)
{
    cout << getName() << endl;
    if(atorh == 0)
        cout << "Attack index:" << getAttackIndex() << endl;
    else
        cout << "Health:" << getHealth() << endl;
}
