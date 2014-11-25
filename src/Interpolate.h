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
/*
 This file is part of the Digital Signal Generation Project or “DSG”.

 DSG is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 DSG is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with DSG.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DSG_Interpolate_h
#define DSG_Interpolate_h
#include "DSGMath.h"
#include "PI.h"
namespace DSG{
    //!\brief DSG::LinearInterpolate - Linear Interpolation
    template<typename decimal>
    decimal LinearInterpolate(decimal const& y1,decimal const& y2,decimal const& mu){
        return(y1*(1-mu)+y2*mu);
    }
    //!\brief DSG::CosineInterpolate - Cosine Interpolation
    template<typename decimal>
    decimal CosineInterpolate(
                              decimal y1,decimal y2,
                              decimal mu)
    {
        decimal mu2;
        mu2 = (1-cos(mu*PI))/2.0;
        return(y1*(1-mu2)+y2*mu2);
    }
    //!\brief DSG::CubicInterpolate - Cubic Interpolation
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
    //!\brief DSG::HermiteInterpolate - Hermite Interpolation
    template<typename decimal>
    decimal HermiteInterpolate(decimal const& y0,decimal const& y1,
                              decimal const& y2,decimal const& y3,
                              decimal const& mu,
                              decimal const& tension,
                              decimal const& bias)
    {
        /*
         Tension: 1 is high, 0 normal, -1 is low
         Bias: 0 is even,
         positive is towards first segment,
         negative towards the other
         */
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