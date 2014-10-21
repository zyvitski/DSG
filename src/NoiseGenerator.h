//
//  NoiseGenerator.h
//  DSG
//
//  Created by Alexander Zywicki on 10/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__NoiseGenerator__
#define __DSG__NoiseGenerator__
#include "SignalGenerator.h"
namespace DSG{
    //Stateless Generator is a class used to wrap stateless signal functions like the noise functions which produce an output with no input. This is a helpfull class because it allows us to use stateless functions as generators.
    class NoiseGenerator:public SignalProcess{
    public:
        NoiseGenerator(DSGSample (*StatelessFunction)(DSGSample));
        virtual ~NoiseGenerator();
        virtual inline bool Perform(DSG::DSGSample& signal);
        virtual inline bool Perform(DSG::RingBuffer& signal);
    protected:
        DSGSample (*_function)(DSGSample);
        DSG::DSGSample _storage;
    };
    inline bool DSG::NoiseGenerator::Perform(DSG::DSGSample& signal){
        signal = _function(0);
        return true;
    }
    inline bool DSG::NoiseGenerator::Perform(DSG::RingBuffer& signal){
        signal.Flush();
        while (!signal.Full()) {
            if (Perform(_storage)) {
                if(signal.Write(_storage)){
                }else return false;
            }else return false;
        }return true;
    }
}
#endif /* defined(__DSG__NoiseGenerator__) */