/*
  ==============================================================================

    Wahclipper.h
    Created: 11 May 2021 12:00:16pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
class Wahclipper {
public:
    Wahclipper();
    ~Wahclipper();
    void prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels);
    void processNextBlock();
private:
    juce::ADSR m_adsr;
    juce::ADSR::Parameters adsr_params;
    
    bool isPrepared{ false };
};


