
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //// WARNING: ALWAYS SET "TRUE" TO CLAMP WHEN WORKING WITH AUDIO AND CAREFUL WEARING HEADPHONES OTHERWISE YOU CAN DAMAGE YOUR EARS ////

    
    ofBackground(75);
    
    // 2 output channels,
    // 0 input channels
    // 22050 samples per second
    // 512 samples per buffer
    // 4 num buffers (latency)
    
    int bufferSize		= 512;
    sampleRate 			= 44100;
    audioOutLeft.resize(bufferSize);
    audioOutRight.resize(bufferSize);
    
    soundStream.setup(this, 2, 0, sampleRate, bufferSize, 4);
    
    pan = 1.0;
    
    // Set up one oscillator but passing in sample rate and buffersize //
    // Set intial oscillator frequency //
    // Set envelope parameters //
    
    oscillator.setup(soundStream.getSampleRate(), soundStream.getBufferSize());
    oscillator.setFrequency(440);
    
    env.set(0.9, 0.07); //these are both 0.0 - 1.0 anything above is dangerous
    //attack 0.0 - 1.0
    //release 0.0 - 1.0
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //trigger an envelope
    
    env.trigger(ofGetKeyPressed());
    
    //control frequency
    
    oscillator.setFrequency(ofMap(ofGetMouseX(), 0, ofGetWidth(), 50, 440, true));
    
    //control filter cutoff
    
    filter.setCutoff(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0.0, 0.5, true));
    
    delay.setFeedback(0.50);
    delay.setMix(0.50);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofVec2f vec = ofVec2f(0, ofGetHeight() * .5);
    drawWaveform(vec);
    
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    
    // This is your left and right speakers //
    
    float leftScale = -1.0;
    float rightScale = 1.0;
    
    // This runs through the audio buffer at the rate of the audioOut core audio event //
    
    for (int i = 0; i < bufferSize; i++){
        
        // Signal Chain //
        float waveformOut = oscillator.setOscillatorType(OF_SAWTOOTH_WAVE) * env.addEnvelope();
        
        float filterOut = filter.addFilter(OF_FILTER_LP, waveformOut);
        
        float delayOut = delay.processSignal(filterOut);
        
        
        // Output Sound //
        audioOutRight[i] = output[ i * nChannels    ] = delayOut * rightScale;
        audioOutLeft[i] = output[ i * nChannels + 1 ] = delayOut * leftScale;
        
    }
    
}

void ofApp::drawWaveform(ofVec2f& position) {
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(position);
    ofColor c = c.turquoise;
    ofSetColor(c);
    ofNoFill();
    ofBeginShape();
    
    for (int i = 0; i < audioOutRight.size(); i++) {
        ofVertex(i * 5, audioOutRight[i] * 100 );
    }
    ofEndShape();
    
    ofPopMatrix();
    ofPopStyle();
    
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
