#pragma once

#include "ofMain.h"

enum filterType { OF_FILTER_LP, OF_FILTER_HP, OF_FILTER_BP };


class ofxGenSoundFilter {
    
public:
    ofxGenSoundFilter();
    ~ofxGenSoundFilter();
    float addFilter(filterType filter, float input);
    void setCutoff(float amount);
    void setResonance(float amount);
    void setAmp(float level);
  
    
private:

    float output, _cutoff;
    float outputs[2];
    
};
