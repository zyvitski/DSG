//
//  DSG.h
//  DSG
//
//  Created by Alexander Zywicki on 9/16/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef DSG_DSG_h
#define DSG_DSG_h

#define DSG_Short_Names // enables inlining of nested namespaces to allow shorter explicit typenames
//Example: DSG::Analog::AnalogSaw (Long Name)...DSG::AnalogSaw (Short Name)(only available with this macro enabled

#include "AudioSettings.h"
#include "SignalProcess.h"
#include "Buffer.h"
#include "RingBuffer.h"
#include "SignalGenerator.h"
#include "Sine.h"
#include "Sinc.h"
#include "Denormal.h"
#include "Math.h"
#include "Leaky.h"
#include "Blackman.h"
#include "LUT.h"
#include "DFT.h"

#include "FourierSaw.h"
#include "FourierSquare.h"
#include "FourierTriangle.h"

#include "AnalogSaw.h"
#include "AnalogSquare.h"
#include "AnalogTriangle.h"

#include "BLIT.h"
#include "BLITSaw.h"

#include "PolyBlep.h"
#include "PolyBlepSaw.h"

#include "MinBlep.h"

#include "DPWSaw.h"

#include "EPTRSaw.h"


#endif
