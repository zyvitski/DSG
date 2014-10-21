//
//  GenericGenerator.cpp
//  DSG
//
//  Created by Alexander Zywicki on 10/21/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "GenericGenerator.h"
DSG::GenericGenerator::GenericGenerator():DSG::SignalGenerator(){}
DSG::GenericGenerator::GenericGenerator(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset,DSG::DSGSample (*signalFunction)(DSG::DSGSample const&)):DSG::SignalGenerator(frequency,offset){}
DSG::GenericGenerator::~GenericGenerator(){}