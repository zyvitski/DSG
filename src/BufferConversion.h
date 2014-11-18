//
//  BufferConversion.h
//  DSG
//
//  Created by Alexander Zywicki on 10/14/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__BufferConversion__
#define __DSG__BufferConversion__
#include "RingBuffer.h"
namespace DSG {
    //!\brief DSG::RingToArray - Move Ring Buffer data to an array
    inline bool RingToArray(DSG::RingBuffer& ring,DSG::DSGSample* array,unsigned long length){
        for (int i=0; i<length; ++i) {
            if (!ring.Empty()) {
                ring.Read(array[i]);
            }
        }return true;
    }
    //!\brief DSG::ArrayToRing - Move array data to a Ring Buffer
    inline bool ArrayToRing(DSG::RingBuffer& ring,DSG::DSGSample* array, unsigned long length){
        int i=0;
        ring.Flush();
        while (!ring.Full()) {
            ring.Write(array[i]);
            ++i;
        }return true;
    }
}
#endif /* defined(__DSG__BufferConversion__) */