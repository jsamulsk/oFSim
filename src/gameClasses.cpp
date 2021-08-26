#include "gameClasses.h"

player::player() {
	health = 100;
	defense = 0;
	choice = 0;
}

float player::getHealth() {
	return health;
}

float player::getDefense() {
	return defense;
}

int player::getChoice() {
	return choice;
}

void player::setHealth(float _health) {
	health = _health;
}

void player::setDefense(float _defense) {
	defense = _defense;
}

void player::increaseDefense(float _defense) {
	defense += _defense;
}

void player::setChoice(int _choice) {
	choice = _choice;
}

float player::heavyAttack(float enemyDefense) {
	if (ofRandom(10) < 5) {
		float _attackBoost = attackBoost;
		attackBoost = 0;
		return (20 - enemyDefense) + _attackBoost;
	}
	else {
		return 0;
	}
}

float player::lightAttack(float enemyDefense) {
	if (ofRandom(10) < 8) {
		float _attackBoost = attackBoost;
		attackBoost = 0;
		return (10 - enemyDefense) + _attackBoost;
	}
	else {
		return 0;
	}
}

float player::fireball() {
	float _spellBoost = spellBoost;
	spellBoost = 0;
	return ofRandom(15) + _spellBoost;
}

float player::heal() {
	return ofRandom(10);
}

void player::attackUp() {
	attackBoost = ofRandom(5);
}

void player::spellUp() {
	spellBoost = ofRandom(5);
}

gameLogic::gameLogic() {
	isPlayerTurn = false;
	user.playerImage.setFileLocation("images/mario.png");
	enemy.playerImage.setFileLocation("images/bowserjr.png");
	battleBackground.load("images/stars.png");
	user.statsBar.setName("Player");
	enemy.statsBar.setName("Enemy");
}

bool gameLogic::getIsPlayerTurn() {
	return isPlayerTurn;
}

void gameLogic::setIsPlayerTurn(bool _isPlayerTurn) {
	isPlayerTurn = _isPlayerTurn;
}

void gameLogic::generateEnemyChoice(int numChoices) {
	enemy.setChoice((int)ofRandom(1, numChoices + 1));
}

void gameLogic::drawGame() {
	float width = ofGetWidth();
	float height = ofGetHeight();

	battleBackground.draw(0, 0, width, height);

	options.setLocation(width, height);
	options.drawMenu();

	output.setLocation(width, height);
	output.drawTextPrint();

	user.playerImage.setLocation(10, height - 510);
	user.playerImage.drawEntity();
	enemy.playerImage.setLocation(width - 210, 120);
	enemy.playerImage.drawEntity();

	user.statsBar.setLocation(10, height - 310);
	user.statsBar.drawStatsbar();
	enemy.statsBar.setLocation(width - 410, 10);
	enemy.statsBar.drawStatsbar();
}

void gameLogic::perceptionCheck() {
	if (isPlayerTurn == false) {
		generateEnemyChoice(4);
		if (enemy.getChoice() != 1) {
			generateEnemyChoice(2);
			if (enemy.getChoice() == 1) {
				output.setText(">Enemy is considering a heavy attack");
			}
			else {
				output.setText(">Enemy is considering a light attack");
			}
		}
		else {
			output.setText(">Enemy is considering a block");
			enemy.setChoice(0);
		}
		isPlayerTurn = true;
	}
}

void gameLogic::updatePlayerChoice() {
	if (isPlayerTurn == true) {
		if (options.getCurrentMenu() == 0) {
			for (int i = 1; i < 5; i++) {
				if (options.whichButton() == i) {
					options.resetButtons();
					user.setChoice(i);
				}

			}

		}
		else {
			for (int i = 1; i < 3; i++) {
				if (options.whichButton() == i) {
					options.resetButtons();
					user.setChoice(i);
				}
			}
		}
	}
}

