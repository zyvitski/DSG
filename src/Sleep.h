//
//  Sleep.h
//  DSG
//
//  Created by Alexander Zywicki on 10/5/14.
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
#ifndef __DSG__Sleep__
#define __DSG__Sleep__
#include <chrono>
#include <thread>
namespace DSG{
    //!\brief DSG::Sleep - Millisecond Sleep Function
    template<typename integer>
    void Sleep(integer const& milliseconds){
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
}
#endif /* defined(__DSG__Sleep__) */