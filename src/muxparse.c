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

#include "muxparse.h"
#include <mux_pipe.h>
#include <stdio.h>


/*
  Enum for keeping track of the state our parser is in.

  IN_STATE: Parsing the input pin field.
  OUT_STATE: Parsing the output pin field.
  CHANNEL_STATE: Parsing the channel field.

*/

typedef enum {
    IN_STATE,
    OUT_STATE,
    CHANNEL_STATE,
} pipe_state_t;


/* Returns 1 for ' ', '\t', or '\n', and 0 otherwise */
static int is_whitespace(char c)
{
    switch (c) {
    case ' ':
	return 1;
    case '\t':
	return 1;
    case '\n':
	return 1;
    default:
	return 0;
    }
}


/* Returns 1 for the comment character '#', and 0 otherwise */
static int is_comment(char c)
{
    return '#' == c;
}


/* Returns 1 for the newline character '\n', and 0 otherwise *\
static int is_newline(char c)
{
    return '\n' == c;
}


/* Skip the entire line, useful when a comment is encountered */
static void skip_line(FILE *mux_file)
{
    int character = fgetc(mux_file);

    while (!is_newline(character)) {
	if (EOF == character) {
	    return;
	}

	character = fgetc(mux_file);
    }
}

/*
  Function to seek (moves the file position indicator of mux_file)
  past all whitespace / comments from the current position. Note that
  you have to start on whitespace, or a comment character '#' in order
  for this to actually move forward.
 */

static void skip_aesthetics(FILE *mux_file)
{
    int character = fgetc(mux_file);

    while (is_whitespace(character) || is_comment(character)) {
	if (is_comment(character)) {
	    skip_line(mux_file);
	}
	else if (EOF == character) {
	    return;
	}

	character = fgetc(mux_file);
    }

    /* Put the non-whitespace / comment character back */
    ungetc(character, mux_file);
}


int mux_parse_pipe(FILE *mux_file, MuxPipe *pipe)
{
    
}
