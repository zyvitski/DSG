//
//  DCBlocker.h
//  DSG
//
//  Created by Alexander Zywicki on 10/13/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__DCBlocker__
#define __DSG__DCBlocker__
#include "SignalProcess.h"
namespace DSG {
#ifdef DSG_Short_Names
    inline
#endif
    namespace Filter{
        class DCBlocker {
        public:
            DCBlocker();
            virtual ~DCBlocker();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
        protected:
            unsigned long count;
            DSG::DSGSample _temp;
            DSG::DSGSample xm1;
            DSG::DSGSample ym1;
            DSG::DSGSample x;
            float _a;
        };
        inline bool DSG::Filter::DCBlocker::Perform(DSG::DSGSample& signal){
            x = signal;
            signal= x - xm1+ (_a * ym1);
            xm1 = x;
            ym1=signal;
            return true;
        }
        inline bool DSG::Filter::DCBlocker::Perform(DSG::RingBuffer& signal){
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
    }
}
#endif /* defined(__DSG__DCBlocker__) */