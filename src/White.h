//
//  White.h
//  DSG
//
//  Created by Alexander Zywicki on 10/14/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef DSG_White_h
#define DSG_White_h
#include "DSGTypes.h"
#include <random>
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Noise{
        template<typename decimal = DSG::DSGSample>
        inline decimal White(decimal=0){
            decimal white =(rand()/(decimal)RAND_MAX);
            white -=0.5;
            white*=2.0;
            return white;
        }
    }
}
#endif