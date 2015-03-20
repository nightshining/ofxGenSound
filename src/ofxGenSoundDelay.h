#pragma once

#include "ofMain.h"
#include "ofxGenSoundOsc.h"

class ofxGenSoundDelay {

public:

    ofxGenSoundDelay();
    ~ofxGenSoundDelay();
   
    double addDelay(double input, int size);
    void setDelayFeedback(double amount);
    void setDelayTime(double amount);
    
private:
    double frequency;
    double feedback;
    int phase;
    double startphase;
    double endphase;
    double output;
    double memory[88200];
    


};

