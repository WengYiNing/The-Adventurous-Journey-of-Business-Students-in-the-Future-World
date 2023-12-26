#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Company.h"
#include "SecuritiesCompany.h"
using namespace std;

void Question::print()
{
    cout << question << endl;
    cout << choiceA << endl << choiceB << endl << choiceC << endl;
}

bool Question::checkInput(string& n)
{
    string choices = "ABC";
    if(choices.find(n) == string::npos)
        return false;
    return true;
}

SecuritiesCompany::SecuritiesCompany() : Company() {}

SecuritiesCompany::SecuritiesCompany(string n, Player& mainCharater) : Company(n, mainCharater)
{
    int baseHealth = mainCharacter.getFinKnowledge() * 2 + mainCharacter.getQuantSkill() * 2 + mainCharacter.getProgramSkill() * 1 - mainCharacter.getLiverIndex() / 5 - mainCharacter.getLazyIndex();
    int baseAttack = (mainCharacter.getFinKnowledge() * 2 + mainCharacter.getQuantSkill() * 2 + mainCharacter.getProgramSkill() * 1) / 5;
    int itemHealth = 0;
    int itemAttack = 0;
    vector<Item> itemList = mainCharacter.getItemVector();
    for(int i = 0; i < itemList.size(); i++)
    {
        itemHealth += itemList[i].getHealthAddCnt();
        itemAttack += itemList[i].getAttackAddCnt();
    }
    this->initHealth = baseHealth + itemHealth;
    this->mainCharacter.setAttackIndex(baseAttack + itemAttack);
}

void SecuritiesCompany::checkHealth()
{
    if(this->mainCharacter.getHealth() <= 0)
        throw logic_error("Life points zero.");
}

bool SecuritiesCompany::compareWithEnemy(int ensCnt, Enemy ens[])
{
    int maxHealth = - 1;
    for(int i = 0; i < ensCnt; i++)
    {
        if(ens[i].getHealth() > maxHealth)
            maxHealth = ens[i].getHealth();
    }
    if(mainCharacter.getHealth() >= maxHealth)
        return true;
    return false;
}

bool SecuritiesCompany::ifAccepted()
{
    if(this->mainCharacter.getFinKnowledge() < 20 || this->mainCharacter.getQuantSkill() < 20)
    {
        cout << "HR: We regret to inform you that your skills do not meet the requirements of our company. We suggest accumulating more relevant experience before applying again!" << endl;
        cin.get();
        return false;
    }
    else
        return true;
}

void SecuritiesCompany::opening()
{
    // cout << this->mainCharacter.getN
    Enemy hr("HR");
    cout << hr.getName() << ": Hi!" << this->mainCharacter.getName() << "Welcome to " << this->name << ". We are recruiting investment research interns this time. There are three levels in total. We look forward to your performance. Good luck!" << endl << "(Press Enter to continue)";
    cin.get();
}

