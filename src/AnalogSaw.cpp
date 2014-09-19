//
//  AnalogSaw.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "AnalogSaw.h"
DSG::Analog::AnalogSaw::AnalogSaw():DSG::SignalGenerator(){}
DSG::Analog::AnalogSaw::AnalogSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){}
DSG::Analog::AnalogSaw::~AnalogSaw(){}