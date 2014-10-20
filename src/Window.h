//
//  Window.h
//  DSG
//
//  Created by Alexander Zywicki on 10/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef DSG_Window_h
#define DSG_Window_h
#include "LUT.h"
namespace DSG{
    template<typename decimal,unsigned long lutsize>
    void ApplyWindow(DSG::LUT<decimal,lutsize>& lut,decimal (&windowFunction)(decimal const&),decimal range = 1.0){
        decimal step = range/(decimal)lut.Size();
        decimal phs=0;
        for (int i=0; i<lut.Size(); ++i) {
            lut[i]*=windowFunction(phs);
            phs+=step;
        }
    }
    template<typename decimal,unsigned long lutsize>
    void ApplyWindow(DSG::LUT<decimal,lutsize>& lut,decimal (&windowFunction)(decimal),decimal range = 1.0){
        decimal step = range/(decimal)lut.Size();
        decimal phs=0;
        for (int i=0; i<lut.Size(); ++i) {
            lut[i]*=windowFunction(phs);
            phs+=step;
        }
    }
}
#endif