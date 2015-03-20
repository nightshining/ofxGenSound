
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
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
    
    
    oscillator.setup(soundStream.getSampleRate(), soundStream.getBufferSize());
    oscillator.setFrequency(440);
    
    env.set(0.005, 0.07); //these are both 0.0 - 1.0 anything above is dangerous
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    env.trigger(ofGetKeyPressed());
    
    oscillator.setFrequency(ofMap(ofGetMouseX(), 0, ofGetWidth(), 50, 440, true));
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofVec2f vec = ofVec2f(0, ofGetHeight() * .5);
    drawWaveform(vec);
    
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    
    
    float leftScale = -1.0;
    float rightScale = 1.0;
    
    for (int i = 0; i < bufferSize; i++){
        float waveform = oscillator.setOscillatorType(OF_TRIANGLE_WAVE) * env.addEnvelope();
        
        audioOutRight[i] = output[ i * nChannels    ] = waveform * leftScale;
        audioOutLeft[i] = output[ i * nChannels + 1 ] = waveform * rightScale;
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
