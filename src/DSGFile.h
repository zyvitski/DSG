//
//  File.h
//  DSG
//
//  Created by Alexander Zywicki on 12/19/14.
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
#ifndef __DSG__File__
#define __DSG__File__
#include <stdio.h>
#include <string>
#include <fstream>
#include "RingBuffer.h"
namespace DSG{
    namespace File{
        typedef enum File_Types{
            PlotFile = 0
        }File_Types;
        template<unsigned type> bool Write(std::string const& filename){
            return false;
        }
        template<unsigned type> bool Write(std::string const& filename,DSG::RingBuffer& signal){
            return false;
        }
        template<> bool Write<PlotFile>(std::string const& filename,DSG::RingBuffer& signal){
            std::fstream file(filename+".dat",std::ios::out|std::ios::binary|std::ios::trunc);
            DSG::DSGSample sample=0;
            if (file.is_open()) {
                for (int i=0; i<signal.Count(); ++i) {
                    if (signal.Read(sample)) {
                        file<<i<<"\t"<<sample<<"\n";
                        signal.Write(sample);
                    }else{
                        return false;
                    }
                }file.close();
            }return true;
        }
    }
}
#endif /* defined(__DSG__File__) */