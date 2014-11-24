//
//  Filter.h
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
#ifndef __DSG__Filter__
#define __DSG__Filter__
#include "SignalProcess.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //!\brief DSG::Filter - Filters
    namespace Filter{
        //!\brief DSG::Filter::FilterBase - Filter Base Class, implements interface for cutoff frequency
        class FilterBase:public DSG::SignalProcess{
        public:
            FilterBase();
            virtual ~FilterBase();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
            virtual inline bool Cutoff(DSG::DSGFrequency const& cutoff);
        protected:
            DSG::DSGSample _temp;
            unsigned long count;
        };
        inline bool DSG::Filter::FilterBase::Perform(DSG::DSGSample& signal){
            return true;
        }
        inline bool DSG::Filter::FilterBase::Perform(DSG::RingBuffer& signal){
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
        inline bool DSG::Filter::FilterBase::Cutoff(DSG::DSGFrequency const& cutoff){
            return false;
        }
    }
}
#endif /* defined(__DSG__Filter__) */