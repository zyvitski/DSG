//
//  FourierSeries.h
//  DSG
//
//  Created by Alexander Zywicki on 11/18/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__FourierSeries__
#define __DSG__FourierSeries__
#include "SignalGenerator.h"
#include <vector>
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Fourier{
        class Harmonic{
        public:
            Harmonic();
            Harmonic(DSG::DSGSample const& ratio,DSG::DSGSample const& amplitude);
            virtual ~Harmonic();
            DSG::DSGSample const& Ratio()const;
            DSG::DSGSample const& Ratio(DSG::DSGSample const& value);
            DSG::DSGSample const& Amplitude()const;
            DSG::DSGSample const& Amplitude(DSG::DSGSample const& value);
        protected:
            DSG::DSGSample _ratio;
            DSG::DSGSample _amplitude;
        };
        class FourierSeriesGenerator: public DSG::SignalGenerator{
        public:
            typedef std::vector<Harmonic> FourierSeries;
            FourierSeriesGenerator();
            FourierSeriesGenerator(DSG::DSGFrequency const& frequency, DSG::DSGPhase const& offset);
            virtual ~FourierSeriesGenerator();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
            inline void Series(FourierSeries const& series);
            inline FourierSeries& Series();
        protected:
            FourierSeries _series;
            DSG::DSGSample value;
        };
        inline bool DSG::Fourier::FourierSeriesGenerator::Perform(DSG::DSGSample& signal){
            value = _phasor;
            signal=0;
            for (auto i = _series.begin(); i!=_series.end(); ++i) {
                signal += DSG::Sin(_phasor * i->Ratio())*i->Amplitude();
            }
            step();
            return true;
        }
        inline bool DSG::Fourier::FourierSeriesGenerator::Perform(DSG::RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_storage)) {
                    if(signal.Write(_storage)){
                    }else return false;
                }else return false;
            }return true;
        }
        inline void DSG::Fourier::FourierSeriesGenerator::Series(DSG::Fourier::FourierSeriesGenerator::FourierSeries const& series){
            _series = series;
        }
        inline DSG::Fourier::FourierSeriesGenerator::FourierSeries& DSG::Fourier::FourierSeriesGenerator::Series(){
            return _series;
        }
    }
}
#endif /* defined(__DSG__FourierSeries__) */