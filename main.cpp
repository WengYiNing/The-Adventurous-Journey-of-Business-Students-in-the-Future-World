#include <iostream>
#include <cstdio>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
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
#include "Game.h"
using namespace std;

int main()
{
    string name;
    cout << "Please enter your name:";
    cin >> name;
    int runOrNot = 1;
    Game game(name, runOrNot);

    game.introduction1();
    cin.get();
    game.introduction2();
    cin.get();

    while(runOrNot)
    {
        game.switchLocation();
    }

    return 0;
}
