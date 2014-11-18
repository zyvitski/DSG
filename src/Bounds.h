//
//  Bounds.h
//  DSG
//
//  Created by Alexander Zywicki on 11/11/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
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