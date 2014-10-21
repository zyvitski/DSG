//
//  LUT.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/25/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef Waveform_LUT_h
#define Waveform_LUT_h
#ifdef DEBUG
#include <assert.h>
#endif
namespace DSG{
    //!\brief DSG::LUT<element,size> - Look Up Table
    template <typename element,unsigned long size>
    class LUT {
    public:
        typedef element (*FillFunction)(element);
        typedef element (*FillFunctionConstRef)(element const&);
        LUT():_size(size){}
        LUT(FillFunction fill,double const& range = 1.0):_size(size){
            //range is the expected input range for the function
            //example would  be 0-2pi or 0-1
            //would be provided a 2pi or 1
            //defaults to 1
            double step = range/(double)_size;
            phs = 0;
            for (int i=0; i<_size; ++i) {
                _table[i] = fill(phs);
                phs+=step;
            }
        }
        LUT(FillFunctionConstRef fill,double const& range = 1.0):_size(size){
            //range is the expected input range for the function
            //example would  be 0-2pi or 0-1
            //would be provided a 2pi or 1
            //defaults to 1
            double step = range/_size;
            phs = 0;
            for (int i=0; i<_size; ++i) {
                _table[i] = fill(phs);
                phs+=step;
            }
        }
        ~LUT(){}
        element const& operator[](unsigned long const& index)const{
#ifdef DEBUG
            assert(index<_size);
#endif
            return _table[index];
        }
        element& operator[](unsigned long const& index){
#ifdef DEBUG
            assert(index<_size);
#endif
            return _table[index];
        }
        inline element const&  operator()(double const& x){
            phs=x;
            //need range checking on x to ensure 0-1 range
            phs<0 ? phs = 1-(phs*-1):0;
            phs-=((int)phs);
            return this->_table[(unsigned)(phs* (this->_size-1))];
        }
        unsigned long const& Size()const{
            return _size;
        }
    protected:
        element _table[size];
        const unsigned long _size;
        double phs;
    };
}
#endif