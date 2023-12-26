#include <iostream>
#include <cstring>
#include <fstream>
#include "Campus.h"
#include "CampusLoc.h"
#include "Player.h"

using namespace std;

Campus::Campus()
{
    for (int i = 0; i < 10; i++)
        locList[i] = nullptr;

    this->locList[0] = new CampusLoc(0, "ntuHospital", "NTU Hospital", "Professor Kuo", 0, 2);
    this->locList[1] = new CampusLoc(1, "derTianHall", "Der Tian Hall", "Professor in Department of Computer Science", 5, 3);
    this->locList[2] = new CampusLoc(2, "manageLib", "College of Management Library", "Sam Smith", 2, 3);
    this->locList[3] = new CampusLoc(3, "manageHall1_1", "Building 1, College of Management 1", "Professor in Department of Finance", 3, 2);
    this->locList[4] = new CampusLoc(4, "manageHall1_2", "Building 1, College of Management 2", "Professor in Department of Business Administration", 3, 2);
    this->locList[5] = new CampusLoc(5, "manageHall1_3", "Building 1, College of Management 3", "Professor Kong Lingjie", 5, 3);
    this->locList[6] = new CampusLoc(6, "manageHall2_1", "Building 2 , College of Management 1", "Professor in Department of International Business", 2, 3);
    this->locList[7] = new CampusLoc(7, "manageHall2_2", "Building 2 , College of Management 2", "Professor in Department of Accounting", 2, 2);
    this->locList[8] = new CampusLoc(8, "computerCen", "Computer and Information Networking Center", "Aunt Computer and Information Networking Center", 5, 3);
    this->locList[9] = new CampusLoc(9, "newStadium", "Sports Center", "Coach", 3, 2);

    (this->locList[0])->setCapab(4, -60, "Liver Index", 5, 10, "Lazy Index");
    (this->locList[1])->setCapab(2, -1, "Communication Skill", 3, 12, "Programming Skill", 4, 5, "Liver Index");
    (this->locList[2])->setCapab(2, 20, "Communication Skill", 4, -8, "Liver Index", 5, 20, "Lazy Index");
    (this->locList[3])->setCapab(0, 15, "Finance Knowledge", 1, 20, "Quantitative Skill");
    (this->locList[4])->setCapab(1, 20, "Quantitative Skill", 2, 7, "Communication Skill");
    (this->locList[5])->setCapab(3, 10, "Programming Skill", 4, 3, "Liver Index", 5, 1, "Lazy Index");
    (this->locList[6])->setCapab(0, 10, "Finance Knowledge", 1, 15, "Quantitative Skill", 2, 15, "Communication Skill");
    (this->locList[7])->setCapab(0, 15, "Finance Knowledge", 2, 5, "Communication Skill");
    (this->locList[8])->setCapab(3, 15, "Programming Skill", 4, 8, "Liver Index", 5, -5, "Lazy Index");
    (this->locList[9])->setCapab(4, -10, "Liver Index", 5, -5, "Lazy Index");
    roundCnt = 0;
}
Campus::~Campus()
{
    for (int i = 0; i < 10; i++)
        delete locList[i];
}
void Campus::playLoc(int locNum, Player *player)
{
    (this->locList[locNum])->run(player);
    roundCnt++;
    player->addRoundCnt(1);
    player->addCourse((this->locList[locNum])->getLocNum());
}
int Campus::getRoundCnt() const
{
    return roundCnt;
}
