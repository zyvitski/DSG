//
//  BLIT.h
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
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
#ifndef __DSG__BLIT__
#define __DSG__BLIT__
#include "SignalGenerator.h"
#include "Denormal.h"
#include "Sinc.h"
#include "DSGMath.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //!DSG::BLIT - Namespace Containing BLIT Based Oscillators
    namespace BLIT{
        /*!\brief DSG::BLIT::Blit - Band-Limited Impulse Train Generator
         */
        //!\todo Re-write DSG::BLIT::Blit algorithm
        class Blit:public DSG::SignalGenerator{
        public:
            Blit();
            Blit(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~Blit();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
            virtual inline DSG::DSGFrequency const& Frequency(DSG::DSGFrequency const& value);
        protected:
            unsigned long p_;
            unsigned long m_;
            unsigned long _h;
            double a_;
            DSG::DSGSample denominator;
            DSG::DSGSample value;
        };
        inline bool DSG::BLIT::Blit::Perform(DSG::DSGSample& signal){
            //found better results in this case with built in sine function. not performance wise but algorithmically
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
            return true;
        }
        inline bool DSG::BLIT::Blit::Perform(DSG::RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_storage)) {
                    if(signal.Write(_storage)){
                    }else return false;
                }else return false;
            }return true;
        }
        inline DSG::DSGFrequency const& DSG::BLIT::Blit::Frequency(DSG::DSGFrequency const& value){
            this->SignalGenerator::Frequency(value);
            p_ = DSG::SampleRate()/_frequency;
            _h = (unsigned)floor(p_*0.5);
            m_ = 2 * (_h)+1;
            a_ = m_/(double)p_;
            return _frequency;
        }
    }
}
#endif /* defined(__DSG__BLIT__) */