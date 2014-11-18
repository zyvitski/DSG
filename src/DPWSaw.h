//
//  DPWSaw.h
//  DSG
//
//  Created by Alexander Zywicki on 9/27/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
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