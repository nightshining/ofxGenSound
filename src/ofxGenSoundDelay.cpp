
#include "ofxGenSoundDelay.h"


ofxGenSoundDelay::ofxGenSoundDelay() {
    
    memset( memory, 0, 88200 * sizeof (double) );
    phase = 0.0;
    output = 0.0;
    frequency = 0.0;
    startphase = 0.0;
    endphase = 0.0;
    feedback = 0.0;
    
}

ofxGenSoundDelay::~ofxGenSoundDelay() {
    
    
}

double ofxGenSoundDelay::addDelay( double input, int size )  {
    
    if ( phase >= size ) {
        phase = 0;
    }
    output = memory[phase];
    memory[phase] = ( memory[phase] * feedback) + (input * feedback) * 0.5;
    phase += 1;
    return output;
    
}

void ofxGenSoundDelay::setDelayFeedback(double amount) {
    
    feedback = amount;
    
}