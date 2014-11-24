//
//  AudioSettings.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
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