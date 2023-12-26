//
//  ConsultingCompany.h
//  程式設計期末專案
//
//  Created by 翁翊寧 on 2023/12/12.
//

#ifndef ConsultingCompany_h
#define ConsultingCompany_h

#include <iostream>
#include <string>
#include <random>
#include "Character.h"
#include "Company.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

// bool generateRandomBoolean();
// {
//     // Use std::random_device as the seed
//     std::random_device rd;

//     // Use std::mt19937 as the generator; other generators can be used
//     std::mt19937 gen(rd());

//     // Use std::uniform_int_distribution to generate 0 or 1
//     std::uniform_int_distribution<> dis(0, 1);

//     // Generate a boolean value
//     return dis(gen) == 1;
// }

class ConsultingCompany : public Company
{
private:
    int itemAttackInt;
    int itemHealthInt;

public:
    ConsultingCompany(string n, Player &m);
    ConsultingCompany();
    bool whetherEnter();
    bool consultingCompanyRun();
    void introduction1();
    bool groupInterview();
    void introduction2();
    bool englishInterview();
    void introduction3();
    bool finalInterview();
    void offer();
};

#endif /* ConsultingCompany_h */
