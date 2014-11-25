//
//  White.h
//  DSG
//
//  Created by Alexander Zywicki on 10/14/14.
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
#ifndef DSG_White_h
#define DSG_White_h
#include "DSGTypes.h"
#include "Random.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Noise{
        //!\brief DSG::Noise::White - White Noise Generator Function
        template<typename decimal = DSG::DSGSample>
        inline decimal White(decimal=0.0){
            return DSG::Random<decimal>();
        }
    }
}
#endif