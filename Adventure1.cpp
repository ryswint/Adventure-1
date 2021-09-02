//Ryan Swint
//Fall 2021 Chapter 2
//Module 3

//Adventure #1
//This program pits the Adventurer against an opponent to see if they can survive.
//Built to run in Windows console
//https://github.com/ryswint/Adventure-1.git

#include <Windows.h>
#include <iostream>
using namespace std;


//===================Variables & Constants=============================================================//
int selection;
int selection2;
int selection3;


int health = 10;
int currentHealth;
int attack;
int block;
int turns = 0;
int endTurn = 4;
int waitTime = 3000;

bool rndTurns = 0;
bool debugMode = 0;
bool answerLoop = 1;
bool titleScreen = 1;

char answer;
char answerCap;

enum enemy { Human = 0, Goblin = 1, Ogre = 2, Demon = 3 };
enemy opponent = Human;

string opponentstring;
string name;

//===================Main Function=====================================================================//

int main()
{
	cout << "Welcome Adventurer!  What is your name?\n";
	cin >> name;



	while (1) //Infinite loop, broken with return 0
	{
		system("Color 07");
		titleScreen = 1;
		answerLoop = 1;

		cout << endl << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n";
		cout << "*=*=*=[The Legend of the Legendary " << name << "]*=*=*\n";
		cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";

		while (titleScreen)
		{
			cout << endl << "Start: 1";
			cout << endl << "Settings: 2";
			cout << endl << "Quit: 3";
			cout << endl << endl << "Selection: ";
			cin >> selection;

			switch (selection)
			{
			case 1:
				titleScreen = 0;
				break;

			case 2:
				while (answerLoop)//Settings Menu
				{

					cout << endl << endl << "1. Opponent: ";
					switch (opponent)
					{
					case 0:
						cout << "Human";
						break;
					case 1:
						cout << "Goblin";
						break;
					case 2:
						cout << "Ogre";
						break;
					case 3:
						cout << "Demon";
					}
					cout << endl << "2. Random Turns: ";
					if (rndTurns) cout << "On";
					else cout << "Off";
					cout << endl << "3. Debug Mode: ";
					if (debugMode) cout << "On";
					else cout << "Off";
					cout << endl << "4. Player Health: " << health;
					cout << endl << "5. Exit";
					cout << endl << endl << "Selection: ";
					cin >> selection2;

					switch (selection2)
					{
					case 1: //Opponent Menu
						cout << endl << endl << "Select Your Opponent!";
						cout << endl << "1. Human - Normal";
						cout << endl << "2. Goblin - Hard";
						cout << endl << "3. Ogre - Extra Hard";
						cout << endl << "4. Demon - WTF";
						cout << endl << endl << "Selection: ";
						cin >> selection3;
						switch (selection3)
						{
						case 1:
							opponent = Human;
							break;
						case 2:
							opponent = Goblin;
							break;
						case 3:
							opponent = Ogre;
							break;
						case 4:
							opponent = Demon;
							break;
						default:
							cout << endl << "How are you going to fight if you can't follow simple instructions " << name << "?";
						}
						break;

					case 2:
						rndTurns = !rndTurns;
						break;
					case 3:
						debugMode = !debugMode;
						break;
					case 4:
						cout << endl << endl << "Enter a value for Player Health.\n";
						cin >> health;
						break;
					case 5:
						answerLoop = 0;
						break;
					default:
						cout << endl << "Does " << selection2 << " look like an option, try again!";
						break;							
					}
				}
				break;
			case 3:
				return 0;
			}
		}

		srand(time(NULL)); //Seed RNG with current time
		currentHealth = health;

		if (rndTurns)
		{
			endTurn = rand() % 10 + 1;
		}
		else
		{
			endTurn = 4;
		}
		if (debugMode) cout << endl << "debugMode-endTurn = " << endTurn;

		cout << endl << endl << "You have chosen to do battle against the ";
		switch (opponent)
		{
		case 0:
			cout << "Human ";
			break;
		case 1:
			cout << "Goblin ";
			break;
		case 2:
			cout << "Ogre ";
			break;
		case 3:
			cout << "Demon ";
		}

		cout << "for " << endTurn << " rounds! Battle will begin in:";
		Sleep(1000);
		cout << endl << "5";
		Sleep(1000);
		cout << endl << "4";
		Sleep(1000);
		cout << endl << "3";
		Sleep(1000);
		cout << endl << "2";
		Sleep(1000);
		cout << endl << "1";
		Sleep(1000);
		cout << endl << "Fight!";
		Sleep(1000);

		for (turns = 0; turns < endTurn; turns++) // Battle Event
		{

			cout << endl << endl << "Turn " << turns + 1 << endl;
			srand(time(NULL)); //Seed RNG with current time

			Sleep(1000);
			cout << endl;
			attack = rand() % 5 + opponent;
			if (debugMode) cout << endl << "debugMode-attack = " << attack;
			block = rand() % 5;
			if (debugMode) cout << endl << "debugMode-block = \n" << block;


			switch (opponent)
			{
			case 0:
				cout << "Human ";
				break;
			case 1:
				cout << "Goblin ";
				break;
			case 2:
				cout << "Ogre ";
				break;
			case 3:
				cout << "Demon ";
			}

			cout << "attacks with a " << attack << "!";
			Sleep(waitTime);


			if (attack > block) //Block Fail
			{
				currentHealth -= attack;
				if (debugMode) cout << endl << "debugMode-currentHealth = " << currentHealth;
				cout << endl << "Your block of " << block << " fails!";
				system("Color 40");
				system("Color 04");
				system("Color 40");
				system("Color 04");
				system("Color 07");
				Sleep(1000);
				cout << endl << "Health: " << currentHealth;
			}
			else //Block Successful
			{
				cout << endl << "You block with a " << block << "!";
				system("Color 10");
				system("Color 01");
				system("Color 10");
				system("Color 01");
				system("Color 07");
				Sleep(1000);
				cout << endl << "Health: " << currentHealth;
			}

			if (currentHealth < 1)
			{

				cout << endl << endl << "You have died!";
				break;
			}

			Sleep(waitTime);
		}

		if (currentHealth > 0)//End Game
		{
			system("Color 02");
			cout << endl << endl << "YOU WON " << name << "!!!";
			if (currentHealth < 3) //Win
			{
				Sleep(waitTime);
				cout << endl << "Now go see a doctor!";
			}
		}
		else //Loss
		{

			system("Color 04");
			cout << endl << endl << name << ", you have suffored a gruesome death.";
		}

		Sleep(waitTime);

		answerLoop = 1;
		while (answerLoop)
		{
			cout << endl << endl << "Do you want to try to survive again? (y/n) ";
			cin >> answer;
			answerCap = toupper(answer);
			switch (answerCap)
			{
			case 'Y':
				answerLoop = false;
				break;
			case 'N':
				answerLoop = false;
				return 0;
			default:
				cout << endl << "What do you mean " << answer << "? The instructions were not that hard " << name << "! Have an Energy Potion and try again!" << endl;
				answerLoop = true;
			}
		}
	}
}


