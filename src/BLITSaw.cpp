//
//  BLITSaw.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/17/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
/*
 This file is part of the Digital Signal Generation Project or “DSG”.

 DSG is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 DSG is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with DSG.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "BLITSaw.h"
DSG::BLIT::BlitSaw::BlitSaw():DSG::BLIT::Blit(),Register_(0){
    Frequency(0);
}
DSG::BLIT::BlitSaw::BlitSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::BLIT::Blit(frequency,offset),Register_(0){
    Frequency(frequency);
}
DSG::BLIT::BlitSaw::~BlitSaw(){}