//
//  BLIT.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "BLIT.h"
DSG::BLIT::Blit::Blit():DSG::SignalGenerator(){
    Frequency(0);
}
DSG::BLIT::Blit::Blit(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){
    Frequency(frequency);

}
DSG::BLIT::Blit::~Blit(){}