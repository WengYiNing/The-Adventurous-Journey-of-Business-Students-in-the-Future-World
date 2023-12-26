//
//  Company.cpp
//  程式設計期末專案
//
//  Created by 翁翊寧 on 2023/12/9.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Character.h"
#include "Company.h"
#include "Player.h"
using namespace std;

bool generateRandomBoolean()
{
    // Use std::random_device as the seed
    std::random_device rd;

    // Use std::mt19937 as the generator; you can use other generators
    std::mt19937 gen(rd());

    // Use std::uniform_int_distribution to generate 0 or 1
    std::uniform_int_distribution<> dis(0, 1);

    // Generate a boolean value
    return dis(gen) == 1;
}

// Constructor that takes company name and main character information
Company::Company(string n, Player &m) : name(n)
{
    mainCharacter = m;
}

Company::Company() : name("")
{
}

Company::Company(const Company &c)
{
    name = c.name;
}

void Company::operator=(const Company &c)
{
    name = c.name;
}

Company::~Company()
{
}
