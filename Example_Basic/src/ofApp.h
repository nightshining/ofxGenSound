#pragma once

#include "ofMain.h"
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
    void drawWaveform(ofVec2f& position);
    
    ofxGenSoundOsc oscillator;
    ofxGenSoundEnvelope env;
    ofxGenSoundDelay delay;
    ofxGenSoundFilter filter;
    
    float sine;
    
    
};

/*
 Example: 
 */
