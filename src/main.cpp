#include "ofMain.h"
#include "ofApp.h"

using namespace std;

//========================================================================
int main( ){
	ofSetupOpenGL(1024,640,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

	
	//terminal based game concept
	/*
	srand(time(0));

	bool endGame = false;
	int playerChoice;
	int enemyChoice;
	int enemyAttack;

	float playerHealth = 100;
	float playerDefense = 0;
	float enemyHealth = 100;
	float enemyDefense = 0;

	while (endGame == false) {
		//perception check
		enemyChoice = (rand() % 2) + 1;
		if (enemyChoice == 1) {
			enemyAttack = (rand() % 2) + 1;
			if (enemyAttack == 1) {
				printf("Enemy is considering a heavy attack\n");
			}
			else {
				printf("Enemy is considering a light attack\n");
			}
		}
		else {
			printf("Enemy is considering a block\n");
		}

		//playerMenu
		printf("Would you like to: \n(1)attack\n(2)defend\n(3)use item\n(4)use spell\n");
		scanf("%d", &playerChoice);

		while (playerChoice < 1 || playerChoice > 4) {
			printf("Please input a valid number: ");
			scanf("%d", &playerChoice);
		}

		//playerChoice
		if (playerChoice == 1) {
			printf("Attack: \n(1)heavy\n(2)light\n");
			scanf("%d", &playerChoice);

			while (playerChoice < 1 || playerChoice > 2) {
				printf("Please input a valid number: ");
				scanf("%d", &playerChoice);
			}

			if (playerChoice == 1) {
				if (rand() % 10 < 5) {
					enemyHealth -= (20 - enemyDefense);
					printf("You hit enemy for %d damage!\n", (int) (20 - enemyDefense));
				}
				else {
					printf("You missed!\n");
				}
			}
			else {
				if (rand() % 10 < 8) {
					enemyHealth -= (10 - enemyDefense);
					printf("You hit enemy for %d damage!\n", (int) (10 - enemyDefense));
				}
				else {
					printf("You missed!\n");
				}
			}
		}
		else if (playerChoice == 2) {
			playerDefense += 1;
		}
		else if (playerChoice == 3) {
			printf("Items: \n(1)item 1\n(2)item 2\n");
			scanf("%d", &playerChoice);

			while (playerChoice < 1 || playerChoice > 2) {
				printf("Please input a valid number: ");
				scanf("%d", &playerChoice);
			}

			if (playerChoice == 1) {
				printf("You used item 1\n");
			}
			else {
				printf("You used item 2\n");
			}
		}
		else {
			printf("Spells: \n(1)heal\n(2)fireball\n");
			scanf("%d", &playerChoice);

			while (playerChoice < 1 || playerChoice > 2) {
				printf("Please input a valid number: ");
				scanf("%d", &playerChoice);
			}

			if (playerChoice == 1) {
				int heal = rand() % 11;
				playerHealth += heal;
				printf("You healed for %d health\n", heal);
			}
			else {
				int fireball = (rand() % 30) + 1;
				enemyHealth -= fireball;
				printf("You hit enemy for %d damage!\n", fireball);
			}
		}

		//enemy turn
		if (rand() % 4 == 0) {
			enemyChoice = (rand() % 2) + 1;
			if (enemyChoice == 1) {
				enemyAttack = (rand() % 2) + 1;
			}
		}
		if (enemyChoice == 1) {
			if (enemyAttack == 1) {
				if (rand() % 10 < 5) {
					playerHealth -= (20 - playerDefense);
					printf("The enemy hit you for %d damage!\n", (int)(20 - playerDefense));
				}
				else {
					printf("The enemy missed!\n");
				}
			}
			else {
				if (rand() % 10 < 8) {
					playerHealth -= (10 - playerDefense);
					printf("The enemy hit you for %d damage!\n", (int)(10 - playerDefense));
				}
				else {
					printf("The enemy missed!\n");
				}
			}
		}
		else {
			enemyDefense += 1;
		}

		//end of turn
		if (playerHealth <= 0) {
			printf("You lose!\n");
			endGame = true;
		}
		else if (enemyHealth <= 0) {
			printf("You win!\n");
			endGame = true;
		}
		else {
			printf("Your health: %.1lf\n Enemy Health: %.1lf\n", playerHealth, enemyHealth);
		}
	}*/
}
