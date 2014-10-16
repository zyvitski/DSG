//
//  BLITSaw.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "BLITSaw.h"
DSG::BLIT::BlitSaw::BlitSaw():DSG::BLIT::Blit(),Register_(0){
    Frequency(0);
}
DSG::BLIT::BlitSaw::BlitSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::BLIT::Blit(frequency,offset),Register_(0){
    Frequency(frequency);
}
DSG::BLIT::BlitSaw::~BlitSaw(){}