//
//  AnalogSquare.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "AnalogSquare.h"
DSG::Analog::AnalogSquare::AnalogSquare():DSG::SignalGenerator(){}
DSG::Analog::AnalogSquare::AnalogSquare(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){}
DSG::Analog::AnalogSquare::~AnalogSquare(){}