bool SecuritiesCompany::writtenTest()
{
    this->mainCharacter.setHealth(this->initHealth);

    srand(time(nullptr));

    Enemy hr("HR");

    const int ENS_CNT = 3;

    // Enemy candidates[ENS_CNT];

    Enemy candidateA("Alex", ((rand() % 300)) + 1);
    Enemy candidateB("Bella", ((rand() % 300)) + 1);
    Enemy candidateC("Chris", ((rand() % 300)) + 1);

    Enemy candidates[ENS_CNT] = {candidateA, candidateB, candidateC};

    cout << hr.getName() << ": Firstly, we will conduct a written test to assess your basic financial knowledge. There are five questions in total. Incorrect answers will deduct health. After answering all questions, if your health are higher than other applicants, you will pass this round. If health reach zero, you fail." << endl;
    cout << " Get ready and let's begin! Good luck!" << "(Press Enter to continue)";
    cin.get();

    Question questions[WQ_CNT] = {wQ1, wQ2, wQ3, wQ4, wQ5};

    for(int i = 0; i < WQ_CNT; i++)
    {
        questions[i].print();
        
        string input;
        cin >> input;
        if(input == "a")
            input = "A";
        else if(input == "b")
            input = "B";
        else if(input == "c")
            input = "C";

        while(!questions[i].checkInput(input))
        {
            cout << "Invalid answer. Please re-enter." << endl;
            cin >> input;
            if(input == "a")
                input = "A";
            else if(input == "b")
                input = "B";
            else if(input == "c")
                input = "C";
        }

        if(input == questions[i].answer)
        {
            cout << "Correct answer." << endl <<  "(Press Enter to continue)";
            cin.get();
        }
        else
        {
            this->mainCharacter.hurt(this->mainCharacter.getAttackIndex());
            cout << "Wrong answer." << endl << "(Press Enter to continue)";
            cin.get();
        }

        try
        {
            checkHealth();
        }
        catch(logic_error die)
        {
            this->mainCharacter.setHealth(0);
            this->mainCharacter.companyPrint();
            cout << die.what() << endl;
            cout << hr.getName() << ": Unfortunately, you did not pass this round of the test and cannot proceed to the next interview. Please try again. Looking forward to seeing you next time." << endl << "(Press Enter to continue)";
            cin.get();
            return false;
        }

        this->mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
        cin.get();
    }
    bool pass = this->compareWithEnemy(ENS_CNT, candidates);
    for(int i = 0; i < ENS_CNT; i++)
    {
        candidates[i].print(1);
    }

    if(pass == 0)
    {
        cout << hr.getName() << ": Unfortunately, you did not pass this round of the test and cannot proceed to the next interview. Please try again. Looking forward to seeing you next time." << endl << "(Press Enter to continue)";
        cin.get();
        return false;
    }
    cout << hr.getName() << ": Congratulations! You have passed the written test and will proceed to the first-round interview." << endl << "(Press Enter to continue)";
    cin.get();
    return true;
}

bool SecuritiesCompany::analystInterview()
{
    this->mainCharacter.setHealth(this->initHealth);

    Enemy analyst("Securities Analyst");
    analyst.setAttackIndex(100);

    cout << analyst.getName() << ": " << this->mainCharacter.getName() << ". I'm glad to see you here. I am the analyst here, and if you come in, I will be your direct supervisor." << endl;
    cout << " Now I want to talk to you about investment. I will ask you five questions. If you answer incorrectly, my attack index will reduce your health. Answering correctly will allow you to dodge the attack. If your health are still above zero after answering all questions, you can proceed to the next interview round." << endl;
    cout << " Let's begin!" << endl;
    analyst.print(0);
    cout << "(Press Enter to continue)";
    cin.get();

    Question questions[AQ_CNT] = {iQ1, iQ2, iQ3, iQ4, iQ5};

    for(int i = 0; i < AQ_CNT; i++)
    {
        cout << analyst.getName() << "：";
        questions[i].print();
        
        string input;
        cin >> input;
        if(input == "a")
            input = "A";
        else if(input == "b")
            input = "B";
        else if(input == "c")
            input = "C";

        while(!questions[i].checkInput(input))
        {
            cout << "Invalid answer. Please re-enter." << endl;
            cin >> input;
            if(input == "a")
                input = "A";
            else if(input == "b")
                input = "B";
            else if(input == "c")
                input = "C";
        }

        if(input == questions[i].answer)
        {
            cout << analyst.getName() << ": Congratulations on the correct answer!" << endl <<  "(Press Enter to continue)";
            cin.get();
        }
        else
        {
            analyst.attack(this->mainCharacter);
            cout << analyst.getName() << ": Unfortunately, you answered incorrectly." << endl << "(Press Enter to continue)";
            cin.get();
        }
        
        try
        {
            checkHealth();
        }
        catch(logic_error die)
        {
            this->mainCharacter.setHealth(0);
            this->mainCharacter.companyPrint();
            cout << die.what() << endl;
            cout << analyst.getName() << ": Unfortunately, the interview will end here for now. Please try again. Looking forward to seeing you next time." << endl << "(Press Enter to continue)";
            cin.get();
            return false;
        }
        this->mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
        cin.get();
    }
    cout << analyst.getName() << ": Congratulations on passing this interview round. You will enter the final round shortly. Good luck!" << endl << "(Press Enter to continue)";
    cin.get();
    return true;
}

