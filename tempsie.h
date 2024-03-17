// tempsie.h
// single-file C wrapper for temp file names by Eduardo Costa
//
// LICENSE - See end of file
//
// to create implementation, add
// #define TEMPSIE_IMPLEMENTATION
// in one C/CPP file that includes this file
//
// use this in the file defining TEMPSIE_IMPLEMENTATION:
// #define TEMPSIE_ERROR(x) log_error(x)
// if you want to log errors
//

#ifdef __cplusplus
extern "C" {
#endif
extern bool tempsie_get_temp_filename(char *buffer, unsigned buffer_size);
#ifdef __cplusplus
}
#endif

#ifdef TEMPSIE_IMPLEMENTATION
#ifndef TEMPSIE_ERROR
#define TEMPSIE_ERROR(x)
#endif

bool tempsie_get_temp_filename(char *buffer, unsigned buffer_size) {
  TEMPSIE_ERROR("TBD");
  return false;
}
#endif

// MIT License
//
// Copyright (c) 2024 Eduardo Costa
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
