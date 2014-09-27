//
//  SineLUT.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/25/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef Waveform_SineLUT_h
#define Waveform_SineLUT_h
#include <stdint.h>
#include <math.h>
#include "LUT.h"
#include "PI.h"
namespace DSG{
    template <typename element, unsigned long size>
    class SineLUT:public LUT<element,size> {
    public:
        SineLUT():LUT<element,size>(){
            double step = (TWOPI/this->_size);
            double phs=0;
            for (int i=0; i<this->_size; ++i) {
                this->_table[i] = sin(phs);
                phs+=step;
            }
        }
        virtual ~SineLUT(){}
        virtual inline element const& operator()(double const& x){
            phs=x;
            //need range checking on x to ensure 0-1 range
            phs<0 ? phs = 1-(phs*-1):0;
            phs-=((int)phs);
            return this->_table[(unsigned)(phs* (this->_size-1))];
        }
    protected:
        double phs;
    };
    template <typename element, unsigned long size>
    class CosineLUT:public LUT<element,size> {
    public:
        CosineLUT():LUT<element,size>(){
            double step = (TWOPI/this->_size);
            double phs=0;
            for (int i=0; i<this->_size; ++i) {

                this->_table[i] = cos(phs);
                phs+=step;
            }
        }
        virtual ~CosineLUT(){}
        virtual inline element const& operator()(double const& x){
            phs=x;
            //need range checking on x to ensure 0-1 range
            phs<0 ? phs = 1-(phs*-1):0;
            phs-=((int)phs);
            return this->_table[(unsigned)(phs* (this->_size-1))];
        }
    protected:
        double phs;
    };

    template <typename element, unsigned long size>
    class SmallSineLUT:public LUT<element,size> {
    public:
        SmallSineLUT():LUT<element,size>(){fill();}
        virtual ~SmallSineLUT(){}
        virtual inline element operator()(double const& x){
            double phs=x;
            //need range checking on x to ensure 0-1 range
            phs=fabs(phs);
            phs=phs-((int)phs);
            if (phs>=0.0 && phs<=0.25) {
                //sin(x) = sin(x)
                return lookup(phs*4);
            }else if (phs>0.25 && phs<=0.5){
                //sin(x) =      sin(pi-x). We are working in 0-1 range not 0-2pi so 0.5 is substituted for pi
                return lookup(2-(phs*4));
            }else if (phs>0.5 && phs<=0.75){
                //sin(x)=-sin(pi+x);
                return -lookup((phs*4)-2);
            }else if (phs>0.75 && phs<=1.0){
                //sin(x) = -sin(-x)
                return -lookup(4-(phs*4));
            }
            return 0;
        }
    protected:
        inline void fill(){
            double step = (M_PI_2/this->_size);
            double phs=0;
            for (int i=0; i<this->_size; ++i) {
                this->_table[i] = sin(phs);
                phs+=step;
            }
        }
        inline element const& lookup(double index){
            //possibvly interpolate for better quality
            return this->_table[(unsigned)(index* (this->_size-1))];
        }
    };
    template <unsigned long size>
    class SmallSineLUT<int32_t,size>:public LUT<int32_t,size> {
    public:
        SmallSineLUT():LUT<int32_t,size>(){fill();}
        virtual ~SmallSineLUT(){}
        virtual inline int32_t operator()(double const& x){
            double phs=x;
            //need range checking on x to ensure 0-1 range
            phs=fabs(phs);
            phs=phs-((int32_t)phs);
            if (phs>=0.0 && phs<=0.25) {
                //sin(x) = sin(x)
                return lookup(phs*4);
                
            }else if (phs>0.25 && phs<=0.5){
                //sin(x) =      sin(pi-x). We are working in 0-1 range not 0-2pi so 0.5 is substituted for pi
                return lookup(2-(phs*4));
            }else if (phs>0.5 && phs<=0.75){
                //sin(x)=-sin(pi+x);
                return -lookup((phs*4)-2);
            }else if (phs>0.75 && phs<=1.0){
                //sin(x) = -sin(-x)
                return -lookup(4-(phs*4));
            }else{}
            return 0;
        }
    protected:
        inline void fill(){
            double step = (M_PI_2/this->_size);
            double phs=0;
            double scale = pow(2, sizeof(int32_t)*8)*0.5;
            for (int32_t i=0; i<this->_size; ++i) {
                this->_table[i] = sin(phs)*scale;
                phs+=step;
            }
        }
        inline int32_t const& lookup(double&& index){
            //possibvly interpolate for better quality
            return this->_table[(unsigned)(index* (this->_size-1))];
        }
    };
}
#endif