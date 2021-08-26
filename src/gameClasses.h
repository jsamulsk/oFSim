#pragma once
#include "ofMain.h"
#include "entityClasses.h"
#include "menuClasses.h"
#include "statsbarClasses.h"


class player {
private:
	float health;
	float defense;
	int choice;

	float attackBoost;
	float spellBoost;
public:
	player();

	entity playerImage;
	statsbar statsBar;

	float getHealth();
	float getDefense();
	int getChoice();

	void setHealth(float _health);
	void setDefense(float _defense);
	void increaseDefense(float _defense);
	void setChoice(int _choice);

	//calculates and returns an amount
	float heavyAttack(float enemyDefense);
	float lightAttack(float enemyDefense);
	float fireball();
	float heal();

	//increases potency of next attack/spell
	void attackUp();
	void spellUp();

};

class gameLogic {
private:
	bool isPlayerTurn;

	ofImage battleBackground;
public:
	gameLogic();

	player user;
	player enemy;
	menu options;
	textPrint output;

	bool getIsPlayerTurn();

	void setIsPlayerTurn(bool _isPlayerTurn);

	void generateEnemyChoice(int numChoices); //given number of choices, randomly chooses one to set enemy.choice
	void drawGame(); //draws/updates based on width and height of screen

	void perceptionCheck(); //creates enemy decision and tells player with 75% accuracy
	void updatePlayerChoice(); //checks for player input
	void updateOptions(); //changes menus and game based on player input
	void enemyTurn(); //enemy takes turn
	void updateHealthBars(); //changes healthbar and health displayed to match events of turn
	void isGameOver(); //checks if game is over, who won, and exits
};