//
//  SignalGenerator.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "SignalGenerator.h"
DSG::SignalGenerator::SignalGenerator():DSG::SignalProcess(),_phasor(0),_frequency(0),_dt(0),_offset(0){}
DSG::SignalGenerator::SignalGenerator(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):_phasor(0),_frequency(frequency),_dt(0),_offset(offset){
    Frequency(frequency);
    Phase(offset);
}
DSG::SignalGenerator::~SignalGenerator(){}