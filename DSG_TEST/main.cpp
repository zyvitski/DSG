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
    DSG::FourierSaw _saw(10.0,0);

    DriverInit(&_saw);
    Pa_Sleep(10000);
    DriverExit();
    
    return 0;
}

