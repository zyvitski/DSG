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
    
        template <typename element,unsigned long size>
        class LUT {
        public:
            LUT():_size(size){}
            virtual ~LUT(){}
            element const& operator[](unsigned long const& index){
#ifdef DEBUG
                assert(index<_size);
#endif
                return _table[index];
            }
            virtual inline element const&  operator()(double const& x){
                return _table[0];
            }
            unsigned long const& Size()const{
                return _size;
            }
        protected:
            element _table[size];
            const unsigned long _size;
        };
    
}
#endif
