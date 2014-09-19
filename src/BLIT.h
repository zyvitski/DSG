//
//  BLIT.h
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__BLIT__
#define __DSG__BLIT__
#include "SignalGenerator.h"
#include <limits>
#include <math.h>
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //!DSG::BLIT - Namespace Containing BLIT Based Oscillators
    namespace BLIT{
        /*!\brief DSG::BLIT::Blit - Band-Limited Impulse Train Generator
         */
        class Blit:public DSG::SignalGenerator{
        public:
            Blit();
            Blit(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~Blit();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
            virtual inline DSG::DSGFrequency const& Frequency(DSG::DSGFrequency const& value);
        protected:
            virtual inline void setHarmonics();
            unsigned long m_;
            unsigned long _nHarms;
            DSG::DSGSample _denominator;
            DSG::DSGSample tmp;
        };
        inline bool DSG::BLIT::Blit::Perform(DSG::DSGSample& signal){
            //Two Sin Calls Per Sample
            _denominator = DSG::Sin(_phasor);
            if (_denominator<=std::numeric_limits<float>::epsilon()) {
                tmp=1.0;
            }else{
                tmp = DSG::Sin(_phasor);
                tmp/= m_ * _denominator;
            }
            signal = tmp;
            _pstep();
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
            _nHarms = MaxHarms(_frequency);
            setHarmonics();
            return _frequency;
        }
        inline void DSG::BLIT::Blit::setHarmonics(){
            if (_nHarms<=0) {
                size_t max = (size_t)floor(0.5 * ( SampleRate()/ _frequency));
                m_ = 2* max +1;
            }
            else{
                m_ = 2* _nHarms +1;
            }
        }
    }
}
#endif /* defined(__DSG__BLIT__) */