//
//  MTOF.h
//  DSG
//
//  Created by Alexander Zywicki on 11/25/14.
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
#ifndef __DSG__MTOF__
#define __DSG__MTOF__
#include <math.h>
namespace DSG{
#ifdef DSG_Short_Names
    inline
#endif
    namespace MIDI{
        namespace{
#define NOTES_PER_OCTAVE 12.0
#define MTOF_FTOM_Center_Note 69.0
        }
        double   MTOF(unsigned char const& MIDI_Number);
        unsigned char FTOM(double const& Frequency);
    }
}
#endif /* defined(__DSG__MTOF__) */