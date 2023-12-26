//
//  consultingCompany.cpp
//  程式設計期末專案
//
//  Created by 翁翊寧 on 2023/12/9.
//

#include <iostream>
#include <string>
#include <random>
#include <cstring>
#include "Character.h"
#include "Company.h"
#include "ConsultingCompany.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

ConsultingCompany::ConsultingCompany(string n, Player &m) : Company(n, m)
{
    itemAttackInt = 0;
    itemHealthInt = 0;

    for (int i = 0; i < mainCharacter.getItemVector().size(); i++)
    {
        itemAttackInt = itemAttackInt + mainCharacter.getItemVector()[i].getAttackAddCnt();
    }

    for (int i = 0; i < mainCharacter.getItemVector().size(); i++)
    {
        itemHealthInt = itemHealthInt + mainCharacter.getItemVector()[i].getHealthAddCnt();
    }

    mainCharacter.setAttackIndex((mainCharacter.getFinKnowledge() * 0.6) + (mainCharacter.getCommuSkill() * 0.6) + itemAttackInt * 0.6);
    mainCharacter.setHealth(mainCharacter.getFinKnowledge() * 2.5 + mainCharacter.getCommuSkill() * 2.5 - mainCharacter.getLiverIndex() * 3 - mainCharacter.getLazyIndex() * 3 + itemHealthInt);
}

ConsultingCompany::ConsultingCompany() : Company()
{
}

bool ConsultingCompany::whetherEnter()
{
    if (mainCharacter.getFinKnowledge() < 30 && mainCharacter.getCommuSkill() < 30)
    {
        cout << "HR: We're sorry, but based on our current evaluation, your resume will not be considered at this time."
             << "\n";
        return false;
    }
    else
        return true;
}

void ConsultingCompany::introduction1()
{
    char continueKey;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "HR: Welcome to our Management Consulting Company. To apply for this position, you must pass three rounds of interviews."
         << "\n"
         << "(Press Enter to continue)";

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: The first round is a group interview with three other candidates. You will answer questions."
             << "\n"
             << "(Press Enter to continue)";
    }

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: Correct answers will deduct health from your opponents equal to your attack index, while incorrect answers will deduct 50 health from you."
             << "\n"
             << "(Press Enter to continue)";
        ;
    }

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: Successfully reducing your opponent's health to zero in five questions will allow you to pass this round of interviews."
             << "\n"
             << "(Press Enter to continue)";
        ;
    }

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: If you're ready, let's begin!"
             << "\n"
             << "(Press Enter to continue)";
    }
}

