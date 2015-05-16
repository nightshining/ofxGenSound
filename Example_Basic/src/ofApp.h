#pragma once

#include "ofMain.h"
#include "ofxGenSound.h"
#include "ofxGui.h"

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
    void drawWaveform(ofVec2f& position);

    //ofxGenSound
    
    ofxGenSoundOsc triWave, sineWave;
    ofxGenSoundEnvelope env;
    ofxGenSoundDelay delay;
    ofxGenSoundFilter filter;

    //GUI
    ofxPanel gui;
    ofxFloatSlider freq1, freq2, filterCutoff, delayFeedback;
};

/*
 Example: 
 
 - Press any key to generate a tone.
 
 - Move the mouse left and right to change frequency.
 
 - Move the mouse up and down to change filter.
 
 */
