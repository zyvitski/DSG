//
//  PolyBlep.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/22/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "PolyBlep.h"
DSG::Blep::PolyBlep::PolyBlep():DSG::SignalGenerator(){}
DSG::Blep::PolyBlep::PolyBlep(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){}
DSG::Blep::PolyBlep::~PolyBlep(){}