void gameLogic::updateOptions() {
	if (isPlayerTurn == true) {
		if (options.getCurrentMenu() == 0 && user.getChoice() == 0) {
			options.buttons[0][0].setLabel("Attack");
			options.buttons[0][1].setLabel("Defend");
			options.buttons[1][0].setLabel("Item");
			options.buttons[1][1].setLabel("Spell");
		}
		if (options.getCurrentMenu() == 0 && user.getChoice() != 0) {
			if (user.getChoice() != 2) {
				if (user.getChoice() == 1) {
					options.buttons[0][0].setLabel("Heavy Attack");
					options.buttons[0][1].setLabel("Light Attack");
					options.setCurrentMenu(1);
				}
				else if (user.getChoice() == 3) {
					options.buttons[0][0].setLabel("Attack Boost");
					options.buttons[0][1].setLabel("Spell Boost");
					options.setCurrentMenu(3);
				}
				else if (user.getChoice() == 4) {
					options.buttons[0][0].setLabel("Heal");
					options.buttons[0][1].setLabel("Fireball");
					options.setCurrentMenu(4);
				}
				options.buttons[1][0].setLabel("");
				options.buttons[1][1].setLabel("");
				user.setChoice(0);
			}
			else if (user.getChoice() == 2) {
				user.increaseDefense(1);
				output.setText(">Defense increased");
				user.setChoice(0);
				setIsPlayerTurn(false);
			}
		}
		else if (options.getCurrentMenu() == 1 && user.getChoice() != 0) {
			if (user.getChoice() == 1) {
				float heavyAttackDamage = user.heavyAttack(enemy.getDefense());
				if (heavyAttackDamage != 0) {
					enemy.setHealth(enemy.getHealth() - heavyAttackDamage);
					output.setText(">You hit the enemy with a heavy attack for " + to_string((int)heavyAttackDamage));
				}
				else {
					output.setText(">You missed");
				}
				options.setCurrentMenu(0);
			}
			else if (user.getChoice() == 2) {
				float lightAttackDamage = user.lightAttack(enemy.getDefense());
				if (lightAttackDamage != 0) {
					enemy.setHealth(enemy.getHealth() - lightAttackDamage);
					output.setText(">You hit the enemy with a light attack for " + to_string((int)lightAttackDamage));
				}
				else {
					output.setText(">You missed");
				}
				options.setCurrentMenu(0);
			}
			user.setChoice(0);
			setIsPlayerTurn(false);
		}
		else if (options.getCurrentMenu() == 3 && user.getChoice() != 0) {
			if (user.getChoice() == 1) {
				user.attackUp();
				output.setText(">Your attack is up");
				options.setCurrentMenu(0);
			}
			else if (user.getChoice() == 2) {
				user.spellUp();
				output.setText(">Your spell is up");
				options.setCurrentMenu(0);
			}
			user.setChoice(0);
			setIsPlayerTurn(false);
		}
		else if (options.getCurrentMenu() == 4 && user.getChoice() != 0) {
			if (user.getChoice() == 1) {
				float amountHealed = user.heal();
				if (amountHealed > 0) {

					user.setHealth(user.getHealth() + amountHealed);
					output.setText(">You healed for " + to_string((int)amountHealed));
					if (user.getHealth() > 100) {
						user.setHealth(100);
					}

				}
				else {
					output.setText(">Your heal fizzled out");
				}
				options.setCurrentMenu(0);
			}
			else if (user.getChoice() == 2) {
				float fireballDamage = user.fireball();
				if (fireballDamage > 5) {
					user.setHealth(user.getHealth() + fireballDamage);
					output.setText(">You hit the enemy with a fireball for " + to_string((int)fireballDamage));
				}
				else {
					output.setText(">Your fireball fizzled out");
				}
				options.setCurrentMenu(0);
			}
			user.setChoice(0);
			setIsPlayerTurn(false);
		}
	}
}

void gameLogic::enemyTurn() {
	if (isPlayerTurn == false) {
		if ((int)ofRandom(4) == 0) {
			generateEnemyChoice(4);
			if (enemy.getChoice() != 1) {
				generateEnemyChoice(2);
			}
			else {
				enemy.setChoice(0);
			}
		}
		if (enemy.getChoice() == 1) {
			float heavyAttackDamage = enemy.heavyAttack(user.getDefense());
			if (heavyAttackDamage != 0) {
				user.setHealth(user.getHealth() - heavyAttackDamage);
				output.setText(">The enemy hit you with a heavy attack for " + to_string((int)heavyAttackDamage));
			}
			else {
				output.setText(">The enemy missed");
			}
		}
		else if (enemy.getChoice() == 2) {
			float lightAttackDamage = enemy.lightAttack(user.getDefense());
			if (lightAttackDamage != 0) {
				user.setHealth(user.getHealth() - lightAttackDamage);
				output.setText(">The enemy hit you with a light attack for " + to_string((int)lightAttackDamage));
			}
			else {
				output.setText(">The enemy missed");
			}
		}
		else {
			enemy.increaseDefense(1);
			output.setText(">Enemy defense increased");
		}
	}
}

void gameLogic::updateHealthBars() {
	user.statsBar.healthBar.setHealth(user.getHealth());
	enemy.statsBar.healthBar.setHealth(enemy.getHealth());
	user.statsBar.setCurrentHealth(to_string((int)user.getHealth()));
	enemy.statsBar.setCurrentHealth(to_string((int)enemy.getHealth()));
}

void gameLogic::isGameOver() {
	if (user.getHealth() <= 0) {
		printf("Game Over:\n");
		printf("You lose...\n");
		printf("Music: Rishabh Agrawal");
		ofExit();
	}
	else if (enemy.getHealth() <= 0) {
		printf("Game Over:\n");
		printf("You win!\n");
		printf("Music: Rishabh Agrawal");
		ofExit();
	}
}
