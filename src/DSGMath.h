//
//  Math.h
//  DSG
//
//  Created by Alexander Zywicki on 9/23/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef DSG_Math_h
#define DSG_Math_h
#include <math.h>
namespace DSG {
    template<typename T>
    inline T Abs(T const& value){
        return value<0.0 ? -1.0* value:value;
    }
}
#endif