#pragma once

#include "ofMain.h"

enum oscType { OF_SINE_WAVE, OF_TRIANGLE_WAVE, OF_SAWTOOTH_WAVE, OF_SQUARE_WAVE, OF_NOISE_WAVE, OF_PHASOR_WAVE };

class ofxGenSoundOsc {
    
public:
    ofxGenSoundOsc();
    ~ofxGenSoundOsc();
    void setup(int samplerate, int buffersize);
    float setOscillatorType(oscType waveformType);
    void setFrequency(float freq);
    void setAmp(float amount);
    void setPhase(float phaseAmount);
    void addSignal(float signal);
    void multiSignal(float signal);
   
protected:
    int _samplerate;
    
private:
    
    int _buffersize;
    float _frequency, _phase;
    float _sine, _tri, _noise, _saw, _square, _phasor;
    
};
