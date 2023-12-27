# The-Adventurous-Journey-of-Business-Students-in-the-Future-World

## Project Theme
The game is set in the year 2105 when technology has reached advanced levels, societal structures have transformed, and even education has evolved. 

In this era, students engage in virtual classroom learning, with academic knowledge becoming exceptionally rich. However, internship opportunities have become exceedingly rare, and the player assumes the role of a student from NTU Management School embarking on an adventurous journey to find an internship. Confronting the unknown professional world, players face various career tasks and build their career paths!

**Players start on the virtual campus, navigating through a virtual campus map to select different learning tasks, and enhancing skills such as Finance Knowledge, Quantitative Skill, Communication Skill, Programming Skill.** **However, players must also be mindful of maintaining their Liver Index and Lazy index.** Additionally, learning opportunities are limited; **players can choose a maximum of six school courses to improve their skills**. Excellent performance may yield rewards such as project opportunities and internal recommendations.

Next, players enter the internship interview stage. After passing the initial corporate competency test, players face different interview challenges, including technical interviews, team interviews, and English interviews, etc. **Attack Index and Health depend on the corresponding skill values possessed by the player.** In case of failure, players can choose to re-interview, apply to other companies, or return to school to accumulate skills (in case the course quota is not full). **If successful, players receive a job offer, concluding the game.**

## System Design

### Main Structure
The class "Game" encompasses the main logical functions of the game. At the start of the game, the "main" function initializes the "Game" and invokes functions from relevant classes, such as game background introduction and rules, to initiate the game. The "Game" then proceeds to initialize the "Player," "Campus," and three companies, with each company subsequently initializing its own set of enemies.

Within the "Campus," individual "CampusLoc" instances are initialized, and each "CampusLoc" contains its own set of items. During each game round, the "Game" calls functions, allowing the "Player" to choose to go to school to complete missions and enhance their skills, attend interviews at companies, or exit the game.

When the "Player" completes an interview, they receive an offer and the game concludes. In the case of interview failure, the "Player" can choose to go to school to improve skills or opt for interviews with other companies until they receive an offer from one of them, leading to the end of the game.

![main structure](https://i.imgur.com/UAlCrOO.png)

### Character
Player and Enemy both inherit from Character.

Character defines variables and functions that are required by both Player and Enemy, such as Attack Index and Health, and sets functions for both.

In Player, there are six ability variables like Finnance Knowledge, Quantitative Skill, Lazy Index, etc. Additionally, it includes storage for dropped items, a vector of completed courses, and a round count to track the number of completed courses. It also encompasses functions for setting and retrieving values for each variable, as well as functions related to attacking enemies and taking damage during the interview phase.

![character](https://i.imgur.com/Qt0oytA.png)

### Company
DataCompany, Consulting Company, and Securities Company all inherit from Company.

Company defines the name of each company and takes the Player instance passed into the game. After the creation of each company, they generate their respective Enemy objects and set values such as attackIndex and health for each Enemy.

DataCompany, Consulting Company, and Securities Company also include their own ability tests and three rounds of interviews. During the ability tests, the Player's capabilities are assessed to determine if they meet the requirements of the specific company. If qualified, the Player proceeds to the interview rounds, and their Attack Index and Health are weighted based on the abilities valued by the company. Additionally, items obtained at school can increase the Player's Attack Index and Health. Each company's three rounds of interviews involve various assessments and game rules, such as math written tests, programming quick response questions, random Enemy attacks, etc. If the Player meets the standards, they can attack the Enemy; otherwise, they will be attacked. The final comparison of their life values determines whether the Player passes the interview.

![company](https://i.imgur.com/Rp61gCT.png)

### Campus
After establishing Campus, the next step is to initialize 10 mission locations, including places like National Taiwan University Hospital, School of Management, and Management School Library. Each campus location (campusLoc) has its own name, mission, abilities that can be enhanced, weights, and items for additional rewards.

Within Campus, there is locList and roundCnt to track the Player's progress in solving missions at school. If a mission is already completed, it cannot be experienced again. If roundCnt exceeds 6, the Player cannot continue to solve missions at school.

Each campusLoc contains different missions. The Player must answer questions, and the corresponding capability increases only when the correctCnt indicates the added value. For example, in the Management School Library, the Player must complete two English questions to increase their conversation skills. Moreover, if the Player answers all questions correctly at a location, they can receive additional Item rewards, which may include job referrals, project works, etc., enhancing their Attack Index and Health for future interview stages, making them more competitive.

Items include names, the amount of Attack Index increase, and the amount of Health increase. When the Player performs well in school missions, they receive the Item for that location. It is then stored in the Player's itemVector and can be read during interviews to boost their Attack Index and Health.

![campus](https://i.imgur.com/hKPYTKJ.png)
