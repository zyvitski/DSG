//
//  SoundFile.h
//  DSG_SoundFIle
//
//  Created by Alexander Zywicki on 10/2/14.
//  Copyright (c) 2014 Alexander Zywicki. All rights reserved.
//

#ifndef __DSG_SoundFIle__SoundFile__
#define __DSG_SoundFIle__SoundFile__
#include <fstream>
namespace DSG{
    namespace SoundFile{
        template<typename sample>
        class WavFile{
        public:
            WavFile(const char* outFile, sample* buf, size_t bufSize, int sampleRate, short channels)
            {
                _file.open(outFile, std::ios::binary);                // Open file _file at "outFile" location
                if (_file.is_open()) {
                    /* Header */
                    _file.write("RIFF", 4);                                        // sGroupID (RIFF = Resource Interchange File Format)
                    write<int>(_file, 36 + bufSize);                               // dwFileLength
                    _file.write("WAVE", 4);                                        // sRiffType

                    /* Format Chunk */
                    _file.write("fmt ", 4);                                        // sGroupID (fmt = format)
                    write<int>(_file, 16);                                         // Chunk size (of Format Chunk)
                    write<short>(_file, 3);                                        // Format (1 = PCM)
                    write<short>(_file, channels);                                 // Channels
                    write<int>(_file, sampleRate);                                 // Sample Rate
                    write<int>(_file, sampleRate * channels * sizeof(sample)); // Byterate
                    write<short>(_file, channels * sizeof(sample));            // Frame size aka Block align
                    write<short>(_file, 8 * sizeof(sample));                   // Bits per sample

                    /* Data Chunk */
                    _file.write("data", 4);                                        // sGroupID (data)
                    _file.write((const char*)&bufSize, 4);                         // Chunk size (of Data, and thus of bufferSize)
                    _file.write((const char*)buf, bufSize);                        // The samples DATA!!!
                    _file.close();
                }
            }
            ~WavFile(){
                if (_file.is_open()) {
                    _file.close();
                }
            }
        protected:
            template <typename T>
            void write(std::ofstream& stream, const T& t) {
                stream.write((const char*)&t, sizeof(T));
            }
            std::ofstream _file;
        };
    }
}

#endif /* defined(__DSG_SoundFIle__SoundFile__) */
