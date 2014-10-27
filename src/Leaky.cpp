//
//  Leaky.cpp
//  DSG
//
//  Created by Alexander Zywicki on 10/27/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
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
