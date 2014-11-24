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
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 DSG is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with DSG.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __DSG__AudioSettings__
#define __DSG__AudioSettings__
#include "DSGTypes.h"
namespace DSG {
    /*!\brief DSG::AudioSettings - Global Storage For Audio Settings Such As Sample Rate
     */
    class AudioSettings{
    public:
        static DSG::DSGFrequency const& SampleRate();
        static DSG::DSGFrequency const& SampleRate(DSG::DSGFrequency const& value);
        static DSG::DSGFrequency const& Nyquist();
    protected:
        static DSG::DSGFrequency _sampleRate;
        static DSG::DSGFrequency _nyquist;
    };
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
}
#endif /* defined(__DSG__AudioSettings__) */