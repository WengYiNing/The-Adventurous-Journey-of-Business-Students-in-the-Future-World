#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "Company.h"
#include "ConsultingCompany.h"
#include "SecuritiesCompany.h"
#include "DataCompany.h"
#include "Campus.h"
#include "CampusLoc.h"
using namespace std;

class Game
{
private:
    Player player;
    Campus campus;
    ConsultingCompany* consultingcompany;
    SecuritiesCompany* securitiescompany;
    DataCompany* datacompany;
    int& runOrNot;
public:
    Game(const string& n, int& runOrNot) : player(n), runOrNot(runOrNot), campus()
    {
        consultingcompany = nullptr;
        securitiescompany = nullptr;
        datacompany = nullptr;
    }
    ~Game()
    {
        delete consultingcompany;
        delete securitiescompany;
        delete datacompany;
    }
    void introduction1();
    void introduction2();
    void switchLocation();
    void selectLocation();
    void selectCompany();
    void gameEnd();
};

#endif // GAME_H