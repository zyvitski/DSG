//
//  SignalGenerator.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__SignalGenerator__
#define __DSG__SignalGenerator__
#include "SignalProcess.h"
#include "AudioSettings.h"
#include "Sine.h"
#include "Bounds.h"
namespace DSG{
    /*!\brief DSG::SignalGenerator - Extends DSG::Signal Process With Tools For Signal Generation
     */
    class SignalGenerator:public DSG::SignalProcess{
    public:
        SignalGenerator();
        SignalGenerator(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
        virtual ~SignalGenerator();
        virtual inline bool Perform(DSG::DSGSample& signal);
        virtual inline bool Perform(DSG::RingBuffer& signal);
        //Adds interface for control rate processing
        virtual inline DSG::DSGFrequency const& Frequency();
        virtual inline DSG::DSGFrequency const& Frequency(DSG::DSGFrequency const& value);
        virtual inline DSG::DSGPhase const& Phase();
        virtual inline DSG::DSGPhase const& Phase(DSG::DSGPhase const& value);
    protected:
        //extends sample rate interface
        inline void step();
        inline void sync();
        //-----------------------------
        DSG::DSGFrequency _frequency;//frequency in Hz
        DSG::DSGPhase _dt;//delta time (change in phase per sample) unit: phase 0-1
        DSG::DSGPhase _offset;//phase shift
        DSG::DSGPhase _phasor;//phase counter
        DSG::DSGSample _storage;//storage variable for calculations
    };
    inline unsigned long MaxHarms(DSG::DSGFrequency const& frequency){
        double _s = DSG::SampleRate()*  20000.0/DSG::SampleRate();
        _s/=frequency;
        return _s;
    }
}
inline bool DSG::SignalGenerator::Perform(DSG::DSGSample& signal){
    signal=0;
    return false;
}
inline bool DSG::SignalGenerator::Perform(DSG::RingBuffer& signal){
    signal.Flush();
    return false;
}
inline DSG::DSGFrequency const& DSG::SignalGenerator::Frequency(){
    return _frequency;
}
inline DSG::DSGFrequency const& DSG::SignalGenerator::Frequency(DSG::DSGFrequency const& value){
    _frequency = DSG::EnforceBounds<0, 20000,DSG::DSGSample>(value);
    _dt = _frequency/DSG::SampleRate();
    return _frequency;
}
inline DSG::DSGPhase const& DSG::SignalGenerator::Phase(){
    return _offset;
}
inline DSG::DSGPhase const& DSG::SignalGenerator::Phase(DSG::DSGPhase const& value){
    _offset-=value;
    _phasor-=_offset;
    _offset=value;
    return _offset;
}
inline void DSG::SignalGenerator::step(){
    _phasor+=_dt;
    _phasor>1.0 ? --_phasor:0;
}
inline void DSG::SignalGenerator::sync(){
    _phasor=_offset;
}
#endif /* defined(__DSG__SignalGenerator__) */