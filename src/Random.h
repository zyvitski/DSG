//
//  Random.h
//  DSG
//
//  Created by Alexander Zywicki on 10/28/14.
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