//
//  AnalogTriangle.h
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__AnalogTriangle__
#define __DSG__AnalogTriangle__
#include "SignalGenerator.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //! DSG::Analog - Namespace Containing Analog Style Oscillators
    namespace Analog{
        class AnalogTriangle : public DSG::SignalGenerator {
        public:
            AnalogTriangle();
            AnalogTriangle(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~AnalogTriangle();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
        protected:
            DSG::DSGSample _stor;
        };
        inline bool DSG::Analog::AnalogTriangle::Perform(DSG::DSGSample& signal){
            _stor = _phasor;
            _stor+=0.25;
            while (_stor>1.0) {
                _stor-=1.0;
            }
            _stor-=0.5;
            if (_stor<0) {
                _stor*=-1.0;
            }
            _stor-=0.25;
            _stor*=-4.0;
            signal = _stor;
            _pstep();//always last
            return true;
        }
        inline bool DSG::Analog::AnalogTriangle::Perform(DSG::RingBuffer& signal){
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

#endif /* defined(__DSG__AnalogTriangle__) */