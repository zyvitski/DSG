//
//  FourierTriangle.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "FourierTriangle.h"
DSG::FourierTriangle::FourierTriangle():DSG::SignalGenerator(){}
DSG::FourierTriangle::FourierTriangle(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){
    _h = MaxHarms(_frequency)+1;
}
DSG::FourierTriangle::~FourierTriangle(){}