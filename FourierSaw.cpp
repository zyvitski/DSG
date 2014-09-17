//
//  FourierSaw.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "FourierSaw.h"

DSG::FourierSaw::FourierSaw():DSG::SignalGenerator(){}
DSG::FourierSaw::FourierSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){
    _h = MaxHarms(_frequency);
}
DSG::FourierSaw::~FourierSaw(){}
