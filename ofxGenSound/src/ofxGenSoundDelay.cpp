
#include "ofxGenSoundDelay.h"


ofxGenSoundDelay::ofxGenSoundDelay() {
    
    memset( memory, 0, 88200 * sizeof (float) );
    phase = 0.0;
    output = 0.0;
    frequency = 0.0;
    startphase = 0.0;
    endphase = 0.0;
    
}

ofxGenSoundDelay::~ofxGenSoundDelay() {
    
    
}

float ofxGenSoundDelay::dl(float input, int size, float feedback)  {
    
    if ( phase >= size ) {
        phase = 0;
    }
    output = memory[phase];
    memory[phase] = ( memory[phase] * feedback) + (input * feedback) * 0.5;
    phase += 1;
    return output;
    
}

float ofxGenSoundDelay::dl(float input, int size, float feedback, int position)  {
    if ( phase >=size ) phase = 0;
    if ( position >=size ) position = 0;
    output=memory[position];
    memory[phase] = (memory[phase] * feedback) + (input * feedback) * 0.5;
    phase += 1;
    return output;
    
}