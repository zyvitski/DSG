//
//  Filter.h
//  DSG
//
//  Created by Alexander Zywicki on 10/27/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__Filter__
#define __DSG__Filter__
#include "SignalProcess.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Filter{
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