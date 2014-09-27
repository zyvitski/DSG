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
#include <math.h>
#include <complex>


int main(int argc, const char * argv[])
{
    DSG::SampleRate(44100);
    float arr[4096];
    DSG::GenerateMinBlep<float, 4, 1024>(arr);
    for (int i=0; i<4096; ++i) {
        std::cout<<arr[i]<<std::endl;
    }
    return 0;
}

