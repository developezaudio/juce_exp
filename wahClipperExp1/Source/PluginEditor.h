/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class WahClipperExp1AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    WahClipperExp1AudioProcessorEditor (WahClipperExp1AudioProcessor&);
    ~WahClipperExp1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    WahClipperExp1AudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WahClipperExp1AudioProcessorEditor)
};
