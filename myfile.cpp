/*
*       Useful things to know:
*       - There is no try/catch or similar, so enter actions correctly. Otherwise the loops may fuck up.
*       - All actions are within single qoutes, like this: 'action'. But you don't type the single qoutes, just the word.
*       - I think I fixed all the bugs, calculations, loops and prints that I stumbled upon, but there is always something you forget or miss...
*          - Enjoy!
*/
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;
//Struct
struct player{
    int playerHP = 100;
    int maxHP = playerHP;
    int energy = 100;
    string name;
}user;
//variables
//string name;
string choice;
string monster;
bool explore = false;
bool fight = false;
bool battle = false;
bool game = true;
//int maxHP = 100;
//int playerHP = maxHP;
//int userEnergy = 100;
int monsterHP = 0;
//functions for different randomizations
int zeroToThree(int a) {
    int random;
    srand(rand() ^ time(NULL));
    return random = rand() % (3 - 0 + 1) + 0;
}
int randMonsterHp(int a) {
    int monsterHpArray[4] = { 50, 75, 100, 115 };
    int random;
    srand(rand() ^ time(NULL));
    random = rand() % (3 + 0 + 1) + 0;
    return monsterHpArray[random];
}
int randMonsterHit(int a) {
    int random;
    srand(rand() ^ time(NULL));
    return random = rand() % (25 - 15 + 1) + 15;
}
int firstHit(int a) {
    int random;
    srand(rand() ^ time(NULL));
    return random = (rand() % 2);
}
int randUserHit(int a) {
    int random;
    srand(rand() ^ time(NULL));
    return random = rand() % (25 - 15 + 1) + 15;
}
int randUserHeavyHit(int a) {
    int random;
    srand(rand() ^ time(NULL));
    return random = rand() % (40 - 25 + 1) + 25;
}
//functions for locations
void locations() {
    string locations[2] = { "forest", "dungeon" };
    cout << "\nEnter where you want to go: \n";
    for (int i = 0; i < 2; i++) {
        cout << "'" << locations[i] << "'\n";
    }
    cin >> choice;
}
void forestMenu() {
    string forestArray[3] = { "'cabin'", "'lake'", "'dungeon'"};
    cout << "\nYou are in the forest.\nOptions from here:\n";
    for (size_t i = 0; i < 3; i++) {
        cout << forestArray[i] << endl;
    }
    cin >> choice;
}
void lakeMenu() {
    string lakeArray[2] = { "'dive'", "'exit'"};
    cout << "\nYou are at the lake. Options from here : \n";
    for (size_t i = 0; i < 2; i++) {
        cout << lakeArray[i] << endl;
    }
    cin >> choice;
}
void hellMenu() {
    string hellArray[2] = { "'satan'", "'exit'" };
    cout << "\nYou are in hell\nOptions from here : \n";
    for (size_t i = 0; i < 2; i++) {
        cout << hellArray[i] << endl;
    }
    cin >> choice;
}
void dungeonMenu() {
    string dungeonArray[3] = { "'chest'", "'hell'", "'forest'"};
    cout << "\nYou are in the dungon.\nOptions from here : \n";
    for (size_t i = 0; i < 3; i++) {
        cout << dungeonArray[i] << endl;
    }
    cin >> choice;
}
//functions for locations with return
int chestMenu(int a) {
    cout << "\nYou found armor +20 to your HP\n";
    cout << "Do you want to continue to hell ? \nEnter 'yes' or 'exit'\n";
    user.maxHP += 20;
    cin >> choice;
    return user.maxHP;
}
int cabinMenu(int a) {
    user.playerHP -= 10;
    cout << "\nYou can't just enter peoples cabins.\nThe owner hit you with a shovel.\nYou lose 10HP\n";
    cout << "Where do you want to go now??\nEnter 'dungeon' or 'lake'\n";
    cin >> choice;
    return user.playerHP;
}
int diveMenu(int a) {
    user.maxHP += 15;
    cout << "\nAt the bottom of the lake you found a rusty helmet, +15HP!\n";
    cout << "Also the game is over, bye :)\n\n";
    explore = false;
    return user.maxHP;
}
void exit() {
    cout << "\nYou chose to exit, bye!\n\n";
}
//battle functions
void userHitMenu() {
    cout << "\nEnter what type of hit you want to make\n'quick' - 15 energy, 'heavy' - 30 energy or 'escape'\nCurrent energy: " << user.energy << "\n\n";
    cin >> choice;
}
void quickHitMenu() {
    int userHit = 0;
    user.energy -= 10;
    userHit = randUserHit(userHit);
    monsterHP -= userHit;
    cout << "\nYou make " << userHit << " damage!\n";
    cin >> choice;
    if (monsterHP < 0) {
        cout << "\nYou slayed the monster, congratulations!!\n";
        cout << "A new monster will be randomized!\n\n";
        battle = false;
    }
    else if (user.energy < 0 && monsterHP > 0) {
        cout << "\nYou are out of energy, the fight is over.\nGo and rest!\n";
        battle = false;
    }
    else {
        int monsterHit = 0;
        monsterHit = randMonsterHit(monsterHit);
        cout << "\nThe " << monster << " have " << monsterHP << "HP left!\n";
        cout << "Now it's the " << monster << "'s turn.\n";
        cout << "The " << monster << " makes " << monsterHit << " damage!\n";
        if (user.playerHP <= 0) {
            cout << "\nYOU DIED!\n";
            cout << "A new monster will be randomized!\n";
            battle = false;
        }
        else if (user.playerHP > 0) {
            cout << "You have " << (user.playerHP -= monsterHit) << "HP left!\n";
        }
    }
}
void heavyHitMenu() {
    int userHeavyHit = 0;
    user.energy -= 20;
    userHeavyHit = randUserHeavyHit(userHeavyHit);
    monsterHP -= userHeavyHit;
    cout << "\nYou make " << userHeavyHit << " damage!\n";
    cin >> choice;
    if (monsterHP < 0) {
        cout << "\nYou slayed the monster, congratulations!!\n";
        cout << "A new monster will be randomized!\n\n";
        battle = false;
    }
    else if (user.energy < 0 && monsterHP > 0) {
        cout << "\nYou are out of energy, the fight is over.\nGo and rest!\n";
        battle = false;
    }
    else {
        int monsterHit = 0;
        monsterHit = randMonsterHit(monsterHit);
        cout << "\nThe " << monster << " have " << monsterHP << "HP left!\n";
        cout << "Now it's the " << monster << "'s turn.\n";
        cout << "The " << monster << " makes " << monsterHit << " damage!\n";
        user.playerHP -= monsterHit;
        if (user.playerHP <= 0) {
            cout << "\nYOU DIED!\n";
            cout << "A new monster will be randomized!\n";
            battle = false;
        }
        else if (user.playerHP > 0) {
            cout << "You have " << (user.playerHP -= monsterHit) << "HP left!\n";
        }
    }
}
void escape() {
    cout << "\nYou ran away, coward!\n";
}
//array for the monsters
string monsters() {
    string monsters[5] = { "Ogre", "Demon", "Dragon", "Zombie", "Minotaur" };
    int i = 0;
    i = zeroToThree(i);
    return monsters[i];
}
//function for satan choice
void satansChoice() {
    int satansChoice = 0;
    satansChoice = zeroToThree(satansChoice);
    switch (satansChoice) {
    case 0:
        cout << "\nSatan likes you, here have some extra armor.\n";
        cout << "Also the game is over, bye :)\n";
        user.maxHP + 25;
        explore = false;
        break;
    case 1:
        cout << "\nSatan does not like you, -25 in HP!\n";
        user.playerHP - 25;
        cout << "Also the game is over, bye :)\n";
        explore = false;
        break;
    case 2:
        cout << "\nSatan really doesn't like you.\nYOU DIED!\n";
        cout << "Also the game is over, bye :)\n";
        explore = false;
        break;
    default:
        cout << "\nSatan is lame today, so he does nothing!\n";
        cout << "Also the game is over, bye :)\n";
        explore = false;
        break;
    }
}
int main() {
    /*
    * INIT START
    */
    cout << "Enter your name: \n";  cin >> user.name;
    cout << "Hello and welcome " << user.name << ", let the game begin!\n";
    /*
    * INIT END
    */
    //while the bool game is true, we run the game
    while (game == true) {
        cout << "\nWhat do you want to do?\n";
        cout << "Enter 'fight', 'explore','rest' or 'exit': \n";
        cout << "Current energy: " << user.energy << "\nCurrent HP: " << user.playerHP << "/" << user.maxHP << "\n";
        cin >> choice;
        //EXPLORE
        //if choice is explore, we set explore to true and run that loop
        if (choice == "explore") {
            explore = true;
            while (explore == true) {
                locations();
                //FOREST CHOICE
                if (choice == "forest") {
                    forestMenu();
                    //forest -> cabin
                    if (choice == "cabin") {
                        cabinMenu(user.playerHP);
                        //forest -> cabin -> dungeon
                        if (choice == "dungeon") {
                            cout << "\nYou are now in the dungeon!\nOptions from here are 'chest' or 'hell':\n";
                            cin >> choice;
                            //forest -> cabin -> dungeon -> hell
                            if (choice == "hell") {
                                hellMenu();
                                //forest -> cabin -> dungeon -> hell -> satan
                                if (choice == "satan") {
                                    satansChoice();
                                }
                                //forest -> dungeon -> hell -> exit
                                else if (choice == "exit") {
                                    exit();
                                    explore = false;
                                }
                            }
                            //forest -> dungeon -> chest
                            else if (choice == "chest") {
                                user.playerHP += 20;
                                chestMenu(user.maxHP);
                                //forest -> dungeon -> chest -> hell
                                if (choice == "yes") {
                                    hellMenu();
                                    //forest -> dungeon -> chest -> hell -> satan
                                    if (choice == "satan") {
                                        satansChoice();
                                    }//forest -> dungeon -> chest -> hell -> exit
                                    else if (choice == "exit") {
                                        exit();
                                        explore = false;
                                    }
                                }//forest -> dungeon -> chest -> exit
                                else if (choice == "exit") {
                                    exit();
                                    explore = false;
                                }
                            }
                        }
                        //forest -> cabin -> lake
                        else if (choice == "lake") {
                            lakeMenu();
                            //forest -> cabin -> lake -> dive
                            if (choice == "dive") {
                                diveMenu(user.maxHP);
                            }//forest -> cabin -> lake -> exit
                            else if (choice == "exit") {
                                exit();
                                explore = false;
                            }
                        }
                        
                    }
                    //forest -> lake
                    else if (choice == "lake") {
                        lakeMenu();
                        //forest -> lake -> dive
                        if (choice == "dive") {
                            diveMenu(user.maxHP);
                        }//forest -> lake -> exit
                        else if (choice == "exit") {
                            exit();
                            explore = false;
                        }
                    }
                    //forest -> dungeon
                    else if (choice == "dungeon") {
                        cout << "\nYou are now in the dungeon.\nOptions from here: 'chest' or 'hell'\n";
                        cin >> choice;
                        //forest -> dungeon -> chest
                        if (choice == "chest") {
                            chestMenu(user.maxHP);
                            //forest -> dungeon -> chest -> hell
                            if (choice == "yes") {
                                hellMenu();
                                //forest -> dungeon -> chest -> hell -> satan
                                if (choice == "satan") {
                                    satansChoice();
                                }//forest -> dungeon -> chest -> hell -> exit
                                else if (choice == "exit") {
                                    exit();
                                    explore = false;
                                }
                            }//forest -> dungeon -> chest -> exit
                            else if (choice == "exit") {
                                exit();
                                explore = false;
                            }
                        }
                        //forest -> dungeon -> hell
                        else if (choice == "hell") {
                            hellMenu();
                            //forest -> dungeon -> hell -> satan
                            if (choice == "satan") {
                                satansChoice();
                            }//forest -> dungeon -> hell -> exit
                            else if (choice == "exit") {
                                exit();
                                explore = false;
                            }
                        }
                    }
                }
                //DUNGEON CHOICE
                else if (choice == "dungeon") {
                    dungeonMenu();
                    //dungeon -> chest
                    if (choice == "chest") {
                        chestMenu(user.maxHP);
                        //dungeon -> chest -> hell
                        if (choice == "yes") {
                            hellMenu();
                            //dungeon -> chest -> hell -> satan
                            if (choice == "satan") {
                                satansChoice();
                            }//dungeon -> chest -> hell -> exit
                            else if (choice == "exit") {
                                exit();
                                explore = false;
                            }
                        }//dungeon -> chest -> exit
                        else if (choice == "exit") {
                            exit();
                            explore = false;
                        }
                    }
                    //dungeon -> hell
                    else if (choice == "hell") {
                        hellMenu();
                        //dungeon -> hell -> satan
                        if (choice == "satan") {
                            satansChoice();
                        }//dungeon -> hell -> exit
                        else if (choice == "exit") {
                            exit();
                            explore = false;
                        }
                    }
                    //dungeon -> forest
                    else if (choice == "forest") {
                        cout << "\nYou are now in the forest.\nOptions from here: 'cabin' or 'lake'\n";
                        cin >> choice;
                        //dungeon -> forest -> cabin
                        if (choice == "cabin") {
                            cabinMenu(user.playerHP);
                            //dungeon -> forest -> cabin -> lake
                            if (choice == "yes") {
                                lakeMenu();
                                if (choice == "dive") {
                                    diveMenu(user.maxHP);
                                }//dungeon -> forest -> cabin -> lake -> exit
                                else if (choice == "exit") {
                                    exit();
                                    explore = false;
                                }
                            }//dungeon -> forest -> cabin -> exit
                            else if (choice == "exit") {
                                exit();
                                explore = false;
                            }
                        }//dungeon -> forest -> lake
                        else if (choice == "lake") {
                            lakeMenu();
                            //dungeon -> forest -> lake -> dive
                            if (choice == "dive") {
                                diveMenu(user.maxHP);
                            }//dungeon -> forest -> lake -> exit
                            else if (choice == "exit") {
                                exit();
                                explore = false;
                            }
                        }
                    }
                }
            }
        }
        //FIGHTING
        //same here, if we chose fight, the fight bool will be set to true.
        else if (choice == "fight") {
            cout << "\nYou chose fighting\n";
            fight = true;
            while (fight == true) {
                //variables for monster and monster HP
                monster = monsters();
                monsterHP = randMonsterHp(monsterHP);
                //menu for fighting
                cout << "\nYou will be fighting " << monster << ".\n";
                cout << "The " << monster << " have " << monsterHP << "HP!\n\n";
                cout << "Do you want to figh it? \n'yes', 'no' or 'exit'\n";
                cin >> choice;
                //if we chose yes, the battle will start
                if (choice == "yes") {
                    cout << "\nLet the battle begin!\n";
                    cout << "Enter 'start' or 'exit'\n\n";
                    cin >> choice;
                    if (choice == "start") {
                        battle = true;
                        //we use a function that random who start
                        cout << "\nThe first hit will be randomized.\n";
                        int first = 0;
                        first = firstHit(first);
                        //if we get a 0 in the function you start
                        if (first == 0) {
                            cout << "You start!\n\n";
                            while (battle == true) {
                                if (first == 0) {
                                    userHitMenu();
                                    //light hit
                                    if (choice == "quick") {
                                        quickHitMenu();
                                    }//heavy hit
                                    else if (choice == "heavy") {
                                        heavyHitMenu();
                                    }
                                    //Escaping the fight
                                    else if (choice == "escape") {
                                        escape();
                                        battle = false;
                                    }
                                }
                            }
                        }//Monster starts the fight
                        //if we get a 1, the monster starts
                        else if (first == 1) {
                            cout << "\nThe " << monster << " starts!\n";
                            while (battle == true) {
                                int monsterHit = 0;
                                monsterHit = randMonsterHit(monsterHit);
                                user.playerHP -= monsterHit;
                                cout << "The " << monster << " makes " << monsterHit << " damage.\n";
                                //if the player ides
                                if (user.playerHP <= 0) {
                                    cout << "\nYOU DIED!\n";
                                    cout << "A new monster will be randomized!\n\n";
                                    battle = false;
                                }//if the player is still alive
                                else if (user.playerHP > 0) {
                                    cout << "\nYou have " << user.playerHP << "HP left!\n";
                                    userHitMenu();
                                    if (choice == "quick") {
                                        quickHitMenu();
                                    }
                                    else if (choice == "heavy") {
                                        heavyHitMenu();
                                    }
                                    else if (choice == "escape") {
                                        escape();
                                        battle = false;
                                    }
                                }
                            }
                        }
                    }//Exit the fight
                    else if (choice == "exit") {
                        exit();
                        fight = false;
                    }
                }//If no, randomize a new monster to fight
                //íf we chose no, we will randomize a new monster and new HP-value
                else if (choice == "no") {
                    cout << "\nNew monster will be randomized!\n\n";
                }//if we chose exit, we exit the fight menu and go back to main menu
                else if (choice == "exit") {
                    exit();
                    fight = false;
                }
            }
        }
        //REST
        else if (choice == "rest") {
        cout << "\nYou are now taking a nap.\nzZz zZz!\nEnergy and HP restored.\n";
        user.energy = 100;
        //if the user is below 100, we calculate what's missing and add the remaining
        if (user.playerHP < user.maxHP) {
            user.playerHP = user.maxHP;
        }
    }
    //Exiting the game
        else {
            exit();
            game = false;
        }
    }
}