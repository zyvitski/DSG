//
//  AudioSettings.h
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
#ifndef __DSG__AudioSettings__
#define __DSG__AudioSettings__
#include "DSGTypes.h"
#include <vector>
namespace DSG {
    class SignalProcess;
    /*!\brief DSG::AudioSettings - Global Storage For Audio Settings Such As Sample Rate
     */
    class AudioSettings{
    public:
        static DSG::DSGFrequency const& SampleRate();
        static DSG::DSGFrequency const& SampleRate(DSG::DSGFrequency const& value);
        static DSG::DSGFrequency const& Nyquist();
        static bool AddSampleRateListener(SignalProcess* listener);
        static bool const& IsSampleRateSet();
    protected:
        static DSG::DSGFrequency _sampleRate;
        static DSG::DSGFrequency _nyquist;
        static std::vector<DSG::SignalProcess*> _listeners;
        static bool _set;
    };
    namespace{
#define SampleRateDefault 44100//hidden macro defining default sample rate
    }
    //!\brief DSG::SampleRate - Get Global Sample Rate
    inline DSG::DSGFrequency const& SampleRate(){
        return DSG::AudioSettings::SampleRate();
    }
    //!\brief DSG::SampleRate - Set Global Sample Rate
    inline DSG::DSGFrequency const& SampleRate(DSG::DSGFrequency const& value){
        return DSG::AudioSettings::SampleRate(value);
    }
    //!\brief DSG::Nyquist() - Pre-Calculated Nyquist Limit. Use instead of calculating each time needed. This value will be updated whenever the sample rate changes.
    inline DSG::DSGFrequency Nyquist(){
        return DSG::AudioSettings::Nyquist();
    }
    //!\brief DSG::AddSampleRateListener() - Allows Generators to be notified if the sample rate changes
    inline bool AddSampleRateListener(DSG::SignalProcess* listner){
        return AudioSettings::AddSampleRateListener(listner);
    }
    //!\brief DSG::VerifySampleRateSet() - Allows a Generator to ask if a valid sample rate has been set
    inline void VerifySampleRateSet(){
        if (!DSG::AudioSettings::IsSampleRateSet()) {
            SampleRate(SampleRateDefault);
        }
    }
}
#endif /* defined(__DSG__AudioSettings__) */