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
    DSG::RingBuffer _b(16);
    DSG::DSGSample _s;
    for (int i=0; i<_b.Size(); ++i) {
        _b.Write(i);
        //std::cout<<_b[i]<<std::endl;
    }
    _b.Read(_s);
    for (int i=0; i<_b.Count(); ++i) {
        std::cout<<_b[i]<<std::endl;
    }




    return 0;
}