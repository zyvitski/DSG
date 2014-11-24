//
//  AnalogSaw.h
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
#ifndef __DSG__AnalogSaw__
#define __DSG__AnalogSaw__
#include "SignalGenerator.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //! DSG::Analog - Namespace Containing Analog Style Oscillators
    namespace Analog{
        //!\brief DSG::Analog::AnalogSaw - Analog Syle Saw Wave Generator
        class AnalogSaw : public DSG::SignalGenerator {
        public:
            AnalogSaw();
            AnalogSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~AnalogSaw();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
        protected:
            DSG::DSGSample _stor;
        };
        inline bool DSG::Analog::AnalogSaw::Perform(DSG::DSGSample& signal){
            _stor=_phasor;
            _stor+=0.5;
            if (_stor>1.0) {
                --_stor;
            }
            _stor-=0.5;
            _stor*=2.0;
            signal=_stor;
            step();
            return true;
        }
        inline bool DSG::Analog::AnalogSaw::Perform(DSG::RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_storage)) {
                    if(signal.Write(_storage)){
                    }else return false;
                }else return false;
            }return true;
        }
    }
}
#endif /* defined(__DSG__AnalogSaw__) */