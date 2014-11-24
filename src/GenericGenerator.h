//
//  GenericGenerator.h
//  DSG
//
//  Created by Alexander Zywicki on 10/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
/*
 This file is part of the Digital Signal Generation Project or “DSG”.

 DSG is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 DSG is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with DSG.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __DSG__GenericGenerator__
#define __DSG__GenericGenerator__
#include "SignalGenerator.h"
namespace DSG{
    //!\brief DSG::GenericGenerator - Generator designed to use a stateless generator function such as DSG::Sin()
    class GenericGenerator:public DSG::SignalGenerator{
    public:
        GenericGenerator();
        GenericGenerator(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset,DSG::DSGSample (*signalFunction)(DSG::DSGSample const&));
        virtual ~GenericGenerator();
        virtual inline bool Perform(DSG::DSGSample& signal);
        virtual inline bool Perform(DSG::RingBuffer& signal);
    protected:
        DSG::DSGSample (*_callback)(DSG::DSGSample const&);
    };
    inline bool DSG::GenericGenerator::Perform(DSG::DSGSample& signal){
        if (_callback!=nullptr) {
            signal = _callback(_phasor);
        }else signal = 0;
        step();
        return true;
    }
    inline bool DSG::GenericGenerator::Perform(DSG::RingBuffer& signal){
        signal.Flush();
        while (!signal.Full()) {
            if (Perform(_storage)) {
                if(signal.Write(_storage)){
                }else return false;
            }else return false;
        }return true;
    }
}
#endif /* defined(__DSG__GenericGenerator__) */