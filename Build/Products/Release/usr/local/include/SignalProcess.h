//
//  SignalProcess.h
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
#ifndef __DSG__SignalProcess__
#define __DSG__SignalProcess__
#include "DSGTypes.h"
#include "RingBuffer.h"
#include "AudioSettings.h"
namespace DSG {
    /*!\brief DSG::SignalProcess - Defines Base Interface For Audio Processing
     */
    class SignalProcess{
    public:
        SignalProcess();
        virtual ~SignalProcess();
        //Defines Interface for sample rate processing
        virtual inline bool Perform(DSG::DSGSample& signal)=0;
        virtual inline bool Perform(DSG::RingBuffer& signal)=0;
        virtual inline bool SampleRateChanged(DSG::DSGFrequency const& sampleRate)=0;
    };
    inline bool DSG::SignalProcess::SampleRateChanged(DSG::DSGFrequency const& sampleRate){
        return true;
    }
}
#endif /* defined(__DSG__SignalProcess__) */