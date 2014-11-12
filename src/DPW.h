//
//  DPW.h
//  DSG
//
//  Created by Alexander Zywicki on 11/11/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef DSG_DPW_h
#define DSG_DPW_h
#include "DSGTypes.h"
#include "DSGMath.h"
#include "SignalGenerator.h"
#include "Bounds.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace DPW{
        template<unsigned order>
        inline DSG::DSGSample DPW_Polynomial(DSG::DSGSample const& value){
            DSG::StaticAssertBounds<1,6>(order);//must be 1-6 order
            return value;
        }
        template<>
        inline DSG::DSGSample DPW_Polynomial<1>(DSG::DSGSample const& value){
            return value;
        }
        template<>
        inline DSG::DSGSample DPW_Polynomial<2>(DSG::DSGSample const& value){
            return DSG::Pow<2>(value);
        }
        template<>
        inline DSG::DSGSample DPW_Polynomial<3>(DSG::DSGSample const& value){
            return DSG::Pow<3>(value)-value;
        }
        template<>
        inline DSG::DSGSample DPW_Polynomial<4>(DSG::DSGSample const& value){
            return DSG::Pow<2>(value) * (DSG::Pow<2>(value) - 2.0);
        }
        template<>
        inline DSG::DSGSample DPW_Polynomial<5>(DSG::DSGSample const& value){
            return DSG::Pow<5>(value) - DSG::Pow<3>(value) * 10.0/3.0 + value * 7.0/3.0;
        }
        template<>
        inline DSG::DSGSample DPW_Polynomial<6>(DSG::DSGSample const& value){
            return DSG::Pow<6>(value) - 5.0 * DSG::Pow<4>(value) + 7.0 * DPW_Polynomial<2>(value);
        }
#warning DSG::DPW_Differentiator<order> untested
        //differentiators
        template<unsigned order>
        class DPW_Differentiator{
        public:
            DPW_Differentiator(){
                DSG::StaticAssertBounds<1, 6>(order);//order must be 1-6
            }
        };

        template<>
        class DPW_Differentiator<1>{
        public:
            inline DSG::DSGSample operator()(DSG::DSGSample const& signal,DSG::DSGSample const& dt){
                return signal;
            }
        };
        template<>
        class DPW_Differentiator<2>{
        public:
            inline DSG::DSGSample operator()(DSG::DSGSample const& signal,DSG::DSGSample const& dt){
                output = (signal - _delay)/(4.0 * dt);
                _delay = signal;
                return output;
            }
        protected:
            DSG::DSGSample output;
            DSG::DSGSample _delay;
        };
        template<>
        class DPW_Differentiator<3>{
        public:
            inline DSG::DSGSample operator()(DSG::DSGSample const& signal,DSG::DSGSample const& dt){
                output  = (signal - _delay[0]);
                output -= (_delay[0] - _delay[1]);
                output /= (24.*DSG::Pow<2>(dt));
                _delay[1]=_delay[0];
                _delay[0]=signal;
                return output;
            }
        protected:
            DSG::DSGSample output;
            DSG::DSGSample _delay[2];
        };
        template<>
        class DPW_Differentiator<4>{
        public:
            inline DSG::DSGSample operator()(DSG::DSGSample const& signal,DSG::DSGSample const& dt){
                output  = (signal - _delay[0]);
                output -= (_delay[0] - _delay[1]);
                output -= (_delay[1] - _delay[2]);
                output /= 144*DSG::Pow<3>(dt);
                _delay[2]=_delay[1];
                _delay[1]=_delay[0];
                _delay[0]=signal;
                return output;
            }
        protected:
            DSG::DSGSample output;
            DSG::DSGSample _delay[3];
        };

        template<>
        class DPW_Differentiator<5>{
        public:
            inline DSG::DSGSample operator()(DSG::DSGSample const& signal,DSG::DSGSample const& dt){
                output  = (signal - _delay[0]);
                output -= (_delay[0] - _delay[1]);
                output -= (_delay[1] - _delay[2]);
                output -= (_delay[2] - _delay[3]);
                output /= 960*DSG::Pow<4>(dt);
                _delay[3]=_delay[2];
                _delay[2]=_delay[1];
                _delay[1]=_delay[0];
                _delay[0]=signal;
                return output;
            }
        protected:
            DSG::DSGSample output;
            DSG::DSGSample _delay[4];
        };

        template<>
        class DPW_Differentiator<6>{
        public:
            inline DSG::DSGSample operator()(DSG::DSGSample const& signal,DSG::DSGSample const& dt){
                output  = (signal - _delay[0]);
                output -= (_delay[0] - _delay[1]);
                output -= (_delay[1] - _delay[2]);
                output -= (_delay[2] - _delay[3]);
                output -= (_delay[3] - _delay[4]);
                output /= 7200*DSG::Pow<5>(dt);
                _delay[4]=_delay[3];
                _delay[3]=_delay[2];
                _delay[2]=_delay[1];
                _delay[1]=_delay[0];
                _delay[0]=signal;
                return output;
            }
        protected:
            DSG::DSGSample output;
            DSG::DSGSample _delay[5];
        };
    }
}
#endif