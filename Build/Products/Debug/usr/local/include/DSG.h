//
//  DSG.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#ifndef DSG_DSG_h
#define DSG_DSG_h
/*!\mainpage DSG - A Collection Of Tools For Digital Signal Generation
 *\section intro_sec Intoduction
 The Digital Signal Generation Project or DSG is a collection of tools used for the generation of digital signals, more specifically the generation of band-limited waveforms.
 *\subsection Scope
 Though DSG has a focus on Bandlimited Waveform Generation it is not limited to it. 
 DSG defines a signal processing interface that is compatable with any form fo audio based signal processing work.
 The interface defined in DSG::SignalProcess is the base interface for signal processing in DSG, It is further expanded by DSG::SignalGenerator which adds functionality geared towards waveform generation.
 See the doumentation for each for their specifics.
 *\section License
    DSG is released under the Lesser GNU Public License (LGPL).
  
 A copy of the LGPL and the GNU Public License should be included with the distrobution in the files: COPYING (GPL), and COPYING.LESSER (LGPL)
Additionally each source file should contain a copy of the license notice which reads as follows:
 \copyright
 

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



#define DSG_Short_Names // enables inlining of nested namespaces to allow shorter explicit typenames
//Example: DSG::Analog::AnalogSaw (Long Name)...DSG::AnalogSaw (Short Name)(only available with this macro enabled
//!\brief DSG - A Collection of tools for Digital Signal Generation
//!\copyright Lesser GNU Public License
//!\todo Increase documentation level. Add documentation for every variable, parameter...
//!\todo Implement Blep Based Algorithms
namespace DSG {}
#include "AudioSettings.h"
#include "SignalProcess.h"
#include "Buffer.h"
#include "RingBuffer.h"
#include "SignalGenerator.h"
#include "Sine.h"
#include "Sinc.h"
#include "Denormal.h"
#include "Math.h"
#include "Blackman.h"
#include "LUT.h"
#include "Window.h"
#include "Bounds.h"
#include "GenericGenerator.h"
#include "Delay.h"
#include "Sleep.h"
#include "BufferConversion.h"
#include "FourierSeries.h"
#include "FourierSaw.h"
#include "FourierSquare.h"
#include "FourierTriangle.h"
#include "AnalogSaw.h"
#include "AnalogSquare.h"
#include "AnalogTriangle.h"
#include "BLIT.h"
#include "BLITSaw.h"
#include "DSF.h"
#include "DPW.h"
#include "DPWSaw.h"
#include "EPTRSaw.h"
#include "Noise.h"
#include "DCBlocker.h"
#include "Filter.h"
#include "Leaky.h"
#include "MTOF.h"
#include "PlotDataFile.h"
#endif