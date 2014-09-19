//
//  FourierTriangle.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __DSG__FourierTriangle__
#define __DSG__FourierTriangle__
#include "SignalGenerator.h"

namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //!DSG::Fourier - Namespace Containing Fourier Series Based Oscillators
    namespace Fourier{
        class FourierTriangle : public DSG::SignalGenerator {
        public:
            FourierTriangle();
            FourierTriangle(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~FourierTriangle();
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
        inline bool DSG::Fourier::FourierTriangle::Perform(DSG::DSGSample& signal){
            //(_h/2)+1 Sine Calls Per Sample
            value=DSG::Sin(_phasor);//i=1
            double sgn = -1;
            for (i=3; i<_h; i+=2) {//i=3..5..7..
                value += sgn * (1.0/(i*i)) * DSG::Sin(_phasor*i);
                sgn*=-1;
            }
            value*=_a;
            signal = value;
            _pstep();
            return true;
        }
        inline bool DSG::Fourier::FourierTriangle::Perform(DSG::RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_storage)) {
                    if(signal.Write(_storage)){
                    }else return false;
                }else return false;
            }return true;
        }
        inline DSG::DSGFrequency const& DSG::Fourier::FourierTriangle::Frequency(DSG::DSGFrequency const& value){
            _h = MaxHarms(this->SignalGenerator::Frequency(value));
            return _frequency;
        }
    }
}
#endif /* defined(__DSG__FourierTriangle__) */