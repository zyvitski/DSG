//
//  DCBlocker.h
//  DSG
//
//  Created by Alexander Zywicki on 10/13/14.
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
#ifndef __DSG__DCBlocker__
#define __DSG__DCBlocker__
#include "Filter.h"
namespace DSG {
#ifdef DSG_Short_Names
    inline
#endif
    namespace Filter{
        //!\brief DSG::Filter::DCBlocker - DC blocking filter
        class DCBlocker:public DSG::Filter::FilterBase {
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
            DSG::DSGSample _a;
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