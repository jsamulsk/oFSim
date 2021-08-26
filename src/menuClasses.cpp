#include "menuClasses.h"

//button
button::button() {
	label = "Button";
	location.x = 0;
	location.y = 0;
	background.set(location, 180, 80);
	isClicked = false;
	buttonBackground.load("images/buttons.png");
}

ofPoint button::getLocation() {
	return location;
}

string button::getLabel() {
	return label;
}

bool button::getIsClicked() {
	return isClicked;
}

void button::setLocation(ofPoint _location) {
	location = _location;
	background.setPosition(_location);
}

void button::setLabel(string _label) {
	label = _label;
}

void button::setIsClicked(bool _isClicked) {
	isClicked = _isClicked;
}

void button::drawButton() {
	ofFill();
	ofSetColor(255);
	buttonBackground.draw(background.x, background.y, background.width, background.height);
	
	ofPoint newCenter = background.getCenter();
	newCenter.x -= 4 * label.length();
	ofDrawBitmapString(label, newCenter);
	
}

bool button::isInside(float x, float y) {
	if ((x <= background.x + background.width) && (x >= background.x)) {
		if ((y <= background.y + background.height) && (y >= background.y)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

//textPrint
textPrint::textPrint() {
	background.setHeight(200);
	background.setWidth(410);
	drawSurface.set(background.x + 10, background.y + 10, 380, 180);
}

ofPoint textPrint::getLocation() {
	return location;
}

string textPrint::getText(int n) {
	return text[n];
}

void textPrint::setLocation(float w, float h) {
	location.set(0, h - 200);
	background.setPosition(location);
	drawSurface.set(background.x + 10, background.y + 10, 390, 180);
}

void textPrint::setText(string newText) {
	text.push_back(newText);
}

void textPrint::drawTextPrint() {
	ofFill();
	ofSetColor(100);
	ofDrawRectangle(background);
	ofNoFill();
	ofSetColor(0);
	ofSetLineWidth(3);
	ofDrawRectangle(background);
	ofFill();
	ofDrawRectangle(drawSurface);
	ofSetColor(255);
	for (int i = text.size(); i > 0; i--) {
		ofDrawBitmapString(text[i - 1], drawSurface.x + 5, (drawSurface.y + 15) + 15 * (text.size() - i));
	}
	ofSetColor(100);
	ofSetLineWidth(1);
	ofDrawLine(drawSurface.x, drawSurface.y + 18, drawSurface.x + drawSurface.width, drawSurface.y + 18);
	ofDrawLine(drawSurface.x, drawSurface.y + 48, drawSurface.x + drawSurface.width, drawSurface.y + 48);
	ofSetColor(255);
}

//menu
menu::menu() {
	background.width = 410;
	background.height = 200;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ofPoint _location = location;
			_location.x += (j * 180) + 25;
			_location.y += (i * 80) + 20;
			buttons[i][j].setLocation(_location);
		}
	}
	currentMenu = 0;
	menuBackground.load("images/menuBackground.png");
}

ofPoint menu::getLocation() {
	return location;
}

int menu::getCurrentMenu() {
	return currentMenu;
}

void menu::setLocation(float w, float h) {
	location.set(w - 410, h - 200);
	background.setPosition(location);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ofPoint _location = location;
			_location.x += (j * 180) + 25;
			_location.y += (i * 80) + 20;
			buttons[i][j].setLocation(_location);
		}
	}

}

void menu::setCurrentMenu(int newMenu) {
	currentMenu = newMenu;
}

void menu::drawMenu() {
	ofFill();
	ofSetColor(255);
	menuBackground.draw(background.x, background.y, background.width, background.height);
	ofNoFill();
	ofSetColor(0);
	ofSetLineWidth(3);
	ofDrawRectangle(background);
	ofFill();

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			buttons[i][j].drawButton();
		}
	}
}

void menu::updateIsClicked(float x, float y) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (buttons[i][j].isInside(x, y)) {
				buttons[i][j].setIsClicked(true);
			}
		}
	}
}

int menu::whichButton() {
	if (buttons[0][0].getIsClicked() == true) {
		return 1;
	}
	else if (buttons[0][1].getIsClicked() == true) {
		return 2;
	}
	else if (buttons[1][0].getIsClicked() == true) {
		return 3;
	}
	else if (buttons[1][1].getIsClicked() == true) {
		return 4;
	}
}

void menu::resetButtons() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			buttons[i][j].setIsClicked(false);
		}
	}
}