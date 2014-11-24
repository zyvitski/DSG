//
//  DSG.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
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
#ifndef DSG_DSG_h
#define DSG_DSG_h
#define DSG_Short_Names // enables inlining of nested namespaces to allow shorter explicit typenames
//Example: DSG::Analog::AnalogSaw (Long Name)...DSG::AnalogSaw (Short Name)(only available with this macro enabled
//!\brief DSG - A Collection of tools for Digital Signal Generation
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

#endif