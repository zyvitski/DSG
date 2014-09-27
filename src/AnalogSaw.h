//
//  AnalogSaw.h
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__AnalogSaw__
#define __DSG__AnalogSaw__
#include "SignalGenerator.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //! DSG::Analog - Namespace Containing Analog Style Oscillators
    namespace Analog{
        //!\brief DSG::AnalogSaw - Analog Syle Saw Wave Generator
        class AnalogSaw : public DSG::SignalGenerator {
        public:
            AnalogSaw();
            AnalogSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~AnalogSaw();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
        protected:
            DSG::DSGSample _stor;
        };
        inline bool DSG::Analog::AnalogSaw::Perform(DSG::DSGSample& signal){
            _stor=_phasor;
            _stor=1.0-_stor;
            _stor-=0.5;
            _stor*=2.0;
            signal=_stor;
            step();
            return true;
        }
        inline bool DSG::Analog::AnalogSaw::Perform(DSG::RingBuffer& signal){
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
#endif /* defined(__DSG__AnalogSaw__) */