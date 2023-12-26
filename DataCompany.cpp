#include <iostream>
#include <cstdio>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cstring>
#include <cstdlib>
#include "Character.h"
#include "Company.h"
#include "Enemy.h"
#include "Player.h"
#include "DataCompany.h"
using namespace std;

// bool generateRandomBoolean()
// {
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(0, 1);
//     return dis(gen) == 1;
// }


bool checkHealth(Character const &c)
{
    if(c.getHealth() <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool checkFinalHealth(Player const &p , Enemy const &e)
{
    if(p.getHealth() >= e.getHealth())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Problem::print()
{
    cout << question << "\n";
    cout << ansA << " " << ansB << " " << ansC << " " << ansD << endl;
}

DataCompany::DataCompany():Company(){}

DataCompany::DataCompany(string n, Player &mainCharater) : Company(n, mainCharater)
{
    calculateAbility();
}

void DataCompany::calculateAbility()
{
    // Calculate the main character's ability points
    int player_attack = (mainCharacter.getProgramSkill() * programSkillindex + mainCharacter.getQuantSkill() * quantSkillindex + mainCharacter.getCommuSkill() * commuSkillindex) / 5;
    int player_health = mainCharacter.getProgramSkill() * programSkillindex + mainCharacter.getQuantSkill() * quantSkillindex + mainCharacter.getCommuSkill() * commuSkillindex;
    int itemAttack = 0;
    int itemHealth= 0;
    
    for(int i = 0; i < mainCharacter.getItemVector().size(); i++)
    {
        itemAttack += mainCharacter.getItemVector()[i].getAttackAddCnt();
        itemHealth += mainCharacter.getItemVector()[i].getHealthAddCnt();
    }
    mainCharacter.setAttackIndex(player_attack + itemAttack);
    mainCharacter.setHealth(player_health + itemHealth);
}

bool DataCompany::pretest()
{
    char continueKey;

    cout << "HR: Welcome to the interview for the Data Analysis Intern position! Before we start the interview, let's assess if your abilities meet our requirements." << "\n" << "(Press Enter to continue)";
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cin.get(continueKey);

    while(continueKey != '\n')
    {
        cin.get(continueKey);
    }

    // 確認能力值
    if(mainCharacter.getProgramSkill() >= 30 || mainCharacter.getQuantSkill() >= 60 || mainCharacter.getCommuSkill() >= 30)
    {
        cout << "HR: It looks like your ability points meet our requirements. Next, we will conduct three rounds of interviews. Good luck!" << "\n" << "(Press Enter to continue)";
        cout << "--------------------------------" << "\n";
        return true;
    }
    else
    {
        cout << "HR: Unfortunately, your ability points don't meet our requirements. We regret to inform you that you won't proceed to the next round. We recommend improving your Programming Skill, Quantitative Skill, and Communication Skill." << "\n";
        cout << "--------------------------------" << "\n";
        return false;
    }
}



bool DataCompany::interview1()
{
    char continueKey;
    char playAns;
    int score = 0;

    cout << "HR: Let's start the first written test. If you achieve a certain score, you can proceed to the next round. Good luck!" << "\n" << "(Press Enter to continue)";
    
    cin.get(continueKey);

    while(continueKey != '\n')
    {
        cin.get(continueKey);
    }

    cout << "--------------------------------" << "\n";
    
    Problem list[5] = {aQ1, aQ2, aQ3, aQ4, aQ5};
    

    for(int i = 0;i < 5;i++)
    {
        list[i].print();
        cin.get(playAns);
        if(tolower(playAns) == list[i].ans){
            score += 20;
        }
    }

    cout << "Your score is " << score << "\n";
    if(score >= 60)
    {
        cout << "HR: Congratulations on passing the first written test! Now, let's move on to the second interview." << "\n";
        cout << "--------------------------------" << "\n";
        return true;
    }
    else
    {
        cout << "HR: Unfortunately, you didn't pass the first written test. We can't proceed with the next round. We hope to see you again in the future." << "\n";
        cout << "--------------------------------" << "\n";
        return false;
    }
}

bool DataCompany::interview2()
{
    char continueKey;
    char playAns;

    Enemy seniorDataAnalyst("seniorDataAnalyst", seniorDataAnalyAttack, seniorDataAnalyHealth);

    cout << "人HR: The second interview will test your data analysis skills. The interview will be conducted in teams. You need to provide the correct answers together." << "\n" << "Successfully answering deducts the life points equivalent to the data analyst's attack index. Incorrect answers deduct your own health." <<"\n";
    cout << "人HR: Alternatively, you can let your team member answer. Similarly, a correct answer deducts the data analyst's health. An incorrect answer deducts your own health." << "\n" << "If you're ready, let's get started!" << "\n" << "(Press Enter to continue)";;
    
    cin.get(continueKey);

    while(continueKey != '\n')
    {
        cin.get(continueKey);
    }

    cout << "--------------------------------" << "\n";

    Problem list[5] = {bQ1, bQ2, bQ3, bQ4, bQ5};

    for(int i = 0; i < 5; i++)
    {
        list[i].print();
        cin.get(playAns);
        if(tolower(playAns) == list[i].ans){
            mainCharacter.attack(seniorDataAnalyst);
            cout << "Senior Analyst: Congratulations on the correct answer." << "\n";
        }
        else{
            mainCharacter.hurt(seniorDataAnalyst.getAttackIndex());
            cout << "Senior Analyst: You answered incorrectly. Please try harder." << "\n";
        }

        cout << "--------------------------------" << "\n";

        mainCharacter.companyPrint();
        cout << "\n" << "--------------------------------" << "\n";
        seniorDataAnalyst.print();
        cout << "\n" << "--------------------------------" << "\n";

        if(!checkHealth(mainCharacter)){
            cout << "Senior Analyst: Unfortunately, you didn't pass the second interview. We can't proceed with the next round. Hope to see you next time." << "\n";
            return false;
        }
        else if(!checkHealth(seniorDataAnalyst)){
            cout << "Senior Analyst: Congratulations on passing this round! Continue to the next round." << "\n";
            return true;
        }
        else{
            cout << "Senior Analyst: Let's move on to the next question." << "\n";
        }
        cout << "--------------------------------";
    }
    if(checkFinalHealth(mainCharacter, seniorDataAnalyst))
    {
        cout << "Senior Analyst: Congratulations on passing this round! Continue to the next round." << "\n";
        cout << "--------------------------------" << "\n";
        return true;
    }
    else
    {
        cout << "Senior Analyst: Unfortunately, you didn't pass the second interview. We can't proceed with the next round. Hope to see you next time." << "\n";
        cout << "--------------------------------" << "\n";
        return false;
    }
}

bool DataCompany::interview3()
{
    Enemy dataTeamBoss("dataTeamBoss", dataTeamBossAttack, dataTeamBossHealth);
    Enemy student1("student1", studentAttack, studentHealth);
    Enemy student2("student2", studentAttack, studentHealth);

    char continueKey;
    char playAns;
    
    cout << "HR: Congratulations on passing the second interview! The final interview will be conducted by our Data Team Supervisor, along with two other candidates." << "\n" ;
    cout << "HR: You'll need to compete with the other two candidates, answering questions in turns. A correct answer deducts health equal to the opponent's and your attack index. An incorrect answer results in the supervisor deducting your health. If your answer is stolen, other candidates will deduct your health." << "\n";
    cout << "HR: Successfully defeat your opponents before the five questions end, and you'll receive the final offer. If you're ready, let's get started. Good luck! You're almost there!" << "\n" << "(Press Enter to continue)";
    
    cin.get(continueKey);

    while(continueKey != '\n')
    {
        cin.get(continueKey);
    }

    cout << "--------------------------------" << "\n";

    Problem list[5] = {cQ1, cQ2, cQ3, cQ4, cQ5};

    // Set the timeout to 8000 milliseconds (8 seconds)
    const auto timeout = chrono::milliseconds(8000);

    for(int i = 0; i < 5; i++)
    {
        list[i].print();
        auto userInputStartTime = chrono::system_clock::now();
        cin.get(playAns);
        auto userInputEndTime = chrono::system_clock::now();

        // Calculate user input time
        if(userInputEndTime - userInputStartTime >= timeout)
        {
            cout << "Other candidates have stolen the answer" << "\n";
            mainCharacter.hurt(dataTeamBoss.getAttackIndex());
            mainCharacter.hurt(student1.getAttackIndex());
        }
        else
        {
            if(tolower(playAns) == list[i].ans)
            {
                mainCharacter.attack(dataTeamBoss);
                cout << "Supervisor: Fast and accurate response, excellent!" << "\n";
            }
            else
            {
                mainCharacter.hurt(dataTeamBoss.getAttackIndex());
                cout << "Supervisor: Incorrect answer. Please try harder." << "\n";
            }
        }
        cout << "--------------------------------" << "\n";
            
        mainCharacter.companyPrint();
        cout << "\n" << "--------------------------------" << "\n";
        dataTeamBoss.print();
        cout << "\n" << "--------------------------------" << "\n";

        if(!checkHealth(mainCharacter))
        {
            cout << "Supervisor: Unfortunately, you didn't pass the third interview, but you were very close to success. Hope to see you next time." << "\n";
            return false;
        }
        else if(!checkHealth(dataTeamBoss))
        {
            cout << "Supervisor: Congratulations on passing this round and receiving the offer! Let's work together and learn from each other starting today!" << "\n";
            return true;
        }
        else
        {
            cout << "Supervisor: Continue to the next question." << "\n";
        }
        cout << "--------------------------------" << "\n";
    }
    if(checkFinalHealth(mainCharacter, dataTeamBoss))
    {
        cout << "Supervisor: Congratulations on passing this round and receiving the offer! Let's work together and learn from each other starting today!" << "\n";
        cout << "--------------------------------" << "\n";
        return true;
    }
    else
    {
        cout << "Supervisor: Unfortunately, you didn't pass the third interview, but you were very close to success. Hope to see you next time." << "\n";
        cout << "--------------------------------" << "\n";
        return false;
    }
}
