//
//  SignalGenerator.h
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
#ifndef __DSG__SignalGenerator__
#define __DSG__SignalGenerator__
#include "SignalProcess.h"
#include "Sine.h"
#include "Phasor.h"
namespace DSG{
    /*!\brief DSG::SignalGenerator - Extends DSG::Signal Process With Tools For Signal Generation
     */
    class SignalGenerator:public DSG::SignalProcess,public DSG::Phasor{
    public:
        SignalGenerator();
        SignalGenerator(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
        virtual ~SignalGenerator();
        virtual inline bool Perform(DSG::DSGSample& signal);
        virtual inline bool Perform(DSG::RingBuffer& signal);
        virtual inline bool SampleRateChanged(DSG::DSGFrequency const& sampleRate);
    protected:
        DSG::DSGSample _storage;//storage variable for calculations
    };
    inline unsigned long MaxHarms(DSG::DSGFrequency const& frequency){
        double _s = DSG::SampleRate()*  20000.0/DSG::SampleRate();
        _s/=frequency;
        return _s;
    }
}
inline bool DSG::SignalGenerator::Perform(DSG::DSGSample& signal){
    signal=0;
    return false;
}
inline bool DSG::SignalGenerator::Perform(DSG::RingBuffer& signal){
    signal.Flush();
    return false;
}
inline bool DSG::SignalGenerator::SampleRateChanged(DSG::DSGFrequency const& sampleRate){
    Frequency(_frequency);
    return true;
}

#endif /* defined(__DSG__SignalGenerator__) */