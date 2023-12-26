#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include "CampusLoc.h"
#include "Player.h"
#include "Item.h"

using namespace std;

CampusLoc::CampusLoc(int locNum, string locName, string fullLocName, string host, int questionCnt, int effectCnt)
{
    this->locNum = locNum;
    this->locName = locName;
    this->fullLocName = fullLocName;
    this->host = host;
    this->questionCnt = questionCnt;
    this->effectCnt = effectCnt;
    for (int i = 0; i < 3; i++)
    {
        capabNum[i] = 0;
        capabWeight[i] = 0;
    }

    int itemNum = locNum % 4;
    this->locItem = new Item(itemNum);

    string fileName = this->locName + ".txt";
    ifstream locFile(fileName);
    if (locFile) // Check if the file actually exists rather than creating a new file
    {
        getline(locFile, this->header);
        getline(locFile, this->regulation);
        getline(locFile, this->rewardIntro);

        for (int i = 0; i < questionCnt; i++)
        {
            getline(locFile, this->question[i]);
            for (int j = 0; j < 4; j++)
                getline(locFile, this->choice[i][j]);

            string ans;
            getline(locFile, ans);
            this->answer[i] = stoi(ans); // 0,1,2,3
        }
    }
    locFile.close();
}
CampusLoc::~CampusLoc() {}
void CampusLoc::setCapab(int num, int weight, string name)
{
    this->capabNum[0] = num;
    this->capabWeight[0] = weight;
    this->capabName[0] = name;
}
void CampusLoc::setCapab(int num1, int weight1, string name1, int num2, int weight2, string name2)
{
    this->capabNum[0] = num1;
    this->capabWeight[0] = weight1;
    this->capabName[0] = name1;
    this->capabNum[1] = num2;
    this->capabWeight[1] = weight2;
    this->capabName[1] = name2;
}
void CampusLoc::setCapab(int num1, int weight1, string name1, int num2, int weight2, string name2, int num3, int weight3, string name3)
{
    this->capabNum[0] = num1;
    this->capabWeight[0] = weight1;
    this->capabName[0] = name1;

    this->capabNum[1] = num2;
    this->capabWeight[1] = weight2;
    this->capabName[1] = name2;

    this->capabNum[2] = num3;
    this->capabWeight[2] = weight3;
    this->capabName[2] = name3;
}

int CampusLoc::getLocNum() const
{
    return this->locNum;
}

void CampusLoc::showLocInfo() const
{
    cout << this->fullLocName << ": " << this->rewardIntro << endl;
}
void CampusLoc::run(Player *player)
{
    cout << "/////////////////////////////////////////////////////" << endl;
    cout << "------------------ " << this->fullLocName << " ------------------" << endl;
    cout << "/////////////////////////////////////////////////////" << endl;
    cout << endl;

    cout << this->host << ": " << this->header << endl;
    cout << "Rules:" << this->regulation << endl;

    cout << "Press Enter to continue" << endl;
    string confirm;
    getline(cin, confirm);

    if (questionCnt > 0)
        int correctCnt = 0;
    else
        cout << "\n";
        int correctCnt = 1;

    for (int i = 0; i < questionCnt; i++)
    {
        cout << this->question[i] << endl;
        cout << "1. " << this->choice[i][0] << endl;
        cout << "2. " << this->choice[i][1] << endl;
        cout << "3. " << this->choice[i][2] << endl;
        cout << "4. " << this->choice[i][3] << endl;
        cout << "Enter your answer and PRESS THE ENTER!" << endl;

        int finish = 0;
        string ans;
        int ansNum = 0;
        while (!finish)
        {
            try
            {
                getline(cin, ans);
                ansNum = stoi(ans);
                if (ansNum > 4 || ansNum < 1)
                    throw out_of_range("invalid input!");
                cout << endl;
            }
            catch (exception e)
            {
                cout << "Please enter a VALID ANSWER!!!";
                continue;
            }
            finish = true;
        }

        if (ansNum == this->answer[i])
        {

            cout << "Excellent!!!" << endl;
            cout << endl;
            correctCnt++;
        }
        else
        {
            cout << "Wrong!!!";
            cout << endl;
        }
    }

    for (int i = 0; i < this->effectCnt; i++)
    {
        int addNum = this->capabWeight[i] * correctCnt;
        cout << this->capabName[i] << " increased by " << addNum << endl;
        player->addCapab(this->capabNum[i], addNum);
    }
    cout << endl;

    if (correctCnt > 0)
    {
        cout << "Completed! Move on to the next challenge!" << endl;
        if (correctCnt == this->questionCnt)
            player->addItem(*(this->locItem));
    }
    else
        cout << "No worries, try again next time!" << endl;

    cout << "------------------ Hope you learned a lot ------------------" << endl;
    cout << endl;
}
