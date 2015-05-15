
#include "ofxGenSoundDelay.h"


ofxGenSoundDelay::ofxGenSoundDelay() {
    
    int defaultSampleRate = 4410;
    setup(defaultSampleRate);
    feedback = 0.5f;
    mix = 0.5f;
}

ofxGenSoundDelay::~ofxGenSoundDelay() {
    
    
}

void ofxGenSoundDelay::setup(int sampleRate) {
    buffer.resize(sampleRate);
    buffer.assign(sampleRate, 0);
    pos = 0;
    
}


void ofxGenSoundDelay::setMix(float amt) {
    mix = amt;
}

    
void ofxGenSoundDelay::setFeedback(float feedbackAmt) {
    feedback = feedbackAmt;
}

float ofxGenSoundDelay::processSignal(float input) {
    pos++;
    pos %= buffer.size();
    float out = buffer[pos];
    buffer[pos] = feedback * buffer[pos] + input;
    return input + (out - input) * mix;
};
