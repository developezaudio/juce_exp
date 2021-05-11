/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class WahClipperExp1AudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    WahClipperExp1AudioProcessor();
    ~WahClipperExp1AudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    juce::AudioProcessorValueTreeState mValueTreeState;

private:
    enum class FilterType {
        LowPass,
        BandPass,
        HighPass
    };
    void reset() override;
    void setType();
    ////// Param Set up //////
    juce::AudioParameterFloat* mCutoff;
    juce::AudioProcessorValueTreeState::ParameterLayout mCreateParams();
    
    juce::dsp::StateVariableTPTFilter<float> mFilter;
    
    juce::dsp::Oscillator<float> osc {[](float x){return std::sin(x);}};
    
    juce::dsp::Gain<float> mGain;
    
    FilterType mFilterType {FilterType::LowPass};
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WahClipperExp1AudioProcessor)
};
