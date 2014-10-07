//
//  Leaky.h
//  DSG
//
//  Created by Alexander Zywicki on 9/24/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__Leaky__
#define __DSG__Leaky__
#include <type_traits>
#include "DSGTypes.h"
namespace DSG {
    template<typename T=DSG::DSGSample>
    inline T Leaky(T const& input,T const& lastOutput,T const& a1){
        static_assert(std::is_floating_point<T>::value==true,"T is not floating point");
        return input + a1*lastOutput;
    }
}
#endif /* defined(__DSG__Leaky__) */