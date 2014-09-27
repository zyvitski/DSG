//
//  PolyBlepSaw.h
//  DSG
//
//  Created by Alexander Zywicki on 9/22/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __DSG__PolyBlepSaw__
#define __DSG__PolyBlepSaw__

#include "PolyBlep.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Blep{
        class PolyBlepSaw : public DSG::Blep::PolyBlep{
        public:
            PolyBlepSaw();
            PolyBlepSaw(DSG::DSGFrequency const& frequency,DSG::DSGPhase const& offset);
            virtual ~PolyBlepSaw();
            virtual inline bool Perform(DSG::DSGSample& signal);
            virtual inline bool Perform(DSG::RingBuffer& signal);
        protected:
            DSG::DSGSample _stor;
        };
        inline bool DSG::Blep::PolyBlepSaw::Perform(DSG::DSGSample& signal){
#warning Untested DSG::Blep::PolyBlepSaw::Perform()
            //needs further evaluation. Still Strongly aliased
            _stor=_phasor;
            _stor=1.0-_stor;
            _stor-=0.5;
            _stor*=2.0;
            _stor-=poly_blep(_phasor);

            signal=_stor;
            step();
            return true;
        }
        inline bool DSG::Blep::PolyBlepSaw::Perform(DSG::RingBuffer& signal){
            signal.Flush();
            while (!signal.Full()) {
                if (Perform(_storage)) {
                    if(signal.Write(_storage)){
                    }else return false;
                }else return false;
            }return true;
        }
    }
}

#endif /* defined(__DSG__PolyBlepSaw__) */
