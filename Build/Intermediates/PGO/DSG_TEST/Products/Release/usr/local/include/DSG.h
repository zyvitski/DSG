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

#include "FourierSaw.h"
#include "FourierSquare.h"
#include "FourierTriangle.h"

#include "AnalogSaw.h"
#include "AnalogSquare.h"
#include "AnalogTriangle.h"

#include "BLIT.h"


#endif
