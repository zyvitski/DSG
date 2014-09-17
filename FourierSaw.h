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
        const double _a = 0.5;
        double phs=0,value=0;
    };
    inline bool DSG::FourierSaw::Perform(DSG::DSGSample& signal){
        value=DSG::Sin(_phasor);
        for (int i=1; i<_h; ++i) {
            value += (1.0/i) * DSG::Sin(_phasor*i);
        }
        value*=_a;
        signal = value;
        _pstep();
        return true;
    }
    inline bool DSG::FourierSaw::Perform(DSG::RingBuffer& signal){
        signal.Flush();
        while (!signal.Full()) {
            if (Perform(_storage)) {
                if(signal.Write(_storage)){
                }else return false;
            }else return false;
        }return true;
    }
    inline DSG::DSGFrequency const& DSG::FourierSaw::Frequency(DSG::DSGFrequency const& value){
        _h = MaxHarms(this->SignalGenerator::Frequency(value));
        return _frequency;
    }
}

#endif /* defined(__DSG__FourierSaw__) */
