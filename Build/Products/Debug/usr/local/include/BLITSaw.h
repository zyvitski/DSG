//
//  BLITSaw.h
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
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
#ifndef __DSG__BLITSaw__
#define __DSG__BLITSaw__
#include "BLIT.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace BLIT{
        //!\brief DSG::BLIT::BlitSaw - Saw Wave Generator Based on BLIT Algorithm
        //!\todo Re-write DSG::BLIT::BlitSaw algorithm
        class BlitSaw : public Blit{
        public:
            BlitSaw();
            BlitSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~BlitSaw();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
            virtual inline DSG::DSGFrequency const& Frequency(DSG::DSGFrequency const& value);
        protected:
            DSG::DSGSample C2_;
            DSG::DSGSample Register_;
        };
        inline bool DSG::BLIT::BlitSaw::Perform(DSG::DSGSample& signal){
            denominator = m_ * sin(PI*_phasor);
            if (DSG::IsDenormal(denominator)) {
                signal = a_;
            }else{
                value = sin(PI*_phasor * m_);
                value/=denominator;
                value*=a_;
                signal = value;
            }
            step();
            signal += (Register_ - C2_);
            Register_ = signal * 0.995;
            C2_+=signal;
            C2_*=0.5;
            return true;
        }
        inline bool DSG::BLIT::BlitSaw::Perform(DSG::RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_storage)) {
                    if(signal.Write(_storage)){
                    }else return false;
                }else return false;
            }return true;
        }
        inline DSG::DSGFrequency const& DSG::BLIT::BlitSaw::Frequency(DSG::DSGFrequency const& value){
            this->SignalGenerator::Frequency(value);
            p_ = DSG::SampleRate()/_frequency;
            _h = (unsigned)floor(p_*0.5);
            m_ = 2 * (_h)+1;
            a_ = m_/(double)p_;
            C2_ = 1.0/(double)p_;
            return _frequency;
        }
    }
}
#endif /* defined(__DSG__BLITSaw__) */