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
        };
        inline bool DSG::BLIT::BlitSaw::Perform(DSG::DSGSample& signal){
            
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
            
            return _frequency;
        }
        inline void DSG::BLIT::BlitSaw::setHarmonics(){
            
        }

    }
}
#endif /* defined(__DSG__BLITSaw__) */