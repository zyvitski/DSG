//
//  EPTRSaw.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/29/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "EPTRSaw.h"
DSG::EPTR::EPTRSaw::EPTRSaw():DSG::SignalGenerator(){}
DSG::EPTR::EPTRSaw::EPTRSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){}
DSG::EPTR::EPTRSaw::~EPTRSaw(){}