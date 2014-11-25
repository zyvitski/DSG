//
//  DPWSaw.h
//  DSG
//
//  Created by Alexander Zywicki on 9/27/14.
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
#ifndef __DSG__DPWSaw__
#define __DSG__DPWSaw__
#include "DPW.h"
namespace DSG {
#ifdef DSG_Short_Names
    inline
#endif
    namespace DPW{
        //!\brief DSG::DPW::DPWSaw - Sawtooth Generator using the Nth Order DPW algorithm 
        template<unsigned order>
        class DPWSaw:public DSG::SignalGenerator{
        public:
            DPWSaw():DSG::SignalGenerator(),_register(0){
                DSG::StaticAssertBounds<1, 6,order>();
            }
            DPWSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset),_register(0){DSG::StaticAssertBounds<1, 6,order>();}
            virtual ~DPWSaw(){}
            virtual inline bool Perform(DSG::DSGSample& signal){
                //trivial saw ramping from -1 to 1
                _register = _phasor;
                _register-=0.5;
                _register*=2.0;
                /*-------------------------*/
                //DPW algorithm
                //polynomial shaping
                _register=DSG::DPW::DPW_Polynomial<order>(_register);
                //differentiating
                signal = _diff(_register,_dt);
                /*-------------------------*/
                //signal = DSG::EnforceBounds<-1, 1>(signal);
                //advance phase
                step();
                return true;
            }
            virtual inline bool Perform(DSG::RingBuffer& signal){
                signal.Flush();
                while (!signal.Full()) {
                    if (Perform(_storage)) {
                        if(signal.Write(_storage)){
                        }else return false;
                    }else return false;
                }return true;
            }
        protected:
            DSG::DSGSample _register;
            DSG::DPW::DPW_Differentiator<order> _diff;
        };
    }
}
#endif /* defined(__DSG__DPWSaw__) */