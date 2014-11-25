//
//  Bounds.h
//  DSG
//
//  Created by Alexander Zywicki on 11/11/14.
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
#ifndef DSG_Bounds_h
#define DSG_Bounds_h
#include <assert.h>
namespace DSG{
    //!\brief DSG::EnforceBounds - Clip value to set bounds
    template<int lower,int upper,typename decimal>
    decimal EnforceBounds(decimal const& value){
        if (value<lower) {
            return lower;
        }else if(value> upper){
            return upper;
        }else return value;
    }
    //!\brief DSG::StaticAssertBounds - Fails on compile time if value is not within bounds
    template<int lower,int upper,int value>
    void StaticAssertBounds(){
        static_assert(value>=lower && value<=upper,"Failed Static Bounds Assert");
    }
    //!\brief DSG::AssertBounds - Fails on runtime if value is not within bounds
    template<int lower,int upper,typename T>
    void AssertBounds(T const& value){
        assert(value>=lower && value<=upper);
    }
}
#endif