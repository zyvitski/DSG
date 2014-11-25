//
//  Buffer.cpp
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