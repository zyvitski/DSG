//
//  Gaussian.h
//  DSG
//
//  Created by Alexander Zywicki on 10/6/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef DSG_Gaussian_h
#define DSG_Gaussian_h
#include "Sine.h"
#include "White.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Noise{
        template<typename decimal=DSG::DSGSample>
        decimal Gaussian(decimal=0){
            //to enforce compatability with DSG::LUT a dummy parameter is applied
            //this parameter is useless except for compatability reasons
            decimal R1 = DSG::Noise::White();
            decimal R2 = DSG::Noise::White();
            decimal x= (decimal)sqrt(-2.0f * log(R1))*DSG::Cos(R2);
            return x;
        }
    }
}
#endif