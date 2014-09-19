//
//  BLIT.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "BLIT.h"
DSG::BLIT::Blit::Blit():DSG::SignalGenerator(){
    setHarmonics();
}
DSG::BLIT::Blit::Blit(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){
    _nHarms = MaxHarms(_frequency);
    setHarmonics();
}
DSG::BLIT::Blit::~Blit(){}