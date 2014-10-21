//
//  SignalProcess.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__SignalProcess__
#define __DSG__SignalProcess__
#include "DSGTypes.h"
#include "RingBuffer.h"
namespace DSG {
    /*!\brief DSG::SignalProcess - Defines Base Interface For Audio Processing
     */
    class SignalProcess{
    public:
        SignalProcess();
        virtual ~SignalProcess();
        //Defines Interface for sample rate processing
        virtual inline bool Perform(DSG::DSGSample& signal)=0;
        virtual inline bool Perform(DSG::RingBuffer& signal)=0;
    };
}
#endif /* defined(__DSG__SignalProcess__) */