//
//  Delay.h
//  DSG
//
//  Created by Alexander Zywicki on 10/23/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __DSG__Delay__
#define __DSG__Delay__
#include "DSGTypes.h"
#include "SignalProcess.h"
#include "Interpolate.h"
#include "AudioSettings.h"
namespace DSG{
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
