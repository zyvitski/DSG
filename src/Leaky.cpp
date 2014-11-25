//
//  Leaky.cpp
//  DSG
//
//  Created by Alexander Zywicki on 10/27/14.
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
#include "Leaky.h"
DSG::Filter::LeakyIntegrator::LeakyIntegrator():DSG::Filter::FilterBase(){
    x1=0;
    y1=0;
    a=0;
    b=0;
    y=0;
}
DSG::Filter::LeakyIntegrator::LeakyIntegrator(DSG::DSGFrequency const& cutoff):DSG::Filter::FilterBase(){
    x1=0;
    y1=0;
    a=0;
    b=0;
    y=0;
    Cutoff(cutoff);
}
DSG::Filter::LeakyIntegrator::~LeakyIntegrator(){
    x1=0;
    y1=0;
    a=0;
    b=0;
    y=0;
}
