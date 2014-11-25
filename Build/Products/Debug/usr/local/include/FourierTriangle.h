//
//  FourierTriangle.h
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
#ifndef __DSG__FourierTriangle__
#define __DSG__FourierTriangle__
#include "SignalGenerator.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //!DSG::Fourier - Namespace Containing Fourier Series Based Oscillators
    namespace Fourier{
        //!\brief DSG::Fourier::FourierTriangle - Fourier Series Triangle Wave Generator
        class FourierTriangle : public DSG::SignalGenerator {
        public:
            FourierTriangle();
            FourierTriangle(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~FourierTriangle();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
            virtual inline DSG::DSGFrequency const& Frequency(DSG::DSGFrequency const& value);
        protected:
            unsigned long _h;
            const double _a;
            double phs;
            double value;
            int i;
        };
        inline bool DSG::Fourier::FourierTriangle::Perform(DSG::DSGSample& signal){
            //(_h/2)+1 Sine Calls Per Sample
            value=DSG::Sin(_phasor);//i=1
            double sgn = -1;
            for (i=3; i<_h; i+=2) {//i=3..5..7..
                value += sgn * (1.0/(i*i)) * DSG::Sin(_phasor*i);
                sgn*=-1;
            }
            value*=_a;
            signal = value;
            step();
            return true;
        }
        inline bool DSG::Fourier::FourierTriangle::Perform(DSG::RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_storage)) {
                    if(signal.Write(_storage)){
                    }else return false;
                }else return false;
            }return true;
        }
        inline DSG::DSGFrequency const& DSG::Fourier::FourierTriangle::Frequency(DSG::DSGFrequency const& value){
            _frequency = value;
            _dt = _frequency/DSG::SampleRate();
            _h = MaxHarms(_frequency);
            return _frequency;
        }
    }
}
#endif /* defined(__DSG__FourierTriangle__) */