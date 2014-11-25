//
//  MTOF.cpp
//  DSG
//
//  Created by Alexander Zywicki on 11/25/14.
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
#include "MTOF.h"
double DSG::MIDI::MTOF(unsigned char const& MIDI_Number){
    return 440.0 *pow(2.0, (MIDI_Number-MTOF_FTOM_Center_Note)/NOTES_PER_OCTAVE);
}
unsigned char DSG::MIDI::FTOM(double const& Frequency){
    return((log2((Frequency/440.0)))*NOTES_PER_OCTAVE)+MTOF_FTOM_Center_Note;
}