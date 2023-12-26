#ifndef CAMPUS_H
#define CAMPUS_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "CampusLoc.h"
#include "Player.h"
using namespace std;

class Campus
{
private:
    CampusLoc *locList[10];
    int roundCnt;

public:
    Campus();
    ~Campus();
    void playLoc(int locNum, Player *player);
    int getRoundCnt() const;
};

#endif // CAMPUS_H

