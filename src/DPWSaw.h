//
//  DPWSaw.h
//  DSG
//
//  Created by Alexander Zywicki on 9/27/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__DPWSaw__
#define __DSG__DPWSaw__
#include "SignalGenerator.h"
namespace DSG {
#ifdef DSG_Short_Names
    inline
#endif
    namespace DPW{
        class DPWSaw:public DSG::SignalGenerator{
        public:
            DPWSaw();
            DPWSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~DPWSaw();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
        protected:
            DSG::DSGSample _register;
            DSG::DSGSample _delay1;
        };
        inline bool DSG::DPW::DPWSaw::Perform(DSG::DSGSample& signal){
            //DPW order 2
            //trivial saw ramping from -1 to 1
            _register = _phasor;
            _register-=0.5;
            _register*=2.0;
            /*-------------------------*/
            //DPW- This Is the meat of the 2nd order DPW code
            //now the square of the saw
            _register*=_register;
            //differencing
            signal=(_register-_delay1)/(4.0*_dt);
            if (signal>1.0 || signal<-1.0) {
                signal=0;
            }
            //store the last output
            _delay1=_register;
            /*-------------------------*/
            //advance phase
            step();
            //assign output
            return true;
        }
        inline bool DSG::DPW::DPWSaw::Perform(DSG::RingBuffer& signal){
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
#endif /* defined(__DSG__DPWSaw__) */