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
        const double _a = 3.6/PI;
        double phs=0,value=0;
        int i=0;
    };
}
inline bool DSG::FourierSquare::Perform(DSG::DSGSample& signal){
    value=DSG::Sin(_phasor);//i=1
    for (i=3; i<_h; i+=2) {//i=3..5..7..
        value += (1.0/i) * DSG::Sin(_phasor*i);
    }
    value*=_a;
    signal = value;
    _pstep();
    return true;
}
inline bool DSG::FourierSquare::Perform(DSG::RingBuffer& signal){
    signal.Flush();
    while (!signal.Full()) {
        if (Perform(_storage)) {
            if(signal.Write(_storage)){
            }else return false;
        }else return false;
    }return true;
}
inline DSG::DSGFrequency const& DSG::FourierSquare::Frequency(DSG::DSGFrequency const& value){
    _h = MaxHarms(this->SignalGenerator::Frequency(value));
    return _frequency;
}
#endif /* defined(__DSG__FourierSquare__) */