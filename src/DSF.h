//
//  DSF.h
//  DSG
//
//  Created by Alexander Zywicki on 11/5/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
/*
 This file is part of the Digital Signal Generation Project or “DSG”.

 DSG is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 DSG is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with DSG.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __DSG__DSF__
#define __DSG__DSF__
#include "DSGMath.h"
#include "DSGTypes.h"
namespace DSG{
    template<typename decimal=DSG::DSGSample>
    decimal DSF(decimal const& beta,decimal const& theta,decimal const& N,decimal const& a){
#ifdef __APPLE__
#warning Untested DSG::DSF()
#endif
        decimal denominator = 1 + DSG::Pow<2>(a) - (2.0*a*cos(beta));
        decimal numerator = sin(theta) - a * sin(theta-beta) - pow(a, N+1) * (sin(theta + (N+1)*beta) - a*sin(theta + (N*beta)));
        return numerator/denominator;
    }
}
#endif /* defined(__DSG__DSF__) */