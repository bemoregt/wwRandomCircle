#include "ofApp.h"

using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){

    string filepath= "/Users/mun/Desktop/test.png";
    image1.load(filepath);
    
    isFind=false;
    
}

//--------------------------------------------------------------
void ofApp::update(){

    int x, y;
    int colsum=0;
    
    if(isFind == false) {

        radius = (int)ofRandom(5,8);
        //ofLog() << radius;
        cx= (int)ofRandom(507);
        cy= (int)ofRandom(324);
        
        if(cx <50) cx=50;
        if(cx > (457) ) cx=457;
        if(cy <50) cy=50;
        if(cy > (274) ) cy=274;
        
        for(float theta=0; theta < 6.28; theta += 0.628){
            x= (int)(radius*cos(theta) + cx);
            y= (int)(radius*sin(theta) + cy);
            ofColor col= image1.getColor(x, y);
            colsum += col.getBrightness();
        }
        
        if(colsum > 690){
            isFind= true;
        }
    }//if isFind
}

//--------------------------------------------------------------
void ofApp::draw(){

    //
    ofSetColor(255, 255, 255);
    image1.draw(0, 0, 507, 324);
    
    if(isFind ==true) {
        //
        ofSetColor(0, 255, 0);
        ofNoFill();
        ofDrawCircle(cx, cy, radius);
        //ofLog() << "center_x= " << cx << ", center_y= " << cy << ", radius= " << radius;
        
        // filled box
        ofSetColor(10, 10, 10);
        ofFill();
        ofDrawRectangle(5, 5, 200, 80);
        //
        ofSetColor(255);
        ofDrawBitmapString("Center_X= " + ofToString(cx), 20, 30);
        ofDrawBitmapString("Center_Y= " + ofToString(cy), 20, 50);
        ofDrawBitmapString("Radius= " + ofToString(radius), 20, 70);
        
    }else{
        ofSetColor(255, 0, 0);
        ofNoFill();
        ofDrawCircle(cx, cy, radius);
    }
    
    // if find== true, draw circle.
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
