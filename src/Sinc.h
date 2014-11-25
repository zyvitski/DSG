//
//  Sinc.h
//  DSG
//
//  Created by Alexander Zywicki on 9/23/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
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
#ifndef __DSG__Sinc__
#define __DSG__Sinc__
#include "PI.h"
#include "Sine.h"
#include "Denormal.h"
#include <type_traits>
#include "DSGMath.h"
namespace DSG{
    //!\brief DSG::Sinc - Implements the Sinc() function (sin(PI*x)/PI*x)
    template<typename decimal>
    inline decimal Sinc(decimal const& x) {
        static_assert(std::is_floating_point<decimal>::value==true,"DSG::Sinc Function Requires Floating Point Type");
        decimal pix;
        if (DSG::IsDenormal(x)) {
            return 1.0;
        }else{
            pix = PI*x;
            return DSG::Sin(pix)/pix;
        }
    }
}
#endif /* defined(__DSG__Sinc__) */