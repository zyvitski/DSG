//
//  Decimate.h
//  DSG
//
//  Created by Alexander Zywicki on 10/13/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__Decimate__
#define __DSG__Decimate__
#include "SignalProcess.h"
#include "PI.h"
#include <math.h>
namespace DSG {
    class Decimator:public DSG::SignalProcess{
    public:
        Decimator(unsigned long factor);
        virtual ~Decimator();
        virtual inline bool Perform(DSG::RingBuffer& signal);
        inline unsigned long const& Factor()const;
        inline unsigned long const& Factor(unsigned long const& value);
    protected:
        virtual inline bool Perform(DSG::DSGSample& signal);//not signal ready, buffer wise only right now
        DSG::DSGSample _kernel[100];
        unsigned long count;
        unsigned long decimationFactor;
        unsigned long counter;
        DSG::DSGSample _temp;
    };
    inline unsigned long const& DSG::Decimator::Factor()const{
        return decimationFactor;
    }
    inline unsigned long const& DSG::Decimator::Factor(unsigned long const& value){
        decimationFactor = value;
        return decimationFactor;
    }
    inline bool DSG::Decimator::Perform(DSG::DSGSample& signal){
        if (counter == 0) {//should this sample be thrown away
            counter=decimationFactor-1;
            return true;//keep
        }else{
            --counter;
            return false;//throw
        }
    }
    inline bool DSG::Decimator::Perform(DSG::RingBuffer& signal){
        if (!signal.Empty()) {
            count = signal.Count();
            while (count-- > 0) {
                if(signal.Read(_temp)){
                    if (Perform(_temp)) {
                        signal.Write(_temp);
                    }
                }else return false;
            }return true;
        }else return false;
    }
}
#endif /* defined(__DSG__Decimate__) */