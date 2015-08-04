#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(ofColor::whiteSmoke);
    ofSetCircleResolution(60);
    
    int bufferSize		= 512;
    sampleRate 			= 44100;
    audioOutLeft.resize(bufferSize);
    audioOutRight.resize(bufferSize);
    
    soundStream.setup(this, 2, 0, sampleRate, bufferSize, 4);
    
    //Panning//
    
    pan = 1.0;
    
    //Volume//
    
    volume = 0.1f;

    triWave.setup(soundStream.getSampleRate(), soundStream.getBufferSize());
    
    triWave.setFrequency(440);
    
    phasorWave.setup(soundStream.getSampleRate(), soundStream.getBufferSize());
    
    phasorWave.setFrequency(440);
    
    squareWave.setup(soundStream.getSampleRate(), soundStream.getBufferSize());
    
    squareWave.setFrequency(440);
    
    env.set(0.15, 0.10); //these are both 0.0 - 1.0 anything above is dangerous
    //attack 0.0 - 1.0
    //release 0.0 - 1.0
    
    int cirAmt = 8;
    alphas.assign(cirAmt, 0.0);
    notes.resize(cirAmt);
    
    notes[0] = 440;
    notes[1] = 490;
    notes[2] = 523;
    notes[3] = 622;
    notes[4] = 164;
    notes[5] = 174;
    notes[6] = 440;
    notes[7] = 622;
    
    rampTrigger = false;
    sequence = 0;
    

    clickPos.set(ofGetWidth() * .25, ofGetHeight() * .20);

    buttonRadius = 30;
    buttonC = ofColor::salmon;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    if (ofGetElapsedTimef() >= 2.0) {
    
    filter.setCutoff(0.25);
    
    
    //ofxControlUtils

    if (control.ticker(true, clickPos.x)) {
        
        env.trigger(true);
        rampTrigger = true;
        
        sequence = control.counter(true, notes.size() - 1);
        triWave.setFrequency(notes[sequence]);
        phasorWave.setFrequency(notes[sequence] * .5);
    
        squareWave.setFrequency(notes[sequence] * 0.75);
        
        //Careful with this one it was doing a loud popping
        // squareWave.setFrequency(notes[sequence] * ofMap(ofGetMouseY(), 0, ofGetHeight(), 1.0, 0.0, true));

    
    } else {
        
        env.trigger(false);
        rampTrigger = false;
    }
    
    
    int alphaOn = ofMap(control.rampToggle(rampTrigger, 1.0, 0.25), 0.0, 1.0, 0, 255);
    
    alphas[sequence] = alphaOn;
    
    }
    
    if (ofDist(ofGetMouseX(), ofGetMouseY(), clickPos.x, clickPos.y) <= buttonRadius * 2) {
       
        buttonC.lerp(ofColor::lightCoral, 0.25);
        resetPos = true;
    
    } else {
        
        buttonC.lerp(ofColor::black, 0.25);
        resetPos = false;
    }
        
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < alphas.size(); i++) {
    ofSetColor(25, 25, 25, alphas[i]);
    ofCircle(ofGetWidth() * .15 + i * 100, ofGetHeight() * .5, 35);
    }
    
    ofSetColor(buttonC);
    ofCircle(clickPos, buttonRadius);
  
    ofDrawBitmapString("Ticker Speed: " + ofToString(clickPos.x) + "ms", clickPos.x * .15, clickPos.y);
}
//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    
    // This is your left and right speakers //
    
    float leftScale = -1.0;
    float rightScale = 1.0;
    
    // This runs through the audio buffer at the rate of the audioOut core audio event //
    
    for (int i = 0; i < bufferSize; i++){
        
        // Signal Chain //
        float waveOut = ( squareWave.setOscillatorType(OF_SQUARE_WAVE) + triWave.setOscillatorType(OF_TRIANGLE_WAVE) * phasorWave.setOscillatorType(OF_PHASOR_WAVE)) * env.addEnvelope();
        
        float filterOut = filter.addFilter(OF_FILTER_LP, waveOut);
        
        
        // Output Sound //
        audioOutRight[i] = output[ i * nChannels    ] = filterOut * volume * rightScale;
        audioOutLeft[i] = output[ i * nChannels + 1 ] = filterOut * volume * leftScale;
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
   

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    if (resetPos) {
        
        clickPos.x = ofClamp(x, ofGetWidth() *.25, ofGetWidth() * .75);
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

  
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
  
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
