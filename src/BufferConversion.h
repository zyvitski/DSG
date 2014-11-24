//
//  BufferConversion.h
//  DSG
//
//  Created by Alexander Zywicki on 10/14/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
/*
 This file is part of the Digital Signal Generation Project or “DSG”.

 DSG is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 DSG is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with DSG.  If not, see <http://www.gnu.org/licenses/>.
 */
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