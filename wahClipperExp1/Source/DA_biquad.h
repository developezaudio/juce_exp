/*
  ==============================================================================

    DA_biquad.h
    Created: 11 May 2021 5:11:06pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#pragma once
/// enum for easy acceses to coeffs
enum coeffs { a0, a1, a2, b1, b2, c0, d0, numCoeffs};

enum { x_z1, x_z2, y_z1, y_z2, numStates};

template <typename T>
class DA_biquad {
public:
    DA_biquad();
    ~DA_biquad();
    void preparetoplay(float sampleRate, int bufferSize);
    void processSample();
    T processSample(T sample);
private:
    double coeffsArray[numCoeffs];
    double statesArray[numStates];
};
