//
//  DSF.h
//  DSG
//
//  Created by Alexander Zywicki on 11/5/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__DSF__
#define __DSG__DSF__
#include "DSGMath.h"
#include "DSGTypes.h"
namespace DSG{
    template<typename decimal=DSG::DSGSample>
    decimal DSF(decimal const& beta,decimal const& theta,decimal const& N,decimal const& a){
#warning Untested DSG::DSF()
        decimal denominator = 1 + DSG::Pow<2>(a) - (2.0*a*cos(beta));
        decimal numerator = sin(theta) - a * sin(theta-beta) - pow(a, N+1) * (sin(theta + (N+1)*beta) - a*sin(theta + (N*beta)));
        return numerator/denominator;
    }
}
#endif /* defined(__DSG__DSF__) */