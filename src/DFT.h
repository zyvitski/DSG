//
//  DFT.h
//  DSG
//
//  Created by Alexander Zywicki on 9/24/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef DSG_DFT_h
#define DSG_DFT_h
#include<complex>
#include "PI.h"
#include <math.h>
namespace DSG {
    template<typename T,unsigned long size>
    void DFT(std::complex<T> (&time)[size],std::complex<T> (&freq)[size]){
        T p;
        std::complex<T> s;
        int k,i;
        for (k=0; k<size; ++k) {
            freq[k]=0.0;
        }
        for (k=0; k<size; ++k) {
            for (i=0; i<size; ++i) {
                p = (TWOPI * (T)(k*i))/size;
                s.real((T)cos(p));
                s.imag((T)-sin(p));
                freq[k].real(freq[k].real()+(time[i].real()*s.real())-(time[i].imag()*s.imag()));
                freq[k].imag(freq[k].imag()+(time[i].real()*s.imag())+(time[i].imag()*s.real()));
            }
        }
    }
    template<typename T,unsigned long size>
    void IDFT(std::complex<T> (&time)[size],std::complex<T> (&freq)[size]){
        T p;
        std::complex<T> s;
        int k,i;
        for (k=0; k<size; ++k) {
            time[k]=0.0;
        }
        for (k=0; k<size; ++k) {
            for (i=0; i<size; ++i) {
                p = (TWOPI * (T)(k*i))/size;
                s.real((T)cos(p));
                s.imag((T)-sin(p));
                time[k].real((freq[i].real() * s.real()) + (freq[i].imag() * s.imag()));
                time[k].imag((freq[i].imag() * s.imag()) - (freq[i].imag() * s.real()));
            }
            time[k]/=size;
        }
        
    }
    template<typename T,unsigned long  size>
    void RealCepstrum(T (&signal)[size],T (&realCepstrum)[size]){
        std::complex<T> time[size];
        std::complex<T> freq[size];
        int i;
        for (i=0; i<size; ++i) {
            time[i].real(signal[i]);
            time[i].imag(0.0);
        }
        DFT<T, size>(time, freq);
        for (i=0; i<size; ++i) {
            freq[i].real(log(abs(freq[i])));
            freq[i].imag(0.0);
        }
        IDFT<T, size>(time, freq);
        for (i=0; i<size; i++) {
            realCepstrum[i]=time[i].real();
        }
    }
}
#endif