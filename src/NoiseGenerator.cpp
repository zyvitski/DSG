//
//  NoiseGenerator.cpp
//  DSG
//
//  Created by Alexander Zywicki on 10/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "NoiseGenerator.h"
DSG::NoiseGenerator::NoiseGenerator(DSGSample (*StatelessFunction)(DSGSample)):DSG::SignalProcess(){
    _function = StatelessFunction;
}
DSG::NoiseGenerator::~NoiseGenerator(){}
