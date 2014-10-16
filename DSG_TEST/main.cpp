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

    DSG::RingBuffer _buff(111);
    std::cout<<_buff.Size();

    return 0;
}