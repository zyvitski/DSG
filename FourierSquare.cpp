//
//  FourierSquare.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "FourierSquare.h"
DSG::FourierSquare::FourierSquare():DSG::SignalGenerator(){}
DSG::FourierSquare::FourierSquare(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){
    _h = MaxHarms(_frequency)+1;
}
DSG::FourierSquare::~FourierSquare(){}