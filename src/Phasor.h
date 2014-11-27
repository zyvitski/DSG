//
//  Phasor.h
//  DSG
//
//  Created by Alexander Zywicki on 11/26/14.
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
#ifndef __DSG__Phasor__
#define __DSG__Phasor__
#include "DSGTypes.h"
#include "Bounds.h"
#include "AudioSettings.h"
namespace DSG{
    //!\brief DSG::Phasor - Linear Phase Generator
    class Phasor{
    public:
        Phasor();
        Phasor(DSG::DSGFrequency const& frequency, DSG::DSGPhase const& offset);
        virtual ~Phasor();
        virtual inline DSG::DSGFrequency const& Frequency();
        virtual inline DSG::DSGFrequency const& Frequency(DSG::DSGFrequency const& value);
        virtual inline DSG::DSGPhase const& Phase();
        virtual inline DSG::DSGPhase const& Phase(DSG::DSGPhase const& value);
    protected:
        //extends sample rate interface
        inline void step();
        inline void sync();
        //-----------------------------//
        DSG::DSGFrequency _frequency;//frequency in Hz
        DSG::DSGPhase _dt;//delta time (change in phase per sample) unit: phase 0-1
        DSG::DSGPhase _offset;//phase shift
        DSG::DSGPhase _phasor;//phase counter
    };
    inline DSG::DSGFrequency const& DSG::Phasor::Frequency(){
        return _frequency;
    }
    inline DSG::DSGFrequency const& DSG::Phasor::Frequency(DSG::DSGFrequency const& value){
        _frequency = DSG::EnforceBounds<0, 20000,DSG::DSGSample>(value);
        _dt = _frequency/DSG::SampleRate();
        return _frequency;
    }
    inline DSG::DSGPhase const& DSG::Phasor::Phase(){
        return _offset;
    }
    inline DSG::DSGPhase const& DSG::Phasor::Phase(DSG::DSGPhase const& value){
        _offset-=value;
        _phasor-=_offset;
        _offset=value;
        return _offset;
    }
    inline void DSG::Phasor::step(){
        _phasor+=_dt;
        _phasor>1.0 ? --_phasor:0;
    }
    inline void DSG::Phasor::sync(){
        _phasor=_offset;
    }
}
#endif /* defined(__DSG__Phasor__) */