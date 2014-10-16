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
    template<typename decimal = DSG::DSGSample>
    inline decimal White(decimal=0){
        return 0;
    }
}
#endif