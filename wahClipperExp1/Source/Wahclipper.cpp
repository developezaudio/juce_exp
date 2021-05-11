/*
  ==============================================================================

    Wahclipper.cpp
    Created: 11 May 2021 12:00:16pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#include "Wahclipper.h"

Wahclipper::Wahclipper()
{
    
}
Wahclipper::~Wahclipper()
{
    
}
void Wahclipper::prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels)
{
    m_adsr.setSampleRate(sampleRate);
    
    //// To make sure function is called
    isPrepared = true;
}
void Wahclipper::processNextBlock()
{
    jassert(isPrepared);
}
