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
#include <type_traits>
namespace DSG {
    //!\brief DSG::Abs - Calculate absolute value
    template<typename T>
    inline T Abs(T const& value){
        return value < 0.0 ? -1.0 * value : value;
    }
    //!\brief DSG::Factorial - Compute integer factorial
    template<unsigned long N>
    struct Factorial{
        enum {value = N * Factorial<N-1>::value};
    };
    //!\brief DSG::Factorial - Compute integer factorial
    template<>
    struct Factorial<0>{
        enum{ value = 1 };
    };
    namespace{
        template<class T, unsigned N>
        struct pow_helper{
            static constexpr T pow(const T x){
                return pow_helper<T, N-1>::pow(x) * x;
            }
        };
        template<class T>
        struct pow_helper<T, 0>{
            static constexpr T pow(const T x){
                return 1;
            }
        };
    }
    //!\brief DSG::Pow - Any type to an integer power, i.e. N ^ I 
    template<unsigned exponent, class T>
    T constexpr Pow(T const base){
        return pow_helper<T, exponent>::pow(base);
    }
}
#endif