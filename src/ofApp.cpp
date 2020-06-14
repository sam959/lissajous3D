#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
	ofBackground(5, 20, 30);

	ofSetSmoothLighting(true);
	pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
	pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));

    // VBO
    ofSpherePrimitive tempSphere;
    tempSphere.setRadius(6);
    tempSphere.setResolution(6);

    vboSphere = tempSphere.getMesh();
    mShdInstanced = shared_ptr<ofShader>(new ofShader());
    mShdInstanced->load("shaders/instanced.vert", "shaders/instanced.frag");

    numberOfElements = 600;
    freqX = 1.0;
    freqY = 1.0;
    freqZ = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
	pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), ofGetHeight()/2, 500);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    ofDisableAlphaBlending();
    ofSetColor(ofColor::yellow);
    mCamMain.begin();
    ofDrawBitmapString("Frequency X: " + ofToString(freqX), 10, 20);
    ofDrawBitmapString("Frequency Y: " + ofToString(freqY), 10, 40);
    ofDrawBitmapString("Frequency Z: " + ofToString(freqZ), 10, 60);


    // bind the shader
	mShdInstanced->begin();
	// feed the shader a normalized float value that changes over time, to animate things a little
	mShdInstanced->setUniform1f("timeValue", (ofGetElapsedTimeMillis() % 30000) / 30000.0f);
    mShdInstanced->setUniform1f("freqX", freqX);
    mShdInstanced->setUniform1f("freqY", freqY);
    mShdInstanced->setUniform1f("freqZ", freqZ);
    mShdInstanced->setUniform1i("numberOfElements", numberOfElements);

    // we only want to render triangles facing the camera.
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	vboSphere.drawInstanced(OF_MESH_FILL, numberOfElements*numberOfElements);

	glDisable(GL_CULL_FACE);
	mShdInstanced->end();

    mCamMain.end();
	ofDisableDepthTest();
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_UP){
        freqX++;
    } else if(key== OF_KEY_DOWN){
        freqX--;
    } else if(key == OF_KEY_RIGHT){
        freqY++;
    } else if (key == OF_KEY_LEFT){
        freqY--;
    }else if (key == 'w'){
        freqZ++;
    }else if (key == 's'){
        freqZ--;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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