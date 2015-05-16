#pragma once

#include "ofMain.h"
#include "ofxGenSoundOsc.h"

class ofxGenSoundDelay {

public:

    ofxGenSoundDelay();
    ~ofxGenSoundDelay();
    void setup(int sampleRate);
    void setMix(float amt);
    void setFeedback(float feedbackAmt);
    float addDelay(float input);

private:
  
    vector<float> buffer;
    int pos;
    
    float feedback;
    float mix;
};




