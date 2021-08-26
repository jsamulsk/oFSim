#pragma once

#include "ofMain.h"
#include "gameClasses.h"

class ofApp : public ofBaseApp{
	public:
		gameLogic game;
		ofSoundPlayer music;

		void setup();
		void update();
		void draw();

		void mousePressed(int x, int y, int button);
};
