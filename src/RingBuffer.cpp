//
//  RingBuffer.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
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

DSG::DSGSample& DSG::RingBuffer::operator[](unsigned long const& index){
#warning Unimplimented DSG::RingBuffer::operator[]
    return _buffer[0];
}