#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

Item::Item(int itemNum)
{
    this->itemNum = itemNum;
    if (itemNum == 0)
    {
        this->itemName = "Project Work";
        this->attackAddCnt = 30;
        this->healthAddCnt = 0;
    }
    else if (itemNum == 1)
    {
        this->itemName = "International Exchange Certificate";
        this->attackAddCnt = 20;
        this->healthAddCnt = 0;
    }
    else if (itemNum == 2)
    {
        this->itemName = "Referral Opportunity";
        this->attackAddCnt = 0;
        this->healthAddCnt = 100;
    }
    else
    {
        this->itemName = "Straightforward Advice";
        this->attackAddCnt = 0;
        this->healthAddCnt = 150;
    }
}
Item::~Item() {}
string Item::getItemName()
{
    return itemName;
}
int Item::getAttackAddCnt()
{
    return attackAddCnt;
}
int Item::getHealthAddCnt()
{
    return healthAddCnt;
}
void Item::showItemInfo()
{
    cout << itemName << ": Add " << attackAddCnt << " Attack, " << healthAddCnt << " Health." << endl;
}
