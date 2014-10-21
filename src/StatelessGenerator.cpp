//
//  StatelessGenerator.cpp
//  DSG
//
//  Created by Alexander Zywicki on 10/20/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#include "StatelessGenerator.h"
DSG::StatelessGenerator::StatelessGenerator(DSGSample (*StatelessFunction)(DSGSample)):DSG::SignalProcess(){
    _function = StatelessFunction;
}
DSG::StatelessGenerator::~StatelessGenerator(){}
