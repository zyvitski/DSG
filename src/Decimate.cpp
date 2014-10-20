//
//  Decimate.cpp
//  DSG
//
//  Created by Alexander Zywicki on 10/13/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "Decimate.h"
DSG::Decimator::Decimator(unsigned long factor):decimationFactor(factor),counter(0),count(0){
//set up filter kernel for windowed sinc filter with a .5 sample rate cutoff
    for (int i=0; i<100; ++i) {
        if (i - 50 == 0) {
            _kernel[i] = TWOPI * 0.5;
        }
        else{
            _kernel[i] = sin(TWOPI * 0.5 * (i-50))/(i-50);
            _kernel[i]*=(0.54 - 0.46*cos(TWOPI*i/100.0));
        }
    }
    DSG::DSGSample sum=0;
    for (int i=0; i<100; ++i) {
        sum+=_kernel[i];
    }
    for (int i=0; i<100; ++i) {
        _kernel[i]/=sum;
    }
}
DSG::Decimator::~Decimator(){}