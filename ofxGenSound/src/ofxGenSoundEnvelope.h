#pragma once

#include "ofMain.h"

class ofxGenSoundEnvelope {
    
public:
    ofxGenSoundEnvelope();
    ~ofxGenSoundEnvelope();
    void set(float _attack, float _release);
    void trigger(bool trigger);
    float addEnvelope();
    
private:
    
    float volume;
    float attack, release;
};
