//
//  Blackman.h
//  DSG
//
//  Created by Alexander Zywicki on 9/24/14.
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
#ifndef DSG_Blackman_h
#define DSG_Blackman_h
#include "PI.h"
#include "LUT.h"
#include "Sine.h"
namespace DSG {
#ifdef DSG_Short_Names
    inline
#endif
    namespace Window{
        //!\brief DSG::Window::Blackman - Blackman Window Function
        template<typename decimal>
        inline decimal Blackman(decimal const& x){
            // Generate Blackman Window
            /*
             Blackman(x) = 0.42f - (0.5f * cos(2pi*x)) + (0.08f * cos(2pi*2.0*x));
             }*/
            static_assert(std::is_floating_point<decimal>::value==true,"DSG::Blackman Function Requires Floating Point Type");
            //we will implement the blackman window as a function as if it were sin(x)
            //cos input domain 0-1 not 0-2pi
            //range checking is handles within DSG::Cos
            decimal phs=x;
            while (phs>1.0) {
                phs-=1.0;
            }
            return 0.42 - (0.5 * DSG::Cos(phs))+(0.08 * DSG::Cos(2.0*phs));
        }
    }
}
#endif