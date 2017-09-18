/*
 *  KeyboardManager.cpp
 *  Video Led Mapper
 *
 *  Created by Imanol Gomez on 18/09/17.
 *
 */

#include "KeyboardManager.h"
#include "AppManager.h"


KeyboardManager::KeyboardManager(): Manager()
{
    //Intentionally left empty
}

KeyboardManager::~KeyboardManager()
{
   ofLogNotice() << "KeyboardManager::destructor";
}


//--------------------------------------------------------------

void KeyboardManager::setup()
{
    if(m_initialized)
        return;
    
    Manager::setup();
    
    ofLogNotice() <<"KeyboardManager::initialized" ;
    this->addListeners();
}

void KeyboardManager::addListeners()
{
    ofRegisterKeyEvents(this); // this will enable the InteractiveVisual class to listen to the key events.
}

void KeyboardManager::keyPressed(ofKeyEventArgs &e)
{
    int key = e.key;
    
    ofLogNotice() <<"KeyboardManager::keyPressed-> " + ofToString(key);
    
  
    if(key == 'g' || key == 'G') {
        AppManager::getInstance().getGuiManager().toggleGui();
    }
    
    if(key == ' ') {
        AppManager::getInstance().getDressManager().toggleShowChannels();
        //AppManager::getInstance().toggleDebugMode();
    }
    
    if(key == OF_KEY_ALT) {
        AppManager::getInstance().getDressManager().pressedAlt(true);
    }
    
    if(key == OF_KEY_BACKSPACE) {
        AppManager::getInstance().getDressManager().pressedBackSpace();
    }
    
}

void KeyboardManager::keyReleased(ofKeyEventArgs &e)
{
    int key = e.key;
    
    ofLogNotice() <<"KeyboardManager::keyReleased-> " + ofToString(key);
    
    if(key == OF_KEY_ALT) {
        AppManager::getInstance().getDressManager().pressedAlt(false);
    }
}










