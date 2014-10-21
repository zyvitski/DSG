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
{   srand(static_cast<unsigned>(time(NULL)));
    DSG::SampleRate(44100);
    DSG::GenericGenerator _gen(20,0,DSG::Sin);
    DriverInit(&_gen);
    DSG::Sleep(2000);
    DriverExit();

    return 0;
    DSG::DSGSample _arr[88200];
    for (int i=0; i<88200; ++i) {
        _arr[i] = DSG::Gaussian();
        std::cout<<_arr[i]<<std::endl;
    }
    DSG::SoundFile::WavFile<DSG::DSGSample> _wav("sndfile.wav",_arr,88200,DSG::SampleRate(),1);
    return 0;
}