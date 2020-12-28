/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionAudioProcessorEditor::DistortionAudioProcessorEditor (DistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    
    distortionTypeChoice.addItem("Hard Clip", 1);
    distortionTypeChoice.addItem("Soft Clip", 2);
    distortionTypeChoice.addItem("Half-Wave Rect", 3);
    distortionTypeChoice.setSelectedId(1);
    distortionTypeChoice.addListener(this);
    addAndMakeVisible(&distortionTypeChoice);
    
    addAndMakeVisible(&Threshold);
    Threshold.setRange(0.f, 1.f, 0.001f);
    Threshold.addListener(this);

    addAndMakeVisible(&Mix);
    Mix.setRange(0.f, 1.f, 0.001f);
    Mix.addListener(this);
}

DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
{
}

//==============================================================================
void DistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
   
}

void DistortionAudioProcessorEditor::resized()
{
    distortionTypeChoice.setBounds(50, 50, 200, 50);
    Threshold.setBounds(50, 100, 200, 50);
    Mix.setBounds(50, 150, 200, 50);
}

void DistortionAudioProcessorEditor::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    audioProcessor.menuChoice = comboBoxThatHasChanged->getSelectedId();
}

void DistortionAudioProcessorEditor::sliderValueChanged(Slider* sliderThatHasChanged)
{
    if (&Mix == sliderThatHasChanged)
    {
    audioProcessor.mix = sliderThatHasChanged->getValue();
    }
    if (&Threshold == sliderThatHasChanged)
    {
    audioProcessor.thresh = sliderThatHasChanged->getValue();
    }
}
