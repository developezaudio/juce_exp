/*
  ==============================================================================

    DA_biquad.h
    Created: 11 May 2021 5:11:06pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#pragma once

class DA_biquad {
public:
    DA_biquad();
    ~DA_biquad();
    void preparetoplay(float sampleRate, int bufferSize);
    void processSample();
private:
    
};
