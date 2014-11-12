//
//  Sine.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__Sine__
#define __DSG__Sine__
#include "LUT.h"
#include "PI.h"
#define LUT_SIZE 16384
namespace DSG {
    namespace{
        typedef enum Sine_Implementations{
            /*!\brief DSG::Sine_Implementations - Specifies The Implementation Option For DSG::Sin<>()*/
            Sine_Taylor =1,
            Sine_LUT =2,
            Sine_Default = Sine_LUT
        }Sine_Implementations;
        /*!\brief DSG::Sin() - Templated Sin Function With Optional Implementation
         */
        template<unsigned implementation> inline double Sin(double const& x){
            return 0;
        }
        template<unsigned implementation> inline double Cos(double const& x){
            return 0;
        }
        template<> inline double Sin<Sine_LUT>(double const& x){
            static DSG::LUT<double, LUT_SIZE> _lut(&sin,TWOPI);
            return _lut(x);
        }
        template<> inline double Cos<Sine_LUT>(double const& x){
            static DSG::LUT<double, LUT_SIZE> _lut(&cos,TWOPI);
            return _lut(x);
        }
        template<> inline double Sin<Sine_Taylor>(double const& x){
            //taylor serie version here
            return 0;
        }
        template<> inline double Cos<Sine_Taylor>(double const& x){
            //taylor series version here
            return 0;
        }
    }
    /*!\brief DSG::Sin() - General Purpose Sin Function Wraps Templated Version
     */
    inline double Sin(double const& x){
        return static_cast<double>(Sin<Sine_Default>(x));//wrap default implementation as non template
    }
    inline float Sin(float const& x){
        return static_cast<float>(Sin<Sine_Default>(x));
    }
    /*!\brief DSG::Cos() - General Purpose Cos Function Wraps Templated Version
     */
    inline double Cos(double const& x){
        return static_cast<double>(Cos<Sine_Default>(x));//wrap default implementation as non template
    }
    inline float Cos(float const& x){
        return static_cast<float>(Cos<Sine_Default>(x));
    }
}
#endif /* defined(__DSG__Sine__) */