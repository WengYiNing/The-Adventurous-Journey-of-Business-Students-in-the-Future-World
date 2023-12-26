#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include "Company.h"
#include "ConsultingCompany.h"
#include "SecuritiesCompany.h"
#include "DataCompany.h"
#include "Campus.h"
#include "CampusLoc.h"
#include "Game.h"
using namespace std;

void Game::introduction1() {
    cout << "In the year 2105 AD, the world has entered a new era of highly advanced technology. The societal structure has undergone a revolutionary transformation, and education is no exception..." << endl;
    cout << "You, as a student at the National Taiwan University's College of Management, engage in interactive learning with professors and fellow students from around the world through advanced virtual classroom technology. Academic knowledge in this era has become incredibly abundant, but simultaneously, internship opportunities have become exceedingly precious." << endl;
    cout << "In this world full of challenges and opportunities, you will embark on an adventure to find internships. Facing the unknown professional world, tackling various occupational tasks, and establishing your own career path, let's go forward together!" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cin.get();
}

void Game::introduction2() {
    cout << "Welcome to the game 'Internship Battle' set in the future world! Here are the rules of the game:" << endl;
    cout << "Players must first participate in relevant courses on campus to enhance their skills, such as financial economics, quantitative analysis, conversational skills, programming, and more." << endl;
    cout << "The progress of each course affects the improvement of the corresponding skill. However, it's essential to maintain your liver index and laziness index at a good level~" << endl;
    cout << "In addition, learning opportunities are limited. You can choose a maximum of six school courses, so good time management is necessary!" << endl;
    cout << endl;
    cin.get();
    cout << "Of course, at any time during your school studies, if you feel ready, you can start your internship journey! " << endl;
    cout << "You can apply for internships at different companies, facing challenges from various enterprises, including written tests, technical interviews, team interviews, and more." << endl;
    cout << "If you pass the interview, congratulations! You can enter the internship at that company and become the ultimate winner." << endl;
    cout << "If you don't pass the interview, don't be discouraged. You can return to school to continue learning, improve your skills, and challenge interviews at other companies." << endl;
    cout << "Are you ready? In this journey of chasing dreams in the future world, showcase your charm, challenge the unknown, and achieve greatness. Now, begin your Internship Battle!" << endl;
    cout << endl;
}

void Game::switchLocation() {
    cout << "Please choose the location you want to go:" << endl;
    cout << "1. Enhance skills at school" << endl;
    cout << "2. Apply for internship at a company" << endl;
    cout << "3. Exit the game" << endl;
    cout << "Enter the number: ";
    // player.schoolPrint();
    int opt = 0;
    int check = 1;

    while (check) {
        cin >> opt;
        if (opt == 1) {
            if (player.getCourseVector().size() < 6) {
                this->selectLocation();
            } else {
                cout << "You have been in school for six semesters. Go find an internship!" << endl;
            }
            check = 0;
        } else if (opt == 2) {
            this->selectCompany();
            check = 0;
        } else if (opt == 3) {
            this->gameEnd();
            check = 0;
        } else {
            cout << "Please enter 1, 2, or 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


void Game::selectLocation(){
    cout << "Please choose the location you want to go:" << endl;
    cout << "1. NTU Hospital" << endl;
    cout << "2. Der Tian Hall" << endl;
    cout << "3. College of Management Library" << endl;
    cout << "4. Building 1, College of Management, Department of Finance" << endl;
    cout << "5. Building 1, College of Management, Department of Business Administration" << endl;
    cout << "6. Building 1, College of Management, Department of Information Management " << endl;
    cout << "7. Building 2 , College of Management, Department of International Business" << endl;
    cout << "8. Building 2 , College of Management, Department of Accounting" << endl;
    cout << "9. Computer and Information Networking Center" << endl;
    cout << "10. Sports Center" << endl;
    cout << "Enter the number: " << endl;
    int opt, check = 1;
    while(check){
        try{
            cin >> opt;
            if (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5 && opt != 6 && opt != 7 && opt != 8 && opt != 9 && opt != 10){
                throw opt;
            }
            // Check if the player has selected the course
            if(player.haveCourses(opt)){
                cout << "You have already selected this course. Please choose again." << endl;
                continue;
            }
            else{
                campus.playLoc(opt - 1, &player);
                check = 0;
            }
        }
        catch(int opt){
            cout << "Please enter a number between 1 and 10." << endl;
            cin >> opt;
        }
    }
}

void Game::selectCompany() {
    cout << "Please choose the company you want to apply to." << endl;
    cout << "1. Consulting Company" << endl;
    cout << "2. Securities Company" << endl;
    cout << "3. Data Company" << endl;
    
    int opt;
    int check = 1;

    while (check) {
        try {
            cin >> opt;
            
            if (opt != 1 && opt != 2 && opt != 3) {
                throw opt;
            }

            if (opt == 1) {
                consultingcompany = new ConsultingCompany("Consulting Company", player);
                if (consultingcompany->consultingCompanyRun()) {
                    this->gameEnd();
                }
                delete consultingcompany;
                consultingcompany = nullptr;
            } else if (opt == 2) {
                securitiescompany = new SecuritiesCompany("Securities Company", player);
                if (securitiescompany->ifAccepted()) {
                    securitiescompany->opening();
                    if (securitiescompany->writtenTest()) {
                        if (securitiescompany->analystInterview()) {
                            if (securitiescompany->headsInterview()) {
                                this->gameEnd();
                            }
                        }
                    }
                }
                delete securitiescompany;
                securitiescompany = nullptr;
            } else {
                datacompany = new DataCompany("Data Company", player);
                if (datacompany->pretest()) {
                    if (datacompany->interview1()) {
                        if (datacompany->interview2()) {
                            if (datacompany->interview3()) {
                                this->gameEnd();
                            }
                        }
                    }
                }
                delete datacompany;
                datacompany = nullptr;
            }
            
            check = 0;
        } catch (int opt) {
            cout << "Please enter a number between 1 and 3." << endl;
            cin >> opt;
        }
    }
}


void Game::gameEnd(){
    cout << "----------------------------------------------------------------" << endl;
    cout << "Game over. Thank you for playing!" << endl;
    runOrNot = 0;
}
