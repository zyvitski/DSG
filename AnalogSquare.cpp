//
//  AnalogSquare.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "AnalogSquare.h"
DSG::AnalogSquare::AnalogSquare():DSG::SignalGenerator(){}
DSG::AnalogSquare::AnalogSquare(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){}
DSG::AnalogSquare::~AnalogSquare(){}