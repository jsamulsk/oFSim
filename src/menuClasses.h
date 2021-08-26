#pragma once
#include "ofMain.h"

class button {
private:
	ofPoint location;
	string label;
	bool isClicked;

	ofRectangle background;
	ofImage buttonBackground;
public:
	button();

	ofPoint getLocation();
	string getLabel();
	bool getIsClicked();

	void setLocation(ofPoint _location);
	void setLabel(string _label);
	void setIsClicked(bool _isClicked);

	void drawButton();
	bool isInside(float x, float y); //checks if coordinates are inside of button
};

class textPrint {
private:
	ofPoint location;
	vector<string> text;

	ofRectangle background;
	ofRectangle drawSurface;
public:
	textPrint();

	ofPoint getLocation();
	string getText(int n);

	void setLocation(float w, float h);
	void setText(string newText);

	void drawTextPrint(); //draws most recent text on top and rest going down
};

class menu {
private:
	ofRectangle background;
	ofPoint location;
	int currentMenu;
	ofImage menuBackground;
public:
	menu();

	button buttons[2][2];

	ofPoint getLocation();
	int getCurrentMenu();

	void setLocation(float x, float y);
	void setCurrentMenu(int newMenu);

	void drawMenu();
	void updateIsClicked(float x, float y); //if buttons[i][j].isInside(x, y) then set buttons[i][j].isClicked to true
	int whichButton(); //turns boolean isClicked for a button to a corresponding number 1 through 4
	void resetButtons(); //clears all isClicked
};