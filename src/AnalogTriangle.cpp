//
//  AnalogTriangle.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "AnalogTriangle.h"
DSG::Analog::AnalogTriangle::AnalogTriangle():DSG::SignalGenerator(){}
DSG::Analog::AnalogTriangle::AnalogTriangle(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){}
DSG::Analog::AnalogTriangle::~AnalogTriangle(){}