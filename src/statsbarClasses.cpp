#include "statsbarClasses.h"

//healthbar
healthbar::healthbar() {
	rect.width = 300;
	rect.height = 50;
	heartImage.load("images/heart.png");
}

void healthbar::setHealth(int _health) {
	health = _health;

}

void healthbar::setLocation(float x, float y) {
	location.set(x, y);
	rect.setPosition(location);
}

int healthbar::gethealth() {
	return health;
}

ofPoint healthbar::getLocation() {
	return location;
}

void healthbar::draw() {
	ofFill();
	ofSetColor(255);
	ofDrawRectangle(rect);
	ofSetColor(255, 0, 0);
	ofDrawRectangle(rect.x, rect.y, ((float) health / 100)*rect.width, rect.height);
	ofNoFill();
	ofSetLineWidth(3);
	ofSetColor(0);
	ofDrawRectangle(rect);
	ofSetColor(255);
	heartImage.draw(rect.x - 15, rect.y - 10, 50, 70);
	
}

//statsbar
statsbar::statsbar()
{
	name = "name";
	rect.width = 400;
	rect.height = 100;
	currentHealth = "100";
	level = "1";
	backgroundImage.load("images/statsbarBackground.jpg");
}

void statsbar::setCurrentHealth(string newHealth)
{
	currentHealth = newHealth;
}

void statsbar::setLevel(string newLevel)
{
	level = newLevel;
}

void statsbar::setLocation(float x, float y)
{
	location.set(x, y);
	rect.setPosition(location);
	healthBar.setLocation(location.x + 10, location.y +40);

}

void statsbar::setName(string newName)
{
	name = newName;
}

string statsbar::getCurrentHealth()
{
	return currentHealth;
}

string statsbar::getLevel()
{
	return level;
}

ofPoint statsbar::getLocation()
{
	return location;
}

string statsbar::getName()
{
	return name;
}

void statsbar::drawStatsbar()
{
	ofFill();
	ofSetColor(255);
	backgroundImage.draw(rect.x, rect.y, rect.width, rect.height);
	ofNoFill();
	ofSetColor(0);
	ofSetLineWidth(3);
	ofDrawRectangle(rect);
	healthBar.draw();
	ofSetColor(0);
	ofDrawBitmapString(name,location.x+10,location.y+30);
	ofDrawBitmapString("Level: "+ level, location.x + 320, location.y + 30);
	ofDrawBitmapString(currentHealth + "/100", location.x + 320, location.y + 65);
	ofSetColor(255);
}
