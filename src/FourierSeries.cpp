//
//  FourierSeries.cpp
//  DSG
//
//  Created by Alexander Zywicki on 11/18/14.
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
#include "FourierSeries.h"
DSG::Fourier::Harmonic::Harmonic():_ratio(0),_amplitude(0){}
DSG::Fourier::Harmonic::Harmonic(DSG::DSGSample const& ratio,DSG::DSGSample const& amplitude):_ratio(ratio),_amplitude(amplitude){}
DSG::Fourier::Harmonic::~Harmonic(){
    _ratio=0;
    _amplitude=0;
}
DSG::DSGSample const& DSG::Fourier::Harmonic::Ratio()const{
    return _ratio;
}
DSG::DSGSample const& DSG::Fourier::Harmonic::Ratio(DSG::DSGSample const& value){
    _ratio = value;
    return _ratio;
}
DSG::DSGSample const& DSG::Fourier::Harmonic::Amplitude()const{
    return _amplitude;
}
DSG::DSGSample const& DSG::Fourier::Harmonic::Amplitude(DSG::DSGSample const& value){
    _amplitude=value;
    return _amplitude;
}
DSG::Fourier::FourierSeriesGenerator::FourierSeriesGenerator():DSG::SignalGenerator(){}
DSG::Fourier::FourierSeriesGenerator::FourierSeriesGenerator(DSG::DSGFrequency const& frequency, DSG::DSGPhase const& offset):DSG::SignalGenerator(frequency,offset){}
DSG::Fourier::FourierSeriesGenerator::~FourierSeriesGenerator(){}