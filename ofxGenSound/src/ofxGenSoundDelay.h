#pragma once

#include "ofMain.h"
#include "ofxGenSoundOsc.h"

class ofxGenSoundDelay {

public:

    ofxGenSoundDelay();
    ~ofxGenSoundDelay();
   
    float dl(float input, int size, float feedback);
    float dl(float input, int size, float feedback, int position);
    
private:
    float frequency;
    int phase;
    float startphase;
    float endphase;
    float output;
    float memory[88200];
    
/*
public:
    ofxGenSoundDelay();
    ~ofxGenSoundDelay();
    void process(float time, float feedback);
    void setDelayTime(float time);
    void setDelayFeedback(float amount);
    
private:
*/

};

