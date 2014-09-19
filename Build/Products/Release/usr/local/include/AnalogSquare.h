//
//  AnalogSquare.h
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__AnalogSquare__
#define __DSG__AnalogSquare__namespace DSG{
#include "SignalGenerator.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Analog{
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
            _pstep();
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