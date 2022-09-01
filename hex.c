#include <stdio.h>

void __attribute__((constructor)) __start() { fprintf(stdout, "\n\tJAYSON MOURIER\n\tHEX READER\n"); fflush(stdout); };

int
main(void)
{
    fprintf(stdout, "Hex reader\n");
    return 0;
}