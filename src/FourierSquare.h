//
//  FourierSquare.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__FourierSquare__
#define __DSG__FourierSquare__
#include "SignalGenerator.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //!DSG::Fourier - Namespace Containing Fourier Series Based Oscillators
    namespace Fourier{
        //!\brief DSG::Fourier::FourierSquare - Fourier Series Square Wave Generator
        class FourierSquare : public DSG::SignalGenerator {
        public:
            FourierSquare();
            FourierSquare(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~FourierSquare();
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
        inline bool DSG::Fourier::FourierSquare::Perform(DSG::DSGSample& signal){
            //(_h/2)+1 Sine Calls Per Sample
            value=DSG::Sin(_phasor);//i=1
            for (i=3; i<_h; i+=2) {//i=3..5..7..
                value += (1.0/i) * DSG::Sin(_phasor*i);
            }
            value*=_a;
            signal = value;
            step();
            return true;
        }
        inline bool DSG::Fourier::FourierSquare::Perform(DSG::RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_storage)) {
                    if(signal.Write(_storage)){
                    }else return false;
                }else return false;
            }return true;
        }
        inline DSG::DSGFrequency const& DSG::Fourier::FourierSquare::Frequency(DSG::DSGFrequency const& value){
            _frequency = value;
            _dt = _frequency/DSG::SampleRate();
            _h = MaxHarms(_frequency);
            return _frequency;
        }
    }
}
#endif /* defined(__DSG__FourierSquare__) */