bool SecuritiesCompany::headsInterview()
{
    this->mainCharacter.setHealth(this->initHealth);

    const int ENS_CNT = 3;
    Enemy twHead("Taiwan Research Department Head", 60, 400);
    Enemy hkHead("Hong Kong Research Department Head", 70, 400);
    Enemy apHead("Asia-Pacific Research Department Head", 80, 400);

    Enemy heads[ENS_CNT] = {twHead, hkHead, apHead};
    
    for(int i = 0; i < ENS_CNT; i++)
    {
        if(i != 0)
            cout << ", ";
        cout << heads[i].getName();
    }
    cout << "：" << this->mainCharacter.getName() << ": Welcome to the final interview! Since you have already gained recognition from our analysts, we won't discuss too professional matters. We just want to get to know you a little better." << endl;
    cout << " We will take turns asking you questions, a total of six questions. Correct answers will reduce our life points with your attack power. Conversely, incorrect answers will deduct your life points with our attack power. If your life points are higher than all three of us at the end, you will pass the interview." << endl;
    cout << " By the way, since we are a foreign securities firm, there will be some English questions later. But I believe you should be fine, right?" << endl;
    cout << " Let's begin!" << "(Press Enter to continue)";
    cin.get();

    Question questions[HQ_CNT] = {hQ1, hQ2, hQ3, hQ4, hQ5, hQ6};

    for(int i = 0; i < HQ_CNT; i++)
    {
        cout << heads[(i % 3)].getName() << "：";
        questions[i].print();
        
        string input;
        cin >> input;
        if(input == "a")
            input = "A";
        else if(input == "b")
            input = "B";
        else if(input == "c")
            input = "C";

        while(!questions[i].checkInput(input))
        {
            cout << "Invalid answer. Please re-enter." << endl;
            cin >> input;
            if(input == "a")
                input = "A";
            else if(input == "b")
                input = "B";
            else if(input == "c")
                input = "C";
        }

        if(input == questions[i].answer)
        {
            this->mainCharacter.attack(heads[(i % 3)]);
            cout << heads[(i % 3)].getName() << ": Great, you got it right!" << endl <<  "(Press Enter to continue)";
            cin.get();
        }
        else
        {
            heads[(i % 3)].attack(this->mainCharacter);
            cout << heads[(i % 3)].getName() << ": Not correct." << endl << "(Press Enter to continue)";
            cin.get();
        }
        
        try
        {
            checkHealth();
        }
        catch(logic_error die)
        {
            this->mainCharacter.setHealth(0);
            this->mainCharacter.companyPrint();
            cout << die.what() << endl;
            for(int i = 0; i < ENS_CNT; i++)
            {
                if(i != 0)
                    cout << ", ";
                cout << heads[i].getName();
            }
            cout << ": Too bad, just a little more, and you could have joined us... Keep up the good work! Looking forward to seeing you next time." << endl << "(Press Enter to continue)";
            cin.get();
            return false;
        }
        this->mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
        cin.get();
    }
    bool pass = this->compareWithEnemy(ENS_CNT, heads);
    for(int i = 0; i < ENS_CNT; i++)
        heads[i].print();

    if(pass == 0)
    {
        for(int i = 0; i < ENS_CNT; i++)
        {
            if(i != 0)
                cout << ", ";
            cout << heads[i].getName();
        }
        cout << ": Too bad, just a little more, and you could have joined us... Keep up the good work! Looking forward to seeing you next time." << endl << "(Press Enter to continue)";;
        cin.get();
        return false;
    }
    for(int i = 0; i < ENS_CNT; i++)
    {
        if(i != 0)
            cout << ", ";
        cout << heads[i].getName();
    }
    cout << ": Congratulations! You have passed all levels and become our intern! Welcome to join our company. Let's work hard together in the future!" << endl << "(Press Enter to continue)";
    cin.get();
    return true;
}
