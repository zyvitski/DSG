//
//  FourierSquare.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
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
#include "FourierSquare.h"
DSG::Fourier::FourierSquare::FourierSquare():DSG::SignalGenerator(),_a(3.6/PI),phs(0),value(0),i(0){}
DSG::Fourier::FourierSquare::FourierSquare(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset),_a(3.6/PI),phs(0),value(0),i(0){
    _h = MaxHarms(_frequency)+1;
}
DSG::Fourier::FourierSquare::~FourierSquare(){}