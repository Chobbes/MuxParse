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

#include <stdio.h>
#include <mux_pipe.h>
#include <muxparse.h>


/* Print the usage information */
void usage(char *prog_name)
{
    printf("Usage: %s <filename>\n", prog_name);
}


/*
  This is a simple little example program that uses the MuxParse
  library to print a ".mux" file in a somewhat "human readable"
  format.

 */

int main(int argc, char *argv[])
{
    if (argc != 2) {
	printf("Invalid number of arguments.\n");
	usage(argv[0]);
	return 1;
    }

    FILE *mux_file = fopen(argv[1], "r");

    if (NULL == mux_file) {
	fprintf(stderr, "Could not read file: %s\n", argv[1]);
	return 2;
    }

    MuxPipe pipe;

    int result = mux_parse_pipe(mux_file, &pipe);

    while (0 == result) {
	printf("Input %d ", pipe.in_pin);
	printf("to output %d ", pipe.out_pin);
	printf("on channel %d!\n", pipe.channel);

	result = mux_parse_pipe(mux_file, &pipe);
    }

    if (2 == result) {
	fprintf(stderr, "Parse error!\n");
	return 2;
    }

    return 0;
}
