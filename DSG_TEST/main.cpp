//
//  main.cpp
//  DSG_TEST
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
//#include "../src/DSG.h"
#include "../src/Driver.h"
#ifdef DEBUG
#include <iostream>
#endif
int main(int argc, const char * argv[])
{
    DSG::SampleRate(44100);
    DSG::FourierSeriesGenerator _f(20,0);
    DSG::FourierSeriesGenerator::FourierSeries _series;
    for (int i=1; i<1000; ++i) {
        DSG::Harmonic _h((double)i,1.0/(double)i);
        _series.push_back(_h);
    }
    _f.Series(_series);
    DSG::RingBuffer _buff(4096);
    _f.Perform(_buff);
    std::cout<<_buff;
        
}