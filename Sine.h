//
//  Sine.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __DSG__Sine__
#define __DSG__Sine__

#include "SineLUT.h"

#define LUT_SIZE 16384

namespace DSG {
    typedef enum Sine_Implementations{
        Sine_Taylor =1,
        Sine_LUT =2,
        Sine_Default = Sine_LUT
    }Sine_Implementations;
    
    template<unsigned implementation=Sine_Default> inline double Sin(double const& x){
        return Sin<implementation>(x);//default to lut
    }
    static DSG::SineLUT<float, LUT_SIZE> _lut;
    template<> inline double Sin<Sine_LUT>(double const& x){
        return _lut(x);
    }
    template<> inline double Sin<Sine_Taylor>(double const& x){
        //taylor serie version here
        return 0;
    }
    inline double Sin(double const& x){
        return Sin<>(x);//wrap default implementation as non template
    }
}

#endif /* defined(__DSG__Sine__) */
