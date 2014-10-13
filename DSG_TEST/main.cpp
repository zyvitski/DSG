//
//  main.cpp
//  DSG_TEST
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
//#include "../src/DSG.h"
#include "../src/Driver.h"
#include <iostream>
int main(int argc, const char * argv[])
{DSG::SampleRate(44100);
    DSG::RingBuffer _b(256);
    DSG::Decimator _dec(4);
    DSG::AnalogSaw _sa(20,0);
    _sa.Perform(_b);
    std::cout<<_b;
    _dec.Perform(_b);
    std::cout<<_b;


        return 0;
}