//
//  Buffer.cpp
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "Buffer.h"
DSG::Buffer::Buffer():_size(0),_buffer(nullptr){}
DSG::Buffer::Buffer(size_t size):_size(size),_buffer(new DSG::DSGSample[size]){}
DSG::Buffer::Buffer(Buffer const& other) {
    _buffer = new  DSG::DSGSample[_size];
    _size = other._size;
    *this = other;
}
DSG::Buffer& DSG::Buffer::operator=(Buffer const& other){
    if (_size!=other._size) {
        if (_buffer!=nullptr) {
            delete [] _buffer;
        }
        _size = other._size;
        _buffer = new  DSG::DSGSample[_size];
    }
    for (int i=0; i<_size; ++i) {
        _buffer[i] = other._buffer[i];
    }
    return *this;
}
DSG::Buffer::~Buffer(){
    if (_buffer!=nullptr) {
        delete [] _buffer;
    }
}
DSG::DSGSample& DSG::Buffer::operator[](size_t const& index){
#ifdef DEBUG
    assert(index<_size);
#endif
    return _buffer[index];
}