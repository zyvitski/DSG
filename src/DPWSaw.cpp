//
//  DPWSaw.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/27/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "DPWSaw.h"

DSG::DPW::DPWSaw::DPWSaw():DSG::SignalGenerator(),_register(0),_delay1(0){}
DSG::DPW::DPWSaw::DPWSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset),_register(0),_delay1(0){}
DSG::DPW::DPWSaw::~DPWSaw(){}