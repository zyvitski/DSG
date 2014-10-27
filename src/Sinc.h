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
#include "DSGMath.h"
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
}
#endif /* defined(__DSG__Sinc__) */