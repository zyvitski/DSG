//
//  Blackman.h
//  DSG
//
//  Created by Alexander Zywicki on 9/24/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef DSG_Blackman_h
#define DSG_Blackman_h
#include "PI.h"
#include "LUT.h"
#include "Sine.h"
namespace DSG {
    //!\brief DSG::Blackman - Blackman Window Function
    // Generate Blackman Window
    /*
        Blackman(x) = 0.42f - (0.5f * cos(2pi*x)) + (0.08f * cos(2pi*2.0*x));
    }*/
    template<typename T>
    inline T Blackman(T const& x){
        static_assert(std::is_floating_point<T>::value==true,"DSG::Blackman Function Requires Floating Point Type");
        //we will implement the blackman window as a function as if it were sin(x)
        //cos input domain 0-1 not 0-2pi
        //range checking is handles within DSG::Cos
        return 0.42 - (0.5 * DSG::Cos(x))+(0.08 * DSG::Cos(2.0*x));
    }
}
#endif