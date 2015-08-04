
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //// WARNING: ALWAYS SET OFMAP TO "TRUE" TO CLAMP WHEN WORKING WITH AUDIO AND CAREFUL WEARING HEADPHONES OTHERWISE YOU CAN DAMAGE YOUR EARS ////

    
    ofBackground(50);
    
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
    
    triWave.setup(soundStream.getSampleRate(), soundStream.getBufferSize());
    triWave.setFrequency(440);
    
    sineWave.setup(soundStream.getSampleRate(), soundStream.getBufferSize());
    sineWave.setFrequency(220);
    
    
    env.set(0.9, 0.07); //these are both 0.0 - 1.0 anything above is dangerous
    //attack 0.0 - 1.0
    //release 0.0 - 1.0
    
    
    //setup ofxGui
    gui.setup("ofxGenSound");
    gui.add(freq1.setup("Triangle Wave Freq", 440, 220, 600));
    gui.add(freq2.setup("Sine Wave Freq", 220, 220, 600));
    gui.add(filterCutoff.setup("Filter Cutoff", 0.5, 0.0, 0.5));
    gui.add(delayFeedback.setup("Delay Feedback", 0.8, 0.0, 0.9));

    
    
    ofSetWindowTitle("ofxGenSound Example");
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //trigger an envelope
    
    env.trigger(ofGetKeyPressed());
    
    //control frequency
    
    triWave.setFrequency(freq1);
    sineWave.setFrequency(freq2);

    
    //control filter cutoff
    
    filter.setCutoff(filterCutoff);
    
    delay.setFeedback(delayFeedback);
    delay.setMix(0.5);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofVec2f vec = ofVec2f(0, ofGetHeight() * .5);
    drawWaveform(vec);
    gui.draw();
    ofDrawBitmapString("Press Any Key to Generate a Tone", ofGetWidth() * .10, ofGetHeight() * .25);
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    
    // This is your left and right speakers //
    
    float leftScale = -1.0;
    float rightScale = 1.0;
    
    // This runs through the audio buffer at the rate of the audioOut core audio event //
    
    for (int i = 0; i < bufferSize; i++){
        
        // Signal Chain //
        float waveOut = (triWave.setOscillatorType(OF_TRIANGLE_WAVE) + sineWave.setOscillatorType(OF_SINE_WAVE)) * env.addEnvelope();
        
        float filterOut = filter.addFilter(OF_FILTER_LP, waveOut);
        
        float delayOut = delay.addDelay(filterOut);
        
        
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
