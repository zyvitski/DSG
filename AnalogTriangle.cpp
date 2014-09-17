//
//  AnalogTriangle.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "AnalogTriangle.h"
DSG::AnalogTriangle::AnalogTriangle():DSG::SignalGenerator(){}
DSG::AnalogTriangle::AnalogTriangle(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){}
DSG::AnalogTriangle::~AnalogTriangle(){}