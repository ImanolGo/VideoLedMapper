/*
 *  OutputDataManager.h
 *  Video Led Mapper
 *
 *  Created by Imanol Gomez on 18/09/17.
 *
 */


#pragma once

#include "Manager.h"
#include "Led.h"
#include "Manager.h"


//========================== class OutputDataManager ==============================
//===================================================================== =======
/** \class OutputDataManager OutputDataManager.h
 *	\brief Class managing the binary data to be exported
 *	\details it reads from the ded visuals and saves it in a binary file on demand
 */



class OutputDataManager: public Manager
{
    
    static const int NUM_DMX_CHANNELS;
    
public:
    
    //! Constructor
    OutputDataManager();
    
    //! Destructor
    ~OutputDataManager();
    
    //! Setup the Image Manager
    void setup();
    
    //! Update the Image Manager
    void update();
    
    //! Draw the Image Manager
    void draw();
    
    void onRecordingChange(bool& value);
    
    void onMirroringChange(bool& value) {m_mirror = value;}
    
private:
    
    void saveData();
    
    void saveDataSample();
    
    void saveDataMirror();
    
    void updateColorPixels();
    
    string getDateTime();
    
private:
    
    typedef vector< ofColor > ColorVector;
    
    bool                m_isRecording;
    bool                m_mirror;
    
    int                 m_numFrames;
    ofFile              m_file;
};




