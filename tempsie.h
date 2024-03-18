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
extern int tempsie_get_temp_filename(const char *prefix, char *buffer,
                                     unsigned buffer_size);
#ifdef __cplusplus
}
#endif

#ifdef TEMPSIE_IMPLEMENTATION
#ifndef TEMPSIE_ERROR
#define TEMPSIE_ERROR(x)
#endif

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static void tempsie__error(const char *msg) {
  LPSTR buf = NULL;
  FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
                    FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                buf, 0, NULL);
  TEMPSIE_ERROR((const char *)buf);
  LocalFree(buf);
}

int tempsie_get_temp_filename(const char *prefix, char *buffer,
                               unsigned buffer_size) {
  char path[MAX_PATH] = {0};
  int ret = GetTempPath(sizeof(path), path);
  if (ret > sizeof(path) || ret == 0) {
    tempsie__error("GetTempPath");
    return 1;
  }
  char file[MAX_PATH] = {0};
  if (0 == GetTempFileName(path, prefix, 0, file)) {
    tempsie__error("GetTempFileName");
    return 1;
  }
  strcpy_s(buffer, buffer_size, file);
  return 0;
}
#else // !_WIN32
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int tempsie_get_temp_filename(const char *prefix, char *buffer,
                              unsigned buffer_size) {
  char buf[1024] = P_tmpdir;
  strcat(buf, "/");
  strcat(buf, prefix);
  strcat(buf, "-XXXXXX");
  int fd = mkstemp(buf);
  if (fd == -1) {
    TEMPSIE_ERROR("Failed to get a unique temporary file name");
    return 1;
  }
  strncpy(buffer, buf, buffer_size);
  close(fd);
  return 0;
}
#endif // _WIN32

#endif // TEMPSIE_IMPLEMENTATION

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
