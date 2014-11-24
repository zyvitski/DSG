//
//  EPTRSaw.h
//  DSG
//
//  Created by Alexander Zywicki on 9/29/14.
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
#ifndef __DSG__EPTRSaw__
#define __DSG__EPTRSaw__
#include "SignalGenerator.h"
namespace DSG {
#ifdef DSG_Short_Names
    inline
#endif
    //!DSG::EPTR - Generators Based On The Efficienct Polynomial Transfer Region Algorithm
    namespace EPTR{
        //!\brief DSG::EPTR::EPTRSaw-Sawtooth Wave Generator Using The Efficienct Polynomial Transfer Region Algorithm
        //!\todo Test and Possibly Re-Write DSG::EPTR::EPTRSaw algorithm 
        class EPTRSaw : public DSG::SignalGenerator{
        public:
            EPTRSaw();
            EPTRSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~EPTRSaw();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
        protected:
            DSG::DSGSample _register;
        };
        inline bool DSG::EPTR::EPTRSaw::Perform(DSG::DSGSample& signal){
#warning Untested For Aliasing DSG::EPTR::EPTRSaw::Perform()
            //generate trivial saw
            _register = _phasor;
            _register+=0.5;
            if (_register>1.0) {
                --_register;
            }
            _register-=0.5;
            _register*=2.0;
            if (_register > 1.0-_dt) {
                //transition region detected
                //apply eptr correction
                signal = _register - (_register/_dt) + (1.0/_dt) -1;
            }else{
                signal = _register;
            }
            step();//avance phase
            return true;
        }
        inline bool DSG::EPTR::EPTRSaw::Perform(DSG::RingBuffer& signal){
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
#endif /* defined(__DSG__EPTRSaw__) */