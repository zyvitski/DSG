//
//  File.h
//  DSG
//
//  Created by Alexander Zywicki on 12/19/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
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