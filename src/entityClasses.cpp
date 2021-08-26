#include "entityClasses.h"

entity::entity() {
	health = 100;
	name = "Name";
	location.x = 0;
	location.y = 0;

	figure.load("images/stickfigure.png");
}

void entity::setHealth(float _health) {
	health = _health;
}

void entity::setLocation(float x, float y) {
	location.x = x;
	location.y = y;
}

string entity::getName()
{
	return name;
}

ofPoint entity::getLocation()
{
	return location;
}

float entity::getHealth()
{
	return health;
}

void entity::drawEntity() {
	figure.draw(location.x, location.y, 200, 200);
}

void entity::setFileLocation(string fileLocation) {
	figure.load(fileLocation);
}