bool ConsultingCompany::groupInterview()
{
    Enemy student1("Student1", 150);
    Enemy student2("Student2", 200);
    Enemy student3("Student3", 250);
    
    introduction1();

    char continueKey;
    char playAns;
    playAns = 0;

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Consultant: Hello, candidates! I am the interviewer for today. Let's start the first question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Consultant: What is the square of 37?"
             << "\n"
             << "(A)1139 (B)1279 (C)1369 (D)1459"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'c')
    {
        mainCharacter.attack(student1);
        mainCharacter.attack(student2);
        mainCharacter.attack(student3);

        cout << "Consultant: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(50);
        cout << "Consultant: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (student1.getHealth() <=0 && student2.getHealth() <= 0 && student3.getHealth() <= 0)
    {
        cout << "Consultant: Congratulations! You have passed this round of interviews. Keep up the good work!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Consultant: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        student1.print();
        student2.print();
        student3.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Consultant: Let's move on to the second question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Consultant: What is the smallest prime number?"
             << "\n"
             << "(A)0 (B)1 (C)2 (D)3"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'c')
    {
        mainCharacter.attack(student1);
        mainCharacter.attack(student2);
        mainCharacter.attack(student3);

        cout << "Consultant: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(50);
        cout << "Consultant: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (student1.getHealth() <=0 && student2.getHealth() <= 0 && student3.getHealth() <= 0)
    {
        cout << "Consultant: Congratulations! You have passed this round of interviews. Keep up the good work!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Consultant: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        student1.print();
        student2.print();
        student3.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Consultant: Let's move on to the third question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Consultant: Which is the largest country in the world?"
             << "\n"
             << "(A) Russia (B) United States (C) China (D) Canada"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'a')
    {
        mainCharacter.attack(student1);
        mainCharacter.attack(student2);
        mainCharacter.attack(student3);

        cout << "Consultant: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(50);
        cout << "Consultant: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (student1.getHealth() <=0 && student2.getHealth() <= 0 && student3.getHealth() <= 0)
    {
        cout << "Consultant: Congratulations! You have passed this round of interviews. Keep up the good work!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Consultant: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        student1.print();
        student2.print();
        student3.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Consultant: Let's move on to the forth question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Consultant: What is the reciprocal of two?"
             << "\n"
             << "(A) -2 (B) 1/2 (C) 2 (D) 4"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'b')
    {
        mainCharacter.attack(student1);
        mainCharacter.attack(student2);
        mainCharacter.attack(student3);

        cout << "Consultant: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(50);
        cout << "Consultant: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (student1.getHealth() <=0 && student2.getHealth() <= 0 && student3.getHealth() <= 0)
    {
        cout << "Consultant: Congratulations! You have passed this round of interviews. Keep up the good work!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Consultant: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        student1.print();
        student2.print();
        student3.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Consultant: Let's move on to the fifth question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Consultant: What is the height of Jade Mountain?"
             << "\n"
             << "(A) 3673 meters (B) 3725 meters (C) 3894 meters (D) 3952 meters"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'd')
    {
        mainCharacter.attack(student1);
        mainCharacter.attack(student2);
        mainCharacter.attack(student3);

        cout << "Consultant: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(50);
        cout << "Consultant: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (student1.getHealth() <=0 && student2.getHealth() <= 0 && student3.getHealth() <= 0)
    {
        cout << "Consultant: Congratulations! You have passed this round of interviews. Keep up the good work!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else
    {
        cout << "Consultant: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }
}

void ConsultingCompany::introduction2()
{
    char continueKey;

    mainCharacter.setHealth(mainCharacter.getLiverIndex() * 2 + mainCharacter.getLazyIndex() * 2 + itemHealthInt);

    cout << "HR: Congratulations on passing the first round of interviews!"
         << "\n"
         << "(Press Enter to continue)";

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: For the second round, we will assess your English proficiency. You will engage in an English dialogue with a senior consultant, and you need to select the correct responses."
             << "\n"
             << "(Press Enter to continue)";
    }

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: Similarly, providing correct answers will deduct the senior consultant's health equivalent to your attack index, while incorrect answers will deduct 60 points from your own health."
             << "\n"
             << "(Press Enter to continue)";
        ;
    }

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: Successfully reducing the opponent's health to zero before the end of five questions will allow you to pass this round of interviews."
             << "\n"
             << "(Press Enter to continue)";
        ;
    }

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: If you're ready, let's get started!"
             << "\n"
             << "(Press Enter to continue)";
    }
}

bool ConsultingCompany::englishInterview()
{
    Enemy seniorConsultant("Senior Consultant", 350);
    
    introduction2();

    char continueKey;
    char playAns;
    playAns = 0;

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Senior Consultant: Hello, I am the interviewer for this round. Let's begin our conversation."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Senior Consultant: Hi, which company do you interview today?"
             << "\n"
             << "(A)Consulting company (B)Investment banking"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'a')
    {
        mainCharacter.attack(seniorConsultant);

        cout << "Senior Consultant: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(60);
        cout << "Senior Consultant: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (seniorConsultant.getHealth() <= 0)
    {
        cout << "Senior Consultant: Congratulations! You have passed this round of interviews. Keep up the good work!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Senior Consultant: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        seniorConsultant.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Senior Consultant: Let's move on to the second question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Senior Consultant: How do you solve a difficult problem generally？"
             << "\n"
             << "(A)solve it just on my own (B)team work"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'b')
    {
        mainCharacter.attack(seniorConsultant);

        cout << "Senior Consultant: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(60);
        cout << "Senior Consultant: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (seniorConsultant.getHealth() <= 0)
    {
        cout << "Senior Consultant: Congratulations! You have passed this round of interviews. Keep up the good work!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Senior Consultant: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        seniorConsultant.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Senior Consultant: Let's move on to the third question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Senior Consultant: What is the core skill in a consulting company？"
             << "\n"
             << "(A)logical thinking (B)singing"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'a')
    {
        mainCharacter.attack(seniorConsultant);

        cout << "Senior Consultant: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(60);
        cout << "Senior Consultant: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (seniorConsultant.getHealth() <= 0)
    {
        cout << "Senior Consultant: Congratulations! You have passed this round of interviews. Keep up the good work!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Senior Consultant: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        seniorConsultant.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Senior Consultant: Let's move on to the forth question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Senior Consultant: How do you deal with the conflict between you and your supervisor？"
             << "\n"
             << "(A)Communication (B)Fight"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'a')
    {
        mainCharacter.attack(seniorConsultant);

        cout << "Senior Consultant: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(60);
        cout << "Senior Consultant: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (seniorConsultant.getHealth() <= 0)
    {
        cout << "Senior Consultant: Congratulations! You have passed this round of interviews. Keep up the good work!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Senior Consultant: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        seniorConsultant.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Senior Consultant: Let's move on to the fifth question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Senior Consultant: Which company is our competitior？"
             << "\n"
             << "(A)Mckinsey (B)P&G"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'a')
    {
        mainCharacter.attack(seniorConsultant);

        cout << "Senior Consultant: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(60);
        cout << "Senior Consultant: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (seniorConsultant.getHealth() <= 0)
    {
        cout << "Senior Consultant: Congratulations! You have passed this round of interviews. Keep up the good work!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else
    {
        cout << "Senior Consultant: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }
}

void ConsultingCompany::introduction3()
{
    char continueKey;

    mainCharacter.setHealth(mainCharacter.getLiverIndex() * 2 + mainCharacter.getLazyIndex() * 2 + itemHealthInt);

    cout << "HR: Congratulations, you have passed the second round of interviews!"
         << "\n"
         << "(Press Enter to continue)";

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: The final round of interviews will be conducted by our partner, and there will also be another overseas returnee applicant from a foreign university."
             << "\n"
             << "(Press Enter to continue)";
    }

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: You will take turns answering questions with the other applicant. Correct answers will deduct the opponent's health equal to your attack index and your own health by 70 points for incorrect answers. The rules apply to both sides."
             << "\n"
             << "(Press Enter to continue)";
        ;
    }

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: If you manage to defeat your opponent before the conclusion of the five questions, you will be eligible for the final offer."
             << "\n"
             << "(Press Enter to continue)";
        ;
    }

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "HR: If you're ready, let's begin. Your opponent this time is quite formidable!"
             << "\n"
             << "(Press Enter to continue)";
    }
}

bool ConsultingCompany::finalInterview()
{
    Enemy overseaStudent("oversea student", 85, 450);
    
    introduction3();

    char continueKey;
    char playAns;
    playAns = 0;

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Hello, I am a partner at this company. Let's begin the final interview."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Oversea student: Sure, no problem!"
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Excellent. Let's start with the candidate who returned from abroad."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Can you name the five components of Michael Porter's Five Forces Analysis?"
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (generateRandomBoolean())
    {
        cout << "（Oversea student answered correctly.）"
             << "\n"
             << "(Press Enter to continue)";
        overseaStudent.attack(mainCharacter);
    }
    else
    {
        cout << "（Oversea student answered wrongly.）"
             << "\n"
             << "(Press Enter to continue)";
        overseaStudent.hurt(70);
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Now, it's your turn."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Before solving problems, what do consultants most commonly establish?"
             << "\n"
             << "(A) Hypothesis (B) Fallacy (C) Advocacy (D) Experiment"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'a')
    {
        mainCharacter.attack(overseaStudent);

        cout << "Partner: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(70);
        cout << "Partner: Incorrect. Don't worry." << "\n" << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (overseaStudent.getHealth() <= 0)
    {
        cout << "Partner: Congratulations, you have passed this final interview!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Partner: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        overseaStudent.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Now, let's have the oversea student answer the next question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Can you list the four dimensions of SWOT analysis?"
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (generateRandomBoolean())
    {
        cout << "（Oversea student answered correctly.）"
             << "\n"
             << "(Press Enter to continue)";
        overseaStudent.attack(mainCharacter);
    }
    else
    {
        cout << "（Oversea student answered wrongly.）"
             << "\n"
             << "(Press Enter to continue)";
        overseaStudent.hurt(70);
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Now, it's your turn."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Which of the following is not one of the four major financial statements?"
             << "\n"
             << "(A) Balance Sheet (B) Statement of Cash Flows (C) Statement of Changes in Equity (D) Company Securities Statement"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'd')
    {
        mainCharacter.attack(overseaStudent);

        cout << "Partner: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(70);
        cout << "Partner: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (overseaStudent.getHealth() <= 0)
    {
        cout << "Partner: Congratulations, you have passed this final interview!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Partner: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        overseaStudent.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Now, let's have the oversea student answer the next question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Please provide one method for valuing a company."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (generateRandomBoolean())
    {
        cout << "（Oversea student answered correctly.）"
             << "\n"
             << "(Press Enter to continue)";
        overseaStudent.attack(mainCharacter);
    }
    else
    {
        cout << "（Oversea student answered wrongly.）"
             << "\n"
             << "(Press Enter to continue)";
        overseaStudent.hurt(70);
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Now, it's your turn."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: What is the English abbreviation for Structured Query Language?"
             << "\n"
             << "(A)SPL (B)SQL (C)HPL (D)HQL"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'b')
    {
        mainCharacter.attack(overseaStudent);

        cout << "Partner: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(70);
        cout << "Partner: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (overseaStudent.getHealth() <= 0)
    {
        cout << "Partner: Congratulations, you have passed this final interview!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Partner: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        overseaStudent.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Now, let's have the oversea student answer the next question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Please explain the Windsor Effect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (generateRandomBoolean())
    {
        cout << "（Oversea student answered correctly.）"
             << "\n"
             << "(Press Enter to continue)";
        overseaStudent.attack(mainCharacter);
    }
    else
    {
        cout << "（Oversea student answered wrongly.）"
             << "\n"
             << "(Press Enter to continue)";
        overseaStudent.hurt(70);
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Now, it's your turn."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Which of the following is not one of the world's three major consulting firms?"
             << "\n"
             << "(A)Mckinsey (B)BCG (C)Bain (D)JP Morgan"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'd')
    {
        mainCharacter.attack(overseaStudent);

        cout << "Partner: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(70);
        cout << "Partner: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (overseaStudent.getHealth() <= 0)
    {
        cout << "Partner: Congratulations, you have passed this final interview!"
             << "\n"
             << "(Press Enter to continue)";
        return true;
    }
    else if (mainCharacter.getHealth() <= 0)
    {
        cout << "Partner: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        return false;
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        overseaStudent.print();
        mainCharacter.companyPrint();
        cout << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Now, let's have the oversea student answer the next question."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Who is considered the father of modern management studies?"
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (generateRandomBoolean())
    {
        cout << "（Oversea student answered correctly.）"
             << "\n"
             << "(Press Enter to continue)";
        overseaStudent.attack(mainCharacter);
    }
    else
    {
        cout << "（Oversea student answered wrongly.）"
             << "\n"
             << "(Press Enter to continue)";
        overseaStudent.hurt(70);
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Now, it's your turn."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Which of the following is not mentioned as an analysis dimension in the BCG Matrix?"
             << "\n"
             << "(A) Cash Cows (B) Dogs (C) Question Marks (D) Golden Fish"
             << "\n"
             << "(Enter your answer)"
             << "\n";
    }

    std::cin.get(playAns);

    if (tolower(playAns) == 'd')
    {
        mainCharacter.attack(overseaStudent);

        cout << "Partner: Excellent, the answer is correct."
             << "\n"
             << "(Press Enter to continue)";
    }
    else
    {
        mainCharacter.hurt(70);
        cout << "Partner: Unfortunately, that's incorrect."
             << "\n"
             << "(Press Enter to continue)";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (overseaStudent.getHealth() <= 0)
    {
        cout << "Partner: Congratulations, you have passed this final interview!"
             << "\n"
             << "(Press Enter to continue)";
        cout << "\n";
        return true;
    }
    else
    {
        cout << "Partner: Unfortunately, your application process ends here. We hope to see you again next time."
             << "\n"
             << "(Press Enter to continue)";
        cout << "\n";
        return false;
    }
}

void ConsultingCompany::offer()
{
    char continueKey;

    cout << "Partner: Congratulations, you have received an offer from our company."
         << "\n"
         << "(Press Enter to continue)";

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Your interview performance reflects your attitude and ambition."
             << "\n"
             << "(Press Enter to continue)";
    }

    // Wait for the user to press Enter
    std::cin.get(continueKey);

    if (continueKey == '\n')
    {
        cout << "Partner: Starting today, let's work together!"
             << "\n"
             << "(Press Enter to continue)";
        ;
    }
}

bool ConsultingCompany::consultingCompanyRun()
{
    if (whetherEnter())
    {
        if (groupInterview())
        {
            if (englishInterview())
            {
                if (finalInterview())
                {
                    offer();
                    return true;
                }
            }
        }
    }
    return false;
}
