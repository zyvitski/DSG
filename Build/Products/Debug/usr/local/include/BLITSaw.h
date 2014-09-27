//
//  BLITSaw.h
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__BLITSaw__
#define __DSG__BLITSaw__
#include "BLIT.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace BLIT{
        //!\brief DSG::BLIT::BlitSaw - Saw Wave Generator Based on BLIT Algorithm
        class BlitSaw : public Blit{
        public:
            BlitSaw();
            BlitSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~BlitSaw();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
            virtual inline DSG::DSGFrequency const& Frequency(DSG::DSGFrequency const& value);
        protected:
            virtual inline void setHarmonics();
            DSG::DSGSample p_;
            DSG::DSGSample C2_;
            DSG::DSGSample state_;
            DSG::DSGSample a_;
            DSG::DSGSample _denominator,tmp;
        };
        inline bool DSG::BLIT::BlitSaw::Perform(DSG::DSGSample& signal){
#warning Non-Functional DSG::BlitSaw::Perform()
            //very broken still
            _denominator = DSG::Sin(_phasor);
            if (DSG::IsDenormal(fabs(_denominator))) {
                tmp=a_;
            }else{
                tmp = DSG::Sin(_phasor);
                tmp/= (SampleRate()/_frequency) * _denominator;
            }
            tmp+=state_-C2_;
            state_ = tmp * 0.995;
            signal = tmp;
            step();
            
            return true;
        }
        inline bool DSG::BLIT::BlitSaw::Perform(DSG::RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_storage)) {
                    if(signal.Write(_storage)){
                    }else return false;
                }else return false;
            }return true;
        }
        inline DSG::DSGFrequency const& DSG::BLIT::BlitSaw::Frequency(DSG::DSGFrequency const& value){
            _frequency = value;
            _dt = SampleRate()/_frequency;
            _h=MaxHarms(_frequency);
            this->setHarmonics();
            C2_ = 1.0/(SampleRate()/ _frequency);
            state_ = -0.5 * a_;
            return _frequency;
        }
        inline void DSG::BLIT::BlitSaw::setHarmonics(){
            if ( _h <= 0 ) {
                unsigned int maxHarmonics = (unsigned int) floor( 0.5 * (SampleRate()/ _frequency) );
                m_ = 2 * maxHarmonics + 1;
            }
            else{
                m_ = 2 * _h + 1;
            }
            a_ = m_ /( SampleRate()/_frequency);
        }
    }
}
#endif /* defined(__DSG__BLITSaw__) */