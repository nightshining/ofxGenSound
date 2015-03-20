
#include "ofxGenSoundFilter.h"


ofxGenSoundFilter::ofxGenSoundFilter() {
    
    output = 0.0;
    _cutoff = 0.0;
    outputs[0] = 0.0;
    outputs[1] = 0.0;
}

ofxGenSoundFilter::~ofxGenSoundFilter() {
    
    
}

float ofxGenSoundFilter::addFilter(filterType filter, float input) {
    
    switch (filter) {
        case OF_FILTER_LP:
            output = outputs[0] + _cutoff * (input-outputs[0]);
            outputs[0] = output;
            return output;
            break;
            
        case OF_FILTER_HP:
            output = input - (outputs[0] + _cutoff * (input - outputs[0]));
            outputs[0] = output;
            return output;
            break;
            
        case OF_FILTER_BP:
            break;
        default:
            break;
    }
}

void ofxGenSoundFilter::setCutoff(float amount) {
    
    _cutoff = amount;
}

void ofxGenSoundFilter::setResonance(float amount) {
    
    
}

void ofxGenSoundFilter::setAmp(float level) {
    
    
    
}

