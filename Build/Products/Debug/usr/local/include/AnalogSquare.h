//
//  AnalogSquare.h
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
#ifndef __DSG__AnalogSquare__
#define __DSG__AnalogSquare__
#include "SignalGenerator.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //! DSG::Analog - Namespace Containing Analog Style Oscillators
    namespace Analog{
        //!\brief DSG::Analog::AnalogSquare - Analog Syle Square Wave Generator
        class AnalogSquare : public DSG::SignalGenerator {
        public:
            AnalogSquare();
            AnalogSquare(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~AnalogSquare();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
        };
        inline bool DSG::Analog::AnalogSquare::Perform(DSG::DSGSample& signal){
            signal=_phasor < 0.5 ? 1.0:-1.0;
            step();
            return true;
        }
        inline bool DSG::Analog::AnalogSquare::Perform(DSG::RingBuffer& signal){
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
#endif /* defined(__DSG__AnalogSquare__) */