//
//  RingBuffer.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__RingBuffer__
#define __DSG__RingBuffer__
#ifdef DEBUG
#include <iostream>
#endif
#include <atomic>
#include "DSGMath.h"
#include "Buffer.h"
namespace DSG {
    /*!\brief DSG::RingBuffer - Circular Buffer of Audio
     */
    class RingBuffer:public DSG::Buffer {
    protected:
        std::atomic<size_t> _write;
        std::atomic<size_t> _read;
        size_t _count;
        size_t MASK;
        size_t write;
        size_t read;
        inline size_t next(size_t current);
        inline size_t make_pow_2(size_t number);
    public:
        RingBuffer();
        RingBuffer(const size_t size);
        RingBuffer(RingBuffer& buffer);
        RingBuffer& operator=(RingBuffer& buffer);
        virtual ~RingBuffer();
        inline bool Write(const DSGSample& elem);
        inline bool Read(DSG::DSGSample& elem);
        inline size_t const& Count()const;
        inline bool Full()const;
        inline bool Empty()const;
        inline void Flush();
        friend bool operator>>(DSG::DSGSample const& signal,DSG::RingBuffer& buffer){
            return buffer.Write(signal);
        }
        friend bool operator<<(DSG::DSGSample& signal,DSG::RingBuffer& buffer){
            return buffer.Read(signal);
        }
#ifdef DEBUG
        friend std::ostream& operator<<(std::ostream& os,DSG:: RingBuffer const& buffer){
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
    };
    inline bool DSG::RingBuffer::Full()const{
        return _count==this->_size;
    }
    inline bool DSG::RingBuffer::Empty()const{
        return _count==0;
    }
    inline void DSG::RingBuffer::Flush(){
        _write.store(0,std::memory_order_relaxed);
        _read.store(0,std::memory_order_relaxed);
        _count=0;
    }
    inline bool DSG::RingBuffer::Write(const DSGSample& elem){
        if (!Full()) {
            write = _write.load(std::memory_order_acquire);
            _write.store(next(write),std::memory_order_release);
            this->_buffer[write] = elem;
            ++_count;
            return true;
        }else return false;
    }
    inline bool DSG::RingBuffer::Read(DSGSample& elem){
        if (!Empty()) {
            read = _read.load(std::memory_order_acquire);
            _read.store(next(read),std::memory_order_release);
            elem = this->_buffer[read];
            --_count;
            return true;
        }else return false;
    }
    inline size_t const& DSG::RingBuffer::Count()const{
        return _count;
    }
    //note: RingBuffer implementation will force a power of 2 size to allow use of bitwise increment.
    inline size_t DSG::RingBuffer::next(size_t current){return (current+1) & MASK;}
    inline size_t DSG::RingBuffer::make_pow_2(size_t number){
        return pow(2, ceil(log(number)/log(2)));
    }
}
#endif /* defined(__DSG__RingBuffer__) */