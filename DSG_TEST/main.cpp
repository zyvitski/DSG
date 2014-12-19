//
//  main.cpp
//  DSG_TEST
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//


#ifdef DEBUG
#include <iostream>
#endif

#include <DSG/DSG.h>

int main(int argc, const char * argv[])
{
    DSG::RingBuffer b(4096);
    DSG::AnalogSaw _saw(20,0);
    _saw.Perform(b);
    DSG::File::Write<DSG::File::PlotFile>("filename", b);

    return 0;
}
