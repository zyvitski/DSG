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
    DSG::Delay<16> _delay(4);
    DSG::DSGSample _samp;
    for (int i=0; i<16; ++i) {
        _samp = i;
        _delay.Perform(_samp);
        std::cout<<i<<": "<<_samp<<std::endl;
    }
    return 0;
    DSG::FourierSaw _saw(50,0);
    DSG::DSGSample _arr[88200];
    for (int i=0; i<88200; ++i) {
        _saw.Perform(_arr[i]);
    }
    DSG::SoundFile::WavFile<DSG::DSGSample> _wav("sndfile.wav",_arr,88200,DSG::SampleRate(),1);
    return 0;
}