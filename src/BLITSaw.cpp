//
//  BLITSaw.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "BLITSaw.h"

DSG::BLIT::BlitSaw::BlitSaw():DSG::BLIT::Blit(),p_(0),C2_(0),state_(0),a_(0){
    setHarmonics();
}
DSG::BLIT::BlitSaw::BlitSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::BLIT::Blit(frequency,offset),p_(0),C2_(0),state_(0),a_(0){
    _h = MaxHarms(_frequency);
    setHarmonics();
}
DSG::BLIT::BlitSaw::~BlitSaw(){
    
}