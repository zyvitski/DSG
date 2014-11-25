//
//  Delay.h
//  DSG
//
//  Created by Alexander Zywicki on 10/23/14.
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
#ifndef __DSG__Delay__
#define __DSG__Delay__
#include "DSGTypes.h"
#include "SignalProcess.h"
#include "Interpolate.h"
#include "AudioSettings.h"
namespace DSG{
    //!\brief DSG::Delay - General purpose delay line
    template<unsigned long maxLength>
    class Delay:public DSG::SignalProcess{
    public:
        Delay():DSG::SignalProcess(),_max(maxLength),_swap(0),_temp(0),count(0),_index(0),_delay(0){
            for (int i=0; i<_max; ++i) {
                _buffer[i]=0;
            }
        }
        Delay(double const& samples):DSG::SignalProcess(),_max(maxLength),_swap(0),_temp(0),count(0),_index(0),_delay(0){
            for (int i=0; i<_max; ++i) {
                _buffer[i]=0;
            }
            if (samples>maxLength) {
                _delay = maxLength;
            }else{
                _delay = samples;
            }
        }
        virtual ~Delay(){}
        virtual inline unsigned long const& Length()const{
            return _delay;
        }
        virtual inline unsigned long const& Length(unsigned long const& samples){
            if (samples>maxLength) {
                _delay = maxLength;
            }else{
                _delay = samples;
            }
            return _delay;
        }
        virtual inline bool Perform(DSG::DSGSample& signal);
        virtual inline bool Perform(DSG::RingBuffer& signal);
    protected:
        unsigned long count;
        unsigned long  _delay;
        unsigned long _index;
        const unsigned long _max;
        DSG::DSGSample _buffer[maxLength];
        DSG::DSGSample _swap;
        DSG::DSGSample _temp;
        virtual inline void increment(){
            ++_index;
            if (_index>_delay) {
                _index-=_delay;
            }
        }
    };
    template<unsigned long maxLength>
    inline bool DSG::Delay<maxLength>::Perform(DSG::DSGSample& signal){
        _swap = _buffer[_index-1];
        _buffer[_index-1]=signal;
        signal = _swap;
        increment();
        return true;
    }
    template<unsigned long maxLength>
    inline bool DSG::Delay<maxLength>::Perform(DSG::RingBuffer& signal){
        if (!signal.Empty()) {
            count = signal.Count();
            while (count-- > 0) {
                if(signal.Read(_temp)){
                    if (Perform(_temp)) {
                        signal.Write(_temp);
                    }else return false;
                }else return false;
            }return true;
        }else return false;
    }
}
#endif /* defined(__DSG__Delay__) */