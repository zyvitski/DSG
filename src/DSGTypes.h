//
//  DSGTypes.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
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
#ifndef DSG_DSGTypes_h
#define DSG_DSGTypes_h
namespace DSG {
    //!\typedef DSG::DSGFrequency - Type for representing a frequency value
    //!\brief DSG::DSGFrequency - Type for representing a frequency value
    typedef float DSGFrequency;
    //!\typedef DSG::DSGPhase - Type for representing a phase value
    //!\brief DSG::DSGPhase - Type for representing a phase value
    typedef float DSGPhase;
    //!\typedef DSG::DSGSample - Type for representing an audio sample
    //!\brief DSG::DSGSample - Type for representing an audio sample
    typedef float DSGSample;
}
#endif