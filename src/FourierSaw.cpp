//
//  FourierSaw.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "FourierSaw.h"
DSG::Fourier::FourierSaw::FourierSaw():DSG::SignalGenerator(),_a(1.7/PI),phs(0),value(0),i(0){}
DSG::Fourier::FourierSaw::FourierSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset),_a(1.7/PI),phs(0),value(0),i(0){
    _h = MaxHarms(_frequency)+1;
}
DSG::Fourier::FourierSaw::~FourierSaw(){}
