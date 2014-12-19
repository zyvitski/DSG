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
#include <fstream>
#include <sstream>
const int N = 10000;

int main(int argc, const char * argv[])
{
    DSG::AnalogTriangle _saw(220.0,0);
    DriverInit(&_saw);
    DSG::Sleep(6000);
    DriverExit();
    return 0;
}
