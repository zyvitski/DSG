//
//  Sleep.h
//  DSG_Tests
//
//  Created by Alexander Zywicki on 10/5/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG_Tests__Sleep__
#define __DSG_Tests__Sleep__
#include <chrono>
#include <thread>
namespace DSG{
    template<typename integer>
    void Sleep(integer const& milliseconds){
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
}
#endif /* defined(__DSG_Tests__Sleep__) */