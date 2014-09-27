//
//  Driver.cpp
//  Waveform
//
//  Created by Alexander Zywicki on 8/25/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//
#include "Driver.h"
PaStream* stream;
#define BufferSize 512
DSG:: RingBuffer _buffer(BufferSize);
int DriverInit(void * data){
    PaError err=0;
    
    err=Pa_Initialize();
    if (err!=paNoError) {
#ifdef DEBUG
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
#endif
        return 1;
    }
    err = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32,DSG::SampleRate(),BufferSize, Callback, data);
    if (err!=paNoError) {
#ifdef DEBUG
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
#endif
        return 1;
    }
    err = Pa_StartStream(stream);
    if (err!=paNoError) {
#ifdef DEBUG
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
#endif
        return 1;
    }
    return 0;
}
int DriverExit(){
    PaError err=0;
    err = Pa_StopStream(stream);
    if (err!=paNoError) {
#ifdef DEBUG
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
#endif
        return 1;
    }
    err = Pa_CloseStream( stream );
    if( err != paNoError ){
#ifdef DEBUG
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
#endif
    }
    err = Pa_Terminate();
    if( err != paNoError ){
#ifdef DEBUG
        printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
#endif
    }
    return 0;
}

int Callback( const void *input,
             void *output,
             unsigned long frameCount,
             const PaStreamCallbackTimeInfo* timeInfo,
             PaStreamCallbackFlags statusFlags,
             void *userData) {
    DSG::DSGSample* _out = (DSG::DSGSample*)output;
    DSG:: DSGSample _sample;
    DSG::SignalGenerator* _osc = (DSG::SignalGenerator*)userData;
    if (_out!=nullptr) {
        _buffer.Flush();
        _osc->Perform(_buffer);
        for (int i=0; i<frameCount; ++i) {
            _buffer.Read(_sample);
            *_out++ = _sample;
            *_out++ = _sample;
        }
    }
    return 0;
}