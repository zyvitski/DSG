//
//  RingBuffer.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
/*
 This file is part of the Digital Signal Generation Project or “DSG”.

 DSG is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 DSG is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with DSG.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "RingBuffer.h"
DSG:: RingBuffer::RingBuffer():Buffer(0),_read(0),_write(0),_count(0),MASK(0){}
DSG:: RingBuffer::RingBuffer(const size_t size):Buffer(make_pow_2(size)),_read(0),_write(0),_count(0){
    MASK = this->_size-1;
}
DSG:: RingBuffer::RingBuffer(RingBuffer& buffer):Buffer(buffer){
    _write.store(buffer._write.load(std::memory_order_acquire));
    _read.store(buffer._read.load(std::memory_order_acquire));
    _count = buffer._count;
    MASK = buffer._size-1;
}
DSG:: RingBuffer& DSG:: RingBuffer::operator=(RingBuffer& buffer){
    Buffer::operator=(buffer);
    _write.store(buffer._write.load(std::memory_order_acquire));
    _read.store(buffer._read.load(std::memory_order_acquire));
    _count = buffer._count;
    MASK = buffer._size-1;
    return *this;
}
DSG:: RingBuffer::~RingBuffer(){Flush();}

