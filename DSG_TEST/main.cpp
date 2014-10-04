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
    DSG::BlitSaw _saw(1000,0);
    DSG::DSGSample _buff[44100];
    for (int i=0; i<44100; ++i) {
        _saw.Perform(_buff[i]);
    }
    DSG::SoundFile::WavFile<DSG::DSGSample> _file("sndfile.wav",_buff,44100,44100,1);
    return 0;
}

