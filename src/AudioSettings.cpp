//
//  AudioSettings.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "AudioSettings.h"
DSG::DSGFrequency DSG::AudioSettings::_sampleRate;
DSG::DSGFrequency DSG::AudioSettings::_nyquist;
DSG::DSGFrequency const& DSG::AudioSettings::SampleRate(){
    return _sampleRate;
}
DSG::DSGFrequency const& DSG::AudioSettings::SampleRate(DSG::DSGFrequency const& value){
    _sampleRate = value;
    _nyquist = _sampleRate*0.5;
    return _sampleRate;
}
DSG::DSGFrequency const& DSG::AudioSettings::Nyquist(){
    return _nyquist;
}