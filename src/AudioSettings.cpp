//
//  AudioSettings.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "AudioSettings.h"
DSG::DSGFrequency DSG::AudioSettings::_sampleRate;
DSG::DSGFrequency const& DSG::AudioSettings::SampleRate(){
    return _sampleRate;
}
DSG::DSGFrequency const& DSG::AudioSettings::SampleRate(DSG::DSGFrequency const& value){
    _sampleRate = value;
    return _sampleRate;
}