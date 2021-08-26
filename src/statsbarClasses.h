#pragma once
#include "ofMain.h"

class healthbar {
private:
	int health;
	ofPoint location;

	ofRectangle rect;
	ofColor color;
	ofImage heartImage;
public:
	healthbar();

	void setHealth(int _health);
	void setLocation(float x, float y);

	int gethealth();
	ofPoint getLocation();

	void draw(); //based on health
};

class statsbar {
private:
	string currentHealth;
	string level;
	ofRectangle rect;
	ofPoint location;
	string name;

	ofImage backgroundImage;
public:
	statsbar();

	healthbar healthBar;

	void setCurrentHealth(string newHealth);
	void setLevel(string newLevel);
	void setLocation(float x, float y);
	void setName(string newName);

	string getCurrentHealth();
	string getLevel();
	ofPoint getLocation();
	string getName();

	void drawStatsbar(); //health number based on currentHealth
};

