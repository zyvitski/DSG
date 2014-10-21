//
//  GenericGenerator.h
//  DSG
//
//  Created by Alexander Zywicki on 10/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__GenericGenerator__
#define __DSG__GenericGenerator__
#include "SignalGenerator.h"
namespace DSG{
    class GenericGenerator:public DSG::SignalGenerator{
    public:
        GenericGenerator();
        GenericGenerator(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset,DSG::DSGSample (*signalFunction)(DSG::DSGSample const&));
        virtual ~GenericGenerator();
        virtual inline bool Perform(DSG::DSGSample& signal);
        virtual inline bool Perform(DSG::RingBuffer& signal);
    protected:
        DSG::DSGSample (*_callback)(DSG::DSGSample const&);
    };
    inline bool DSG::GenericGenerator::Perform(DSG::DSGSample& signal){
        signal = _callback(_phasor);
        step();
        return true;
    }
    inline bool DSG::GenericGenerator::Perform(DSG::RingBuffer& signal){
        signal.Flush();
        while (!signal.Full()) {
            if (Perform(_storage)) {
                if(signal.Write(_storage)){
                }else return false;
            }else return false;
        }return true;
    }
}
#endif /* defined(__DSG__GenericGenerator__) */