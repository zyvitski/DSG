//
//  Interpolate.h
//  DSG
//
//  Created by Alexander Zywicki on 10/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
//Code In this file was adapted from the code provided on this website
//http://paulbourke.net/miscellaneous/interpolation/
//
#ifndef DSG_Interpolate_h
#define DSG_Interpolate_h
#include "DSGMath.h"
#include "PI.h"
namespace DSG{
    template<typename decimal>
    decimal LinearInterpolate(decimal const& y1,decimal const& y2,decimal const& mu){
        return(y1*(1-mu)+y2*mu);
    }
    template<typename decimal>
    decimal CosineInterpolate(
                              decimal y1,decimal y2,
                              decimal mu)
    {
        decimal mu2;
        mu2 = (1-cos(mu*PI))/2.0;
        return(y1*(1-mu2)+y2*mu2);
    }
    template<typename decimal>
    decimal CubicInterpolate(decimal const& y0,decimal const& y1,
                             decimal const& y2,decimal const& y3,
                             decimal const& mu)
    {
        decimal a0,a1,a2,a3,mu2;
        mu2 = mu*mu;
        a0 = y3 - y2 - y0 + y1;
        a1 = y0 - y1 - a0;
        a2 = y2 - y0;
        a3 = y1;
        return(a0*mu*mu2+a1*mu2+a2*mu+a3);
    }
    /*
     Tension: 1 is high, 0 normal, -1 is low
     Bias: 0 is even,
     positive is towards first segment,
     negative towards the other
     */
    template<typename decimal>
    decimal HermiteInterpolate(decimal const& y0,decimal const& y1,
                              decimal const& y2,decimal const& y3,
                              decimal const& mu,
                              decimal const& tension,
                              decimal const& bias)
    {
        decimal m0,m1,mu2,mu3;
        decimal a0,a1,a2,a3;
        mu2 = mu * mu;
        mu3 = mu2 * mu;
        m0  = (y1-y0)*(1+bias)*(1-tension)/2.0;
        m0 += (y2-y1)*(1-bias)*(1-tension)/2.0;
        m1  = (y2-y1)*(1+bias)*(1-tension)/2.0;
        m1 += (y3-y2)*(1-bias)*(1-tension)/2.0;
        a0 =  2*mu3 - 3*mu2 + 1;
        a1 =    mu3 - 2*mu2 + mu;
        a2 =    mu3 -   mu2;
        a3 = -2*mu3 + 3*mu2;
        return(a0*y1+a1*m0+a2*m1+a3*y2);
    }
}
#endif