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
#ifdef DEBUG
std::ostream& DSG:: operator<<(std::ostream& os,DSG:: RingBuffer const& buffer){
    if (!buffer.Empty()) {
        size_t index= buffer._read;
        size_t count=buffer.Count();
        size_t size = buffer.Size();
        for (int i=0; i<count; ++i) {
            os<<index<<": "<<buffer._buffer[index]<<std::endl;
            index = ((index+1)%size);
        }
    }return os;
}
#endif