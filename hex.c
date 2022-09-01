/**
 * 
 * Jayson Mourier - 2022
 * jayson.mourier@parisnanterre.fr
 * 
 * Simple hex reader, nothing more. 
 *
*/  

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>

#define FILE_NAME "hex.c"
#define BUFFER_SIZE 10
#define NEW_LINE 10

// GLOBAL
time_t _startTime;

void __attribute__((constructor)) __start() 
{
    _startTime = time( NULL ); 
    fprintf(stdout, "\n\tJAYSON MOURIER\n\tHEX READER\n");
    fflush(stdout); 
};

void __attribute__((destructor)) __stop()
{
    fprintf(stdout, "\n%lld\n", time( NULL ) - _startTime);
    fflush(stdout);
}

/**
 * load a file from disk, lifts an exception in case of a problem.
*/ 
FILE *loadFile(const char *__restrict__ src) __attribute__((nonnull (1)));
void readHex(FILE *__restrict__ file) __attribute__((nonnull (1)));

int
main(void)
{
    FILE *file = loadFile(FILE_NAME);
    readHex(file);
    fclose(file);
    return 0;
}

FILE *loadFile(const char *__restrict__ src)
{
    FILE *tmp = fopen64(src, "rb+");
    assert(tmp != NULL);
    return tmp;
}

void readHex(FILE *__restrict__ file)
{
    int8_t buffer[BUFFER_SIZE];
    size_t n;

    while((n = fread(&buffer, sizeof(int8_t), BUFFER_SIZE, file)) > 0)
    {
        for(size_t i = 0; i < n; ++i)
        {
            fprintf(stdout, "%2x ", buffer[i]);
        }
        fprintf(stdout, "--> ");
        for(size_t i = 0; i < n; ++i)
        {
            putchar(buffer[i]);
        }
        putchar(NEW_LINE);
    }
}