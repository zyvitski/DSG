//
//  MinBlep.h
//  DSG
//
//  Created by Alexander Zywicki on 9/23/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__MinBlep__
#define __DSG__MinBlep__
#include "DFT.h"
#include "Sinc.h"
#include "Blackman.h"
#include "SignalGenerator.h"
#include "PI.h"
namespace DSG {
    namespace Blep{        
        template<typename T,unsigned long  size>
        void MinimumPhase(T (&realCepstrum)[size],T (&minimumPhase)[size]){
            int i,nd2;
            nd2 = size/2;
            std::complex<T> time[size];
            std::complex<T> freq[size];
            if ((size % 2)==1) {
                time[0].real(realCepstrum[0]);
                for (i=1; i<nd2; ++i) {
                    time[i].real(2.0 * realCepstrum[i]);
                    for (i=nd2; i<size; ++i) {
                        time[i].real(0.0);
                    }
                }
            }else{
                time[0].real(realCepstrum[0]);
                for (i=1; i<nd2; ++i) {
                    time[i].real(2.0 * realCepstrum[i]);
                    time[nd2].real(realCepstrum[nd2]);
                    for (i=nd2+1; i<size; ++i) {
                        time[i].real(0.0);
                    }
                }
            }
            for (i=0; i<size; ++i) {
                time[i].imag(0.0);
            }
            DFT<T, size>(time, freq);
            for (i=0; i<size; ++i) {
                freq[i]=exp(freq[i]);
            }
            IDFT<T, size>(time, freq);
            for (i=0; i<size; ++i) {
                minimumPhase[i] = time[i].real();
            }
        }
        template<typename T,unsigned long zeroCrossings,unsigned long oversampling, unsigned long n = 2.0 * zeroCrossings * oversampling>
        void GenerateMinBlep(T (&minBlep)[n]){
            T buffer1[n];
            T buffer2[n];
            int i;
            T r,a,b;
            a = (float)-zeroCrossings;
            b = (float)zeroCrossings;
            for(i = 0; i < n; ++i)
            {
                r = ((float)i) / ((float)(n - 1));
                buffer1[i] = DSG::Sinc((a + (r * (b - a)))/TWOPI);
            }
            for (i=0; i<n; ++i) {
                buffer2[i] = DSG::Blackman(i/(float)n);
            }
            for (i=0; i<n; ++i) {
                buffer1[i]*=buffer2[i];
            }
            RealCepstrum(buffer1,buffer2);
            MinimumPhase(buffer2,buffer1);
            a=0.0;
            for (i=0; i<n; ++i) {
                a+=buffer1[i];
                minBlep[i] = a;
            }
            a=0.0;
            //normalize to -1.0 - 1.0
            for (i=0; i<n; ++i) {
                if (DSG::Abs( minBlep[i])>a) {
                    a=DSG::Abs(minBlep[i]);//find highest value in table
                }
            }
            a=1.0/a;
            for (i=0; i<n; ++i) {
                minBlep[i]*=a;//divide table by highest value
            }
        }
    }
}
#endif /* defined(__DSG__MinBlep__) */