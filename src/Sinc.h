//
//  Sinc.h
//  DSG
//
//  Created by Alexander Zywicki on 9/23/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __DSG__Sinc__
#define __DSG__Sinc__

#include "PI.h"
#include "Sine.h"
#include "Denormal.h"
#include <type_traits>
namespace DSG{
    
    template<typename T>
    inline T Sinc(T const& x) {
        static_assert(std::is_floating_point<T>::value==true,"DSG::Sinc Function Requires Floating Point Type");
        T pix;
        if (DSG::IsDenormal(x)) {
             return 1.0;
        }else{
            pix = PI*x;
            return DSG::Sin(pix)/pix;
        }
    }
    //SincM(X) = sin(Pi*X)/M sin(Pi*X/M)
    inline double SincM(double const& x,unsigned long const& M){
        //two sin calls per SincM
        double value=0;
        double denom = DSG::Sin(x);
        if (DSG::IsDenormal(denom)) {
            return 1.0;
        }else{
            value= DSG::Sin(M * x);
            value/=M * denom;
            return value;
        }
    }
}
#endif /* defined(__DSG__Sinc__) */