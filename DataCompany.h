#ifndef DataCompany_H
#define DataCompany_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Company.h"
using namespace std;

bool checkHealth(Character const &c);
bool checkFinalHealth(Player const &p , Enemy const &e);


class DataCompany : public Company
{
private:
    // Weight, maximum health 500, maximum attack index 100
    // const int programSkillindex = 2;
    // const int quantSkillindex = 1;
    // const int commuSkillindex = 2;
    // const int seniorDataAnalyAttack = 100;
    // const int seniorDataAnalyHealth = 300;
    // const int dataTeamBossAttack = 150;
    // const int dataTeamBossHealth = 400;
    // const int studentAttack = 50;
    // const int studentHealth = 250;
    static const int programSkillindex = 2;
    static const int quantSkillindex = 1;
    static const int commuSkillindex = 2;
    static const int seniorDataAnalyAttack = 100;
    static const int seniorDataAnalyHealth = 300;
    static const int dataTeamBossAttack = 150;
    static const int dataTeamBossHealth = 400;
    static const int studentAttack = 50;
    static const int studentHealth = 250;


public:
    DataCompany();
    DataCompany(string n, Player &m);
    ~DataCompany(){};
    void calculateAbility();
    bool pretest();
    bool interview1();
    bool interview2();
    bool interview3();
};

struct Problem
{
    string question;
    string ansA;
    string ansB;
    string ansC;
    string ansD;
    char ans;
    void print();
};

const Problem aQ1 = {"1.Which of the following statistics can be used to describe the dispersion of data?", "(a) Mean", "(b) Standard Deviation", "(c) Median", "(d) Range", 'b'};
const Problem aQ2 = {"2.What is the significance of p-value in statistical hypothesis testing?", "(a) Probability of rejecting the null hypothesis", "(b) Probability of accepting the null hypothesis", "(c) Significance level", "(d) Value of standard deviation", 'a'};
const Problem aQ3 = {"3.What is an outlier?？", "(a) Maximum value in the dataset", "(b) Minimum value in the dataset", "(c) A value significantly different from other data points", "(d) Median of the dataset", 'c'};
const Problem aQ4 = {"4.What does PCA stand for?", "(a)Partial Component Analysis", "(b)Primary Component Analysis", "(c)Pokemon Count Analysis", "(d)Principal Component Analysis", 'd'};
const Problem aQ5 = {"5.What is the meaning of residual in regression analysis?", "(a) Difference between predicted and actual values", "(b) Similarity between predicted and actual values", "(c) Difference between mean and median", "(d) Difference between categorical variables", 'a'};

const Problem bQ1 = {"1.In a DataFrame named df, use Matplotlib to draw a boxplot showing the distribution of data for each column.。", "(a)df.boxplot()", "(b)df.plot(kind='box')", "(c)df.box()", "(d)Let the teammate answer", 'b'};
const Problem bQ2 = {"2.In a NumPy array named data, calculate the standard deviation of the data.", "(a)np.std(data)", "(b)np.var(data)", "(c)np.mean(data)", "(d)Let the teammate answer", 'a'};
const Problem bQ3 = {"3.Standardize a training dataset named X_train using the Scikit-learn library.", "(a)StandardScaler().fit(X_train)", "(b)MinMaxScaler.fit(X_train)", " (C)Normalizer.fit(X_train)", "(d)Let the teammate answer", 'a'};
const Problem bQ4 = {"4.SQL was invented by employees of which company?", "(a)IBM", "(b)Microsoft", "(c)Oracle", "(d)Let the teammate answer", 'a'};
const Problem bQ5 = {"5.In SQL, what is the statement used to select all columns from a table?", "(a)SELECT COLUMN(*)", "(b)SELECT *", "(C)GET ALL", "(d)Let the teammate answer", 'b'};

const Problem cQ1 = {"1.In C++, which of the following is a characteristic of an abstract class?", "(a) Can be instantiated", "(b) Can contain pure virtual functions", "(c) Cannot contain member variables", "(d) Can be instantiated directly but cannot call its member functions", 'b'};
const Problem cQ2 = {"2.In C++, what is the difference between ++i and i++?", "(a) No difference", "(b) ++i is post-increment, i++ is pre-increment", "(c) ++i is pre-increment, i++ is post-increment", "(d) ++i and i++ are different data types", 'c'};
const Problem cQ3 = {"3.In C++, what is a constructor?", "(a) Function used to destroy objects", "(b) Function used to create objects", "(c) Function used to update objects", "(d) Function used to copy objects", 'b'};
const Problem cQ4 = {"4.In C++, what is the purpose of the static modifier?", "(a) Indicates that the variable is global", "(b) Indicates that the variable is a constant", "(c) Indicates that the variable is static", "(d) Indicates that the variable is dynamic", 'c'};
const Problem cQ5 = {"5.In C++, what is dynamic binding?", "(a) Binds functions at compile time", "(b) Binds functions at runtime", "(c) Binds variables at compile time", "(d) Binds variables at runtime", 'b'};


#endif // DataCompany_H
