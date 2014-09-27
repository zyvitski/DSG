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
#include "Denormal.h"
#include "Sinc.h"
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
            unsigned long _h;
            double a_;
        };
        inline bool DSG::BLIT::Blit::Perform(DSG::DSGSample& signal){
#warning Non Functional DSG::BLIT::Blit::Perform
            signal = DSG::SincM(_phasor, m_);//uses stilson and smith style SincM function- DSG::SincM(x,m);
            
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
            _h = MaxHarms(_frequency);
            setHarmonics();
            a_ = (float)m_/(DSG::SampleRate()/_frequency);
            return _frequency;
        }
        inline void DSG::BLIT::Blit::setHarmonics(){
            if (_h<=0) {
                size_t max = (size_t)floor(0.5 * ( SampleRate()/ _frequency));
                m_ = 2* max +1;
            }else{
                m_ = 2* _h +1;
            }
        }
    }
}
#endif /* defined(__DSG__BLIT__) */