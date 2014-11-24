//
//  FourierSeries.cpp
//  DSG
//
//  Created by Alexander Zywicki on 11/18/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
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