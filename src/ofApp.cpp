#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//gets music playing on a loop
	music.load("music/battlemusic.mp3");
	music.setLoop(true);
	music.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	game.perceptionCheck(); //creates enemy decision and tells player with 75% accuracy
	game.updatePlayerChoice(); //checks for player input
	game.updateOptions(); //changes menus and game based on player input
	game.enemyTurn(); //enemy takes turn
	game.updateHealthBars(); //changes healthbar and health displayed to match events of turn
	game.isGameOver(); //checks if game is over, who won, and exits
}

//--------------------------------------------------------------
void ofApp::draw(){
	game.drawGame(); //draws
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	game.options.updateIsClicked(x, y); //checks if click was in a button and records which one if so
}
