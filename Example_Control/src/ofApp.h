
////////
//Created by M.Romeo 2015//
//This Example uses another addon utility//
//ofxControlUtils//
//https://github.com/nightshining/ofxControlUtils//
////////

#pragma once

#include "ofMain.h"
#include "ofxControlUtils.h"
#include "ofxGenSound.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    void audioOut(float * input, int bufferSize, int nChannels);
    
    ofSoundStream soundStream;
    int sampleRate;
    vector <float> audioOutLeft;
    vector <float> audioOutRight;
    float pan;
    float volume;
    
    //ofxGenSound
    
    ofxGenSoundOsc triWave, phasorWave, squareWave;
    ofxGenSoundEnvelope env;
    ofxGenSoundFilter filter;

    
    //ofxControlUtils
    ofxControlUtils control;
    
    vector<float> alphas;
    vector<int> notes;
    
    bool rampTrigger;
    int sequence;
    
    //gui
    ofPoint clickPos;
    bool resetPos;
    ofColor buttonC;
    int buttonRadius;
    
};
