//
//  Buffer.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
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