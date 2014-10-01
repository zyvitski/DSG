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
{
    DSG::SampleRate(44100);
    DSG::DPWSaw _saw(20,0);
    DSG::RingBuffer _buff(4096);
    _saw.Perform(_buff);
    std::cout<<_buff;
    return 0;
}

