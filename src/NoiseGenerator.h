//
//  NoiseGenerator.h
//  DSG
//
//  Created by Alexander Zywicki on 10/20/14.
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
#ifndef __DSG__NoiseGenerator__
#define __DSG__NoiseGenerator__
#include "SignalGenerator.h"
namespace DSG{
    //!\brief DSG::NoiseGenerator - Generator that uses noise functions such as DSG::White() to generate signal
    class NoiseGenerator:public SignalProcess{
    public:
        NoiseGenerator(DSGSample (*StatelessFunction)(DSGSample));
        virtual ~NoiseGenerator();
        virtual inline bool Perform(DSG::DSGSample& signal);
        virtual inline bool Perform(DSG::RingBuffer& signal);
    protected:
        DSGSample (*_function)(DSGSample);
        DSG::DSGSample _storage;
    };
    inline bool DSG::NoiseGenerator::Perform(DSG::DSGSample& signal){
        signal = _function(0);
        return true;
    }
    inline bool DSG::NoiseGenerator::Perform(DSG::RingBuffer& signal){
        signal.Flush();
        while (!signal.Full()) {
            if (Perform(_storage)) {
                if(signal.Write(_storage)){
                }else return false;
            }else return false;
        }return true;
    }
}
#endif /* defined(__DSG__NoiseGenerator__) */