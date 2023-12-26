#ifndef SECURITIESCOMPANY_H
#define SECURITIESCOMPANY_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Company.h"
using namespace std;

struct Question
{
    string question;
    string choiceA;
    string choiceB;
    string choiceC;
    string answer;
    void print();
    bool checkInput(string& n);
};

class SecuritiesCompany : public Company
{
private:
    int initHealth;
public:
    SecuritiesCompany();
    SecuritiesCompany(string n, Player& mainCharater);
    void checkHealth(); // exception handling
    bool compareWithEnemy(int ensCnt, Enemy ens[]);
    bool ifAccepted();
    void opening();
    bool writtenTest();
    bool analystInterview();
    bool headsInterview();
};

const int WQ_CNT = 5;
const int AQ_CNT = 5;
const int HQ_CNT = 6;

const Question wQ1 = {"What is gross profit margin?", "A Pre-tax profit / Total revenue", "B After-tax profit / Total assets", "C (Total revenue - Total cost) / Total revenue", "C"};
const Question wQ2 = {"The first person recorded in history with a name is Kushim. What was his profession?", "A King", "B Teacher", "C Accountant", "C"};
const Question wQ3 = {"What is the formula for calculating EPS (Earnings Per Share)?","A After-tax net profit / Number of shares", "B Gross profit / Number of shares", "C Revenue / Number of shares", "A"};
const Question wQ4 = {"Which of the following NTU presidents has taught courses in the College of Management?", "A Fu Si-nian", "B Kuan Chung-ming", "C Chen Wen-zheng", "B"};
const Question wQ5 = {"Which of the following is not an indicator of a company's profitability?", "A Accounts receivable turnover ratio", "B Return on assets", "C Net profit margin", "A"};

const Question iQ1 = {"What statistical measure can be used to assess the risk of stocks?", "A Median", "B Mean", "C Standard deviation", "C"};
const Question iQ2 = {"Which of the following stocks has never reached a price of over one thousand NT dollars?", "A TSMC (2330)", "B Largan Precision (3008)", "C Cathay Financial (2882)", "A"};
const Question iQ3 = {"As of December 2023, what is the largest industry sector by market share in the Yuanta Taiwan 50 ETF (0050)?", "A Financial industry", "B Semiconductor industry", "C Optoelectronics industry", "B"};
const Question iQ4 = {"If you invested in the Dow Jones Industrial Average since its inception date and reinvested all dividends, what would be the return multiple?", "A 174,000 times", "B 219,000 times", "C 96,000 times", "A"};
const Question iQ5 = {"Which of the following does not belong to fundamental analysis?", "A Industry analysis", "B Technical analysis", "C Economic environment analysis", "B"};

const Question hQ1 = {"Which of the following statements about NTU is incorrect?", "A The area of the College of Management used to be a Japanese military base", "B The old name of the Drunken Moon Lake was Niu-nan Pond", "C The architects of the 1st Student Activity Center and the Sun Yat-sen Memorial Hall are the same person", "A"};
const Question hQ2 = {"Which is not the stock indexes in the US?", "A S&P 500 Index", "B Russell 2000 Index", "C FTSE MIB Index", "C"};
const Question hQ3 = {"Which company does Warren Buffett serve as the CEO?", "A Goldman Sachs", "B Berkshire Hathaway", "C JPMorgan Chase", "B"};
const Question hQ4 = {"Which of the following events did not happen this year (2023)?", "A Wave of bank failures in the United States", "B Regional Comprehensive Economic Partnership (RCEP) coming into effect", "C Credit Suisse crisis", "B"};
const Question hQ5 = {"Who is the current Chairperson of the Federal Reserve?", "A Antony Blinken", "B George Soros", "C Jerome Powell", "C"};
const Question hQ6 = {"Which of the following is NOT a quote attributed to Warren Buffett?", "A \"Time is the friend of the wonderful company, the enemy of the mediocre.\"", "B \"Our favorite holding period is forever.\"", "C \"I believe that market prices are always wrong in the sense that they present a biased view of the future.\"", "C"};

#endif // SECURITIESCOMPANY_H
