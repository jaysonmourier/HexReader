#include <stdio.h>
#include <time.h>
#include <assert.h>

// GLOBAL
time_t startTime;

void __attribute__((constructor)) __start() 
{
    startTime = time( NULL ); 
    fprintf(stdout, "\n\tJAYSON MOURIER\n\tHEX READER\n");
    fflush(stdout); 
};

void __attribute__((destructor)) __stop()
{
    fprintf(stdout, "\n%lld\n", time( NULL ) - startTime);
}

FILE *loadFile(const char *__restrict__ src) __attribute__((nonnull (1)));

int
main(void)
{
    fprintf(stdout, "Hex reader\n");
    return 0;
}

FILE *loadFile(const char *__restrict__ src)
{
    FILE *tmp = fopen64(src, "rb+");
    assert(tmp != NULL);
    return tmp;
}