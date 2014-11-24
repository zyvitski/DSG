//
//  Denormal.h
//  DSG
//
//  Created by Alexander Zywicki on 9/23/14.
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
#ifndef DSG_Denormal_h
#define DSG_Denormal_h
#include <limits>
#include "DSGMath.h"
namespace DSG{
    //!\brief DSG::IsDenormal - Returns True if number is Denormal 
    template<typename T>
    inline bool IsDenormal(T const& value){
        return DSG::Abs(value)<=std::numeric_limits<T>::epsilon();//return true if number is denormal
    }
}
#endif