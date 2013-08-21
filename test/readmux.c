#include <stdio.h>
#include <muxpipe.h>
#include <muxparse.h>


/* Print the usage information */
void usage(char *prog_name)
{
    printf("Usage: %s <filename>\n", prog_name);
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
	printf("Invalid number of arguments.\n");
	usage(argv[0]);
	return 1;
    }

    FILE *mux_file = fopen(argv[1], "r");
    MuxPipe pipe;

    int result = mux_pipe_parse(mux_file, &pipe);

    while (0 == result) {
	printf("Input %d ", pipe.in_pin);
	printf("to output %d ", pipe.out_pin);
	printf("on channel %d!\n", pipe.channel);

	result = mux_pipe_parse(mux_file, &pipe);
    }

    if (2 == result) {
	fprintf(stderr, "Parse error!\n");
	return 2;
    }

    return 0;
}
