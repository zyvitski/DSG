//
//  Leaky.h
//  DSG
//
//  Created by Alexander Zywicki on 10/27/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
/*
 This file is part of the Digital Signal Generation Project or “DSG”.

 DSG is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 DSG is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with DSG.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __DSG__Leaky__
#define __DSG__Leaky__
#include "Filter.h"
#include "PI.h"
namespace DSG {
#ifdef DSG_Short_Names
    inline
#endif
    namespace Filter{
        //!\brief DSG::Filter::LeakyIntegrator - Leaky integrator 
        class LeakyIntegrator:public DSG::Filter::FilterBase{
        public:
            LeakyIntegrator();
            LeakyIntegrator(DSG::DSGFrequency const& cutoff);
            virtual ~LeakyIntegrator();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
            virtual inline bool Cutoff(DSG::DSGFrequency const& cutoff);
        protected:
            double x1,y1,a,b;
            double y;
        };
        inline bool DSG::Filter::LeakyIntegrator::Perform(DSG::DSGSample& signal){
            y = b * (signal + x1) - a * y1;
            x1=signal;
            y1=y;
            signal=y;
            return true;
        }
        inline bool DSG::Filter::LeakyIntegrator::Perform(DSG::RingBuffer& signal){
            if (!signal.Empty()) {
                count = signal.Count();
                while (count-- > 0) {
                    if(signal.Read(_temp)){
                        if (Perform(_temp)) {
                            signal.Write(_temp);
                        }else return false;
                    }else return false;
                }return true;
            }else return false;
        }
        inline bool DSG::Filter::LeakyIntegrator::Cutoff(DSG::DSGFrequency const& cutoff){
            double Omega;
            x1 = y1 = 0.0;
            Omega = atan(PI * cutoff);
            a = -(1.0 - Omega) / (1.0 + Omega);
            b = (1.0 - b) / 2.0;
            return true;
        }
    }
}
#endif /* defined(__DSG__Leaky__) */