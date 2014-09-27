//
//  Denormal.h
//  DSG
//
//  Created by Alexander Zywicki on 9/23/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef DSG_Denormal_h
#define DSG_Denormal_h
#include <limits>
#include "DSGMath.h"
namespace DSG{
    template<typename T>
    inline bool IsDenormal(T const& value){
        return DSG::Abs(value)<=std::numeric_limits<T>::epsilon();//return true is number is denormal
    }
}

#endif
