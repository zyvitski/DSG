//
//  AudioSettings.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
/*
 This file is part of the Digital Signal Generation Project or “DSG”.

 DSG is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 DSG is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with DSG.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "AudioSettings.h"
#include "SignalProcess.h"
DSG::DSGFrequency DSG::AudioSettings::_sampleRate;
DSG::DSGFrequency DSG::AudioSettings::_nyquist;
bool DSG::AudioSettings::_set=false;
std::vector<DSG::SignalProcess*> DSG::AudioSettings::_listeners;
DSG::DSGFrequency const& DSG::AudioSettings::SampleRate(){
    return _sampleRate;
}
DSG::DSGFrequency const& DSG::AudioSettings::SampleRate(DSG::DSGFrequency const& value){
    if (!_set) {
        _set=true;
    }
    _sampleRate = value;
    _nyquist = _sampleRate*0.5;
    for (auto i:_listeners) {
        i->SampleRateChanged(_sampleRate);
    }
    return _sampleRate;
}
DSG::DSGFrequency const& DSG::AudioSettings::Nyquist(){
    return _nyquist;
}
bool DSG::AudioSettings::AddSampleRateListener(DSG::SignalProcess* listener){
    _listeners.push_back(listener);
    return true;
}
bool const& DSG::AudioSettings::IsSampleRateSet(){
    return _set;
}