#ifndef ITEM_H
//Set to compile only once, as continuous inclusion may result in redundant compilation.
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    string itemName;
    int itemNum;
    int attackAddCnt;
    int healthAddCnt;

public:
    Item(int itemNum);
    ~Item();
    string getItemName();
    int getAttackAddCnt();
    int getHealthAddCnt();
    void showItemInfo();
};

#endif // ITEM_H
