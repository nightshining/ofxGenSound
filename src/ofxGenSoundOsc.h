#pragma once

#include "ofMain.h"

enum oscType { OF_SINE_WAVE, OF_TRIANGLE_WAVE, OF_SAWTOOTH_WAVE, OF_SQUARE_WAVE, OF_NOISE_WAVE, OF_PHASOR_WAVE };

class ofxGenSoundOsc {
    
public:
    ofxGenSoundOsc();
    ~ofxGenSoundOsc();
    void setup(int samplerate, int buffersize);
    double setOscillatorType(oscType waveformType);
    void setFrequency(double freq);
    void setAmp(double amount);
    void setPhase(double phaseAmount);
    void addSignal(double signal);
    void multiSignal(double signal);
   
protected:
    int _samplerate;
    
private:
    
    int _buffersize;
    double _frequency, _phase;
    double _sine, _tri, _noise, _saw, _square, _phasor;
    
};
