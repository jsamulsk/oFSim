#pragma once
#include "ofMain.h"

class entity {
private:
	string name;
	ofPoint location;
	float health;

	ofImage figure;
public:
	entity();
	
	void setHealth(float _health);
	void setLocation(float x, float y);

	string getName();
	ofPoint getLocation();
	float getHealth();

	void drawEntity(); //draws saved image
	void setFileLocation(string fileLocation); //sets image location of figure
};
