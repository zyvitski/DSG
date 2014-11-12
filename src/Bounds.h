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
    template<int lower,int upper,typename decimal>
    decimal EnforceBounds(decimal const& value){
        if (value<lower) {
            return lower;
        }else if(value> upper){
            return upper;
        }else return value;
    }
    template<int lower,int upper,typename T>
    void StaticAssertBounds(T const& value){
        static_assert(value>=lower && value<=upper,"Failed Static Bounds Assert");
    }
    template<int lower,int upper,typename T>
    void AssertBounds(T const& value){
        assert(value>=lower && value<=upper);
    }
}
#endif