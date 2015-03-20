
#include "ofxGenSoundEnvelope.h"


ofxGenSoundEnvelope::ofxGenSoundEnvelope() {
    
    volume = 0.0;

}

ofxGenSoundEnvelope::~ofxGenSoundEnvelope() {
    
    
}

void ofxGenSoundEnvelope::set(float _attack, float _release) {
   
    attack = _attack; //0.0 - 1.0 slow to fast attack
    release = _release; //0.0 - 1.0 slow to fast fade
    
}

void ofxGenSoundEnvelope::trigger(bool trigger) {
    
    if(trigger) {
        volume = ofLerp(volume, 1.0, attack); // jump quickly to 1
    } else {
        volume = ofLerp(volume, 0.0, release); // fade slowly to 0
    }
    
}

float ofxGenSoundEnvelope::addEnvelope() {
    
    return volume;
    
    
}