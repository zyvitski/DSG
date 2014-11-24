//
//  Window.h
//  DSG
//
//  Created by Alexander Zywicki on 10/17/14.
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
#ifndef DSG_Window_h
#define DSG_Window_h
#include "LUT.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //!\brief DSG::Window - Window functions and utilities
    namespace Window{
        //!\brief DSG::Window::ApplyWindow - Apply a window function to a LUT
        template<typename decimal,unsigned long lutsize>
        void ApplyWindow(DSG::LUT<decimal,lutsize>& lut,decimal (&windowFunction)(decimal const&),decimal range = 1.0){
            decimal step = range/(decimal)lut.Size();
            decimal phs=0;
            for (int i=0; i<lut.Size(); ++i) {
                lut[i]*=windowFunction(phs);
                phs+=step;
            }
        }
        //!\brief DSG::Window::ApplyWindow - Apply a window function to a LUT
        template<typename decimal,unsigned long lutsize>
        void ApplyWindow(DSG::LUT<decimal,lutsize>& lut,decimal (&windowFunction)(decimal),decimal range = 1.0){
            decimal step = range/(decimal)lut.Size();
            decimal phs=0;
            for (int i=0; i<lut.Size(); ++i) {
                lut[i]*=windowFunction(phs);
                phs+=step;
            }
        }
    }
}
#endif