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
    protected:
        static DSG::DSGFrequency _sampleRate;
        static unsigned long _bufferSize;
    };
    inline DSG::DSGFrequency const& SampleRate(){
        return DSG::AudioSettings::SampleRate();
    }
    inline DSG::DSGFrequency const& SampleRate(DSG::DSGFrequency const& value){
        return DSG::AudioSettings::SampleRate(value);
    }
}
#endif /* defined(__DSG__AudioSettings__) */