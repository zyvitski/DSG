//
//  FourierSaw.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__FourierSaw__
#define __DSG__FourierSaw__
#include "SignalGenerator.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Fourier{
        class FourierSaw : public DSG::SignalGenerator {
        public:
            FourierSaw();
            FourierSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~FourierSaw();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
            virtual inline DSG::DSGFrequency const& Frequency(DSG::DSGFrequency const& value);
        protected:
            unsigned long _h;
            const double _a;
            double phs;
            double value;
            int i;
        };
        inline bool DSG::Fourier::FourierSaw::Perform(DSG::DSGSample& signal){
            value=DSG::Sin(_phasor);
            for (i=2; i<_h; ++i) {
                value += (1.0/i) * DSG::Sin(_phasor*i);
            }
            value*=_a;
            signal = value;
            _pstep();
            return true;
        }
        inline bool DSG::Fourier::FourierSaw::Perform(DSG::RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_storage)) {
                    if(signal.Write(_storage)){
                    }else return false;
                }else return false;
            }return true;
        }
        inline DSG::DSGFrequency const& DSG::Fourier::FourierSaw::Frequency(DSG::DSGFrequency const& value){
            _h = MaxHarms(this->SignalGenerator::Frequency(value));
            return _frequency;
        }
    }
}
#endif /* defined(__DSG__FourierSaw__) */