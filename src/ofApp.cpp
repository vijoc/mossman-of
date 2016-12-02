#include "ofApp.h"
#include "scenes/boids/boidsScene.hpp"

float t;
BoidsScene* b;
//--------------------------------------------------------------
void ofApp::setup(){
	t = 0.0f;
	ofBackground(255, 255, 255);
	b = new BoidsScene();
}

//--------------------------------------------------------------
void ofApp::update(){
	t += 0.03f;
	b->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0, 0, 0);
	ofDrawCircle(100, 100, 10.0 + sin(t)*10.0);
	b->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
