/* Copyright (C) 2013 Calvin Beck

  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this software and associated documentation files
  (the "Software"), to deal in the Software without restriction,
  including without limitation the rights to use, copy, modify, merge,
  publish, distribute, sublicense, and/or sell copies of the Software,
  and to permit persons to whom the Software is furnished to do so,
  subject to the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

*/

#ifndef MUXPARSE_H
#define MUXPARSE_H

#include <stdio.h>
#include <mux_pipe.h>  /* Need the MuxPipe structure! */


/*
  Arguments:
      mux_file: File pointer for the .mux file that we are reading.

      pipe: Pointer to a pipe structure to store results in.

  Returns 0 on success, 1 when the end of the file has been reached
  (and thus no more pipes to read at all) and 2 if there was a parse
  error.

  Note that the mux_file should have just been opened before calling
  this the first time without manipulating the file position
  indicator, and only this function should be used to parse the entire
  file. It relies upon the file position indicator staying put! Moving
  it manually may cause interesting results.

 */

int mux_parse_pipe(FILE *mux_file, MuxPipe *pipe);

#endif
