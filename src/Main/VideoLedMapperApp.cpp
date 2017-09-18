/*
 *  VideoLedMapperApp.cpp
 *  Video Led Mapper
 *
 *  Created by Imanol Gomez on 18/09/17.
 *
 */


#include "AppManager.h"

#include "VideoLedMapperApp.h"

//--------------------------------------------------------------
void VideoLedMapperApp::setup(){
    AppManager::getInstance().setup();
}

//--------------------------------------------------------------
void VideoLedMapperApp::update(){
    AppManager::getInstance().update();
}

//--------------------------------------------------------------
void VideoLedMapperApp::draw(){
    AppManager::getInstance().draw();
}

void VideoLedMapperApp::exit()
{
    ofLogNotice() <<"VideoLedMapperApp::exit";

}

//--------------------------------------------------------------
void VideoLedMapperApp::keyPressed(int key){

}

//--------------------------------------------------------------
void VideoLedMapperApp::keyReleased(int key){

}

//--------------------------------------------------------------
void VideoLedMapperApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void VideoLedMapperApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void VideoLedMapperApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void VideoLedMapperApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void VideoLedMapperApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void VideoLedMapperApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void VideoLedMapperApp::dragEvent(ofDragInfo dragInfo){

}
