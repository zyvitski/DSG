//
//  Pink.h
//  DSG
//
//  Created by Alexander Zywicki on 10/8/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef DSG_Pink_h
#define DSG_Pink_h
#include "Gaussian.h"
#include "DCBlocker.h"
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Noise{
        //!\brief DSG::Noise::Pink - Pink Noise Generator Function
        template<typename decimal=DSG::DSGSample>
        decimal Pink(decimal=0.0){
            //routine: Get white or gaussian, filter, return
            static decimal b0,b1,b2,b3,b4,b5,b6;
            static decimal normalizer=1;//variable used to actively normalize the output
            static DSG::DCBlocker _block;
            decimal white = DSG::Noise::Gaussian();
            decimal pink;
            //pinking filter
            b0 = 0.99886 * b0 + white * 0.0555179;
            b1 = 0.99332 * b1 + white * 0.0750759;
            b2 = 0.96900 * b2 + white * 0.1538520;
            b3 = 0.86650 * b3 + white * 0.3104856;
            b4 = 0.55000 * b4 + white * 0.5329522;
            b5 = -0.7616 * b5 - white * 0.0168980;
            pink = b0 + b1 + b2 + b3 + b4 + b5 + b6 + white * 0.5362;
            b6 = white * 0.115926;
            if (DSG::Abs(pink)>normalizer) {
                //store highest output
                normalizer=DSG::Abs(pink);
            }
            pink/=normalizer;
            _block.Perform(pink);
            return pink;
        }
    }
}
#endif