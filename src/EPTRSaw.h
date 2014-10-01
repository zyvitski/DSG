//
//  EPTRSaw.h
//  DSG
//
//  Created by Alexander Zywicki on 9/29/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__EPTRSaw__
#define __DSG__EPTRSaw__
#include "SignalGenerator.h"
namespace DSG {
#ifdef DSG_Short_Names
    inline
#endif
    //!DSG::EPTR - Namespace Enclosign Generators Based On The Efficienct Polynomial Transfer Region Algorithm
    namespace EPTR{
        //!\brief DSG::EPTR::EPTRSaw-Sawtooth Wave Generator Using The Efficienct Polynomial Transfer Region Algorithm
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
                //appy eptr correction
                signal = _register - (_register/_dt) + (1/_dt) -1;
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