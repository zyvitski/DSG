//
//  PolyBlep.h
//  DSG
//
//  Created by Alexander Zywicki on 9/22/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __DSG__PolyBlep__
#define __DSG__PolyBlep__

#include "SignalGenerator.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Blep{
        class PolyBlep : public DSG::SignalGenerator{
        public:
            PolyBlep();
            PolyBlep(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~PolyBlep();
        protected:
            inline double poly_blep(double t);
        };
        inline double DSG::Blep::PolyBlep::poly_blep(double t){
            if (t<2.0*_dt) {
                t/=_dt;
                return t+t -t*t - 1.0;
            }else if (t>1.0-(2.0*_dt)){
                t = (t-1.0)/-_dt;
                return t*t + t+t +1.0;
            }else{
                return 0.0;
            }
        }
    }
}

#endif /* defined(__DSG__PolyBlep__) */
