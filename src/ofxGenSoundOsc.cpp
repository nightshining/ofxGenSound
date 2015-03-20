
#include "ofxGenSoundOsc.h"


ofxGenSoundOsc::ofxGenSoundOsc() {
    
    _frequency = 440.0;
    _phase = 100.0;
    _sine = 0.0;
    _noise = 0.0;
}

ofxGenSoundOsc::~ofxGenSoundOsc() {
    
    
}

void ofxGenSoundOsc::setup(int samplerate, int buffersize) {
    
    _samplerate = samplerate;
    _buffersize = buffersize;
    
}

double ofxGenSoundOsc::setOscillatorType(oscType waveformType) {
 

    switch (waveformType) {
            
        case OF_SINE_WAVE:
            
            _sine = sin (_phase * (TWO_PI));
            if ( _phase >= 1.0 ) _phase -= 1.0;
            _phase += ( 1. / ( _samplerate / (_frequency) ) );
            return _sine;
            break;
            
        case OF_TRIANGLE_WAVE:

            if ( _phase >= 1.0 ) _phase -= 1.0;
            _phase += (1./(_samplerate/(_frequency)));
            if (_phase <= 0.5 ) {
                _tri = (_phase - 0.25) * 4;
            } else {
                _tri =((1.0 - _phase) - 0.25) * 4;
            }
            return _tri;
            break;
            
        case OF_SAWTOOTH_WAVE:
            
            _saw = _phase;
            
            if ( _phase >= 1.0 ) _phase -= 2.0;
            
            _phase += (1./(_samplerate/(_frequency)));
            
            return _saw;
            break;
            
        case OF_SQUARE_WAVE:
            
            if (_phase<0.5) _square=-1;
            
            if (_phase>0.5) _square=1;
            
            if ( _phase >= 1.0 ) _phase -= 1.0;
            
            _phase += (1./(_samplerate/(_frequency)));
            
            return _square;
            break;
            
        case OF_PHASOR_WAVE:
            
            _phasor = _phase;
            
            if ( _phase >= 1.0 ) _phase -= 1.0;
            
            _phase += (1./(_samplerate/(_frequency)));
            
            return _phasor;
            break;
            
        case OF_NOISE_WAVE:
            _noise = ofRandom(0, 1);
            return _noise;
            break;
            
        default:
            return 0;
            break;
    }
    
}

void ofxGenSoundOsc::setFrequency(double freq) {
    
    _frequency = freq;
}

void ofxGenSoundOsc::setAmp(double amount) {
    
    
}

void ofxGenSoundOsc::setPhase(double phaseAmount) {
    
    _phase = phaseAmount;
}

void ofxGenSoundOsc::addSignal(double signal) {
    
    return signal;
    
}

void ofxGenSoundOsc::multiSignal(double signal) {
    
    
}






