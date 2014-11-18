//
//  Random.h
//  DSG
//
//  Created by Alexander Zywicki on 10/28/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef DSG_Random_h
#define DSG_Random_h
#include "DSGTypes.h"
#include <random>
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    //!\brief DSG::Noise - Noise Generators
    namespace Noise{
        namespace{
            template<typename decimal>
            class random_helper{
            public:
                random_helper(){
                    srand(static_cast<unsigned>(time(NULL)));
                }
                inline decimal next(){
                    return static_cast<decimal>(rand()/max);
                }
            protected:
                const decimal max = static_cast<decimal>(RAND_MAX);
            };
        }
        //!\brief DSG::Noise::Random - Random Number Function
        template<typename decimal = DSG::DSGSample>
        inline decimal Random(decimal=0.0){
            static DSG::Noise::random_helper<decimal> _rand{};
            return _rand.next();
        }
    }
}
#endif