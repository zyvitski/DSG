//
//  PlotDataFile.h
//  DSG
//
//  Created by Alexander Zywicki on 12/18/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef __DSG__PlotDataFile__
#define __DSG__PlotDataFile__
#include "DSGTypes.h"
#include <string>
#include <fstream>
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace Plot{
        template<typename sample,unsigned long size>
        bool CreatePlotData(std::string const& filename,sample (&buffer)[size]){
            std::fstream file(filename+".dat",std::ios::out|std::ios::binary|std::ios::trunc);
            if (file.is_open()) {
                for (int i=0; i<size; ++i) {
                    file<<i<<"\t"<<buffer[i]<<"\n";
                }
                file.close();
            }
            return true;
        }
    }
}
#endif /* defined(__DSG__PlotDataFile__) */