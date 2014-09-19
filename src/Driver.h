//
//  Driver.h
//  Waveform
//
//  Created by Alexander Zywicki on 8/25/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __Waveform__Driver__
#define __Waveform__Driver__

#ifdef DEBUG
#include <iostream>
#endif
#include <portaudio.h>
#include "DSG.h"

int DriverInit(void * data);
int DriverExit();
int Callback( const void *input,
             void *output,
             unsigned long frameCount,
             const PaStreamCallbackTimeInfo* timeInfo,
             PaStreamCallbackFlags statusFlags,
             void *userData );
#endif /* defined(__Waveform__Driver__) */