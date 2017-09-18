/*
 *  OutputDataManager.cpp
 *  Video Led Mapper
 *
 *  Created by Imanol Gomez on 18/09/17.
 *
 */


#include "ofMain.h"

#include <time.h>

#include "OutputDataManager.h"
#include "AppManager.h"


const int OutputDataManager::NUM_DMX_CHANNELS = 512;


OutputDataManager::OutputDataManager(): Manager(), m_isRecording(false), m_mirror(false), m_numFrames(0)
{
    //Intentionally left empty
}


OutputDataManager::~OutputDataManager()
{
    ofLogNotice() <<"OutputDataManager::Destructor" ;
}


void OutputDataManager::setup()
{
    if(m_initialized)
        return;
    
    
    Manager::setup();
    
    m_file.close();
    ofLogNotice() <<"OutputDataManager::initialized" ;
    
}




void OutputDataManager::update()
{
    if (m_isRecording) {
        this->updateColorPixels();
    }
}

void OutputDataManager::draw()
{
    
}

void OutputDataManager::updateColorPixels()
{
    auto leds = AppManager::getInstance().getLedsManager().getLeds();
    
    for (auto& led: leds){
        uint8_t brightness_byte = (uint8_t) led->getColor().getBrightness();
        m_file << brightness_byte;
    }
    
    if(leds.size() < NUM_DMX_CHANNELS)
    {
        int remainingDmxChannels = NUM_DMX_CHANNELS - leds.size();
        for(int i = 0; i < remainingDmxChannels; i++)
        {
            uint8_t brightness_byte = 0;
            m_file << brightness_byte;
        }
    }
    
    m_numFrames++;
    
}

void OutputDataManager::onRecordingChange(bool& value)
{
     ofLogNotice() <<"OutputDataManager::onRecordingChange -> " << value;
    
    if (m_isRecording && !value) {
        this->saveData();
    }
    
    if(!m_isRecording && value){
        
        m_file.open("output/output_" + getDateTime() + ".rbf", ofFile::WriteOnly, true);
        m_numFrames = 0;
    }
    
    m_isRecording = value;
}


void OutputDataManager::saveData()
{
    
    if(m_mirror){
        this->saveDataMirror();
    }
    else{
        this->saveDataSample();
    }
    
    
    m_numFrames = 0;
    m_file.close();
}



void OutputDataManager::saveDataMirror()
{
    this->saveDataSample();
}


void OutputDataManager::saveDataSample()
{
    auto leds = AppManager::getInstance().getLedsManager().getLeds();
    int num_channels = leds.size();
    
    ofLogNotice() <<"OutputDataManager::saveDataSample ->  num_channels = " << num_channels;
    ofLogNotice() <<"OutputDataManager::saveDataSample ->  frames = " << m_numFrames;
    //ofLogNotice() <<"OutputDataManager::saveDataSample ->  file size = " << m_file.getSize();
    
    
    string fileName = "output/output_"+ getDateTime()  + "_" + ofToString(m_numFrames) + ".rbf";
    //  m_file.renameTo(fileName,true, true);
    
    
    
    m_file.close();
    
    ofLogNotice() <<"OutputDataManager::saveDataSample ->  Saved " << fileName;
    
}

string OutputDataManager::getDateTime()
{
    char buffer[80];
    string fmt="%d-%m-%Y-%H-%M-%S";
    time_t rawtime;
    time ( &rawtime );
    
    struct tm *timeinfo = localtime(&rawtime);
    strftime(buffer,80,fmt.c_str(),timeinfo);
    return buffer;
}





