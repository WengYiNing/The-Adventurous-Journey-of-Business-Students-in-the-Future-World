//
//  Company.h
//  程式設計期末專案
//
//  Created by 翁翊寧 on 2023/12/7.
//

#ifndef Company_h
#define Company_h

#include <iostream>
#include <string>
#include <random>
#include "Character.h"
#include "Player.h"
using namespace std;

bool generateRandomBoolean();
// {
//     // Use std::random_device as the seed
//     std::random_device rd;

//     /// Use std::mt19937 as the generator; you can use other generators
//     std::mt19937 gen(rd());

//     // Use std::uniform_int_distribution to generate 0 or 1
//     std::uniform_int_distribution<> dis(0, 1);

//     // Generate a boolean value
//     return dis(gen) == 1;
// }

class Company
{
protected:
    string name;
    Player mainCharacter;
public:
    //Constructor that takes company name and main character information,
    //and sets the main character as the first character in the characterArray
    Company(string n, Player &m);
    Company();
    Company(const Company &c);
    void operator=(const Company &c);
    ~Company();
};


#endif /* Company_h */


