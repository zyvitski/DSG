//
//  Buffer.h
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
#ifndef __DSG__Buffer__
#define __DSG__Buffer__
#include <stddef.h>
#include "DSGTypes.h"
#ifdef DEBUG
#include <assert.h>
#endif
namespace DSG{
    /*!\brief DSG::Buffer - Base Class For DSG::RingBuffer. Not For Direct Use
     */
    class Buffer {
    public:
        Buffer();
        Buffer(size_t size);
        Buffer(Buffer const& other);
        Buffer& operator=(Buffer const& other);
        virtual ~Buffer();
        DSG::DSGSample& operator[](size_t const& index);
        inline size_t const& Size()const;
    protected:
        DSG::DSGSample* _buffer;
        size_t _size;
    };
    inline size_t const& DSG::Buffer::Size()const{
        return _size;
    }
}
#endif /* defined(__DSG__Buffer__) */