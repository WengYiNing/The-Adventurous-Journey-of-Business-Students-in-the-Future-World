#ifndef CAMPUSLOC_H
#define CAMPUSLOC_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include "Player.h"
#include "Item.h"
using namespace std;

class CampusLoc
{
private:
    int locNum;
    string locName;
    string fullLocName;
    string host;
    string header;
    string regulation;
    string rewardIntro;
    int correctCnt;
    Item *locItem;

    int questionCnt;
    string question[5];
    string choice[5][4];
    int answer[5];

    int effectCnt;
    string capabName[3];
    int capabNum[3];
    int capabWeight[3];

public:
    CampusLoc(int locNum, string locName, string fullLocName, string host, int questionCnt, int effectCnt);
    ~CampusLoc();
    void setCapab(int num, int weight, string name);
    void setCapab(int num1, int weight1, string name1, int num2, int weight2, string name2);
    void setCapab(int num1, int weight1, string name1, int num2, int weight2, string name2, int num3, int weight3, string name3);
    int getLocNum() const;
    void showLocInfo() const;
    void run(Player *player);
};

#endif // CAMPUSLOC_H