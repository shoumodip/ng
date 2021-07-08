#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Lower boundary for the length of a random name
#define LOWER_NAME_BOUND 3

// Upper boundary for the length of a random name
#define UPPER_NAME_BOUND 7

// Calculate random numbers in a given range
#define random(min, max) (rand() % ((max) + 1 - (min))) + (min)

int main(int argc, const char *argv[])
{
    // Generate REALLY random numbers
    // See https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c
    struct timespec nanos;
    clock_gettime(CLOCK_MONOTONIC, &nanos);
    srand(nanos.tv_nsec);

    int length = (argc > 1) ? atoi(argv[1]) : random(LOWER_NAME_BOUND, UPPER_NAME_BOUND);

    // If the length is 0, user entered invalid number
    // If the length is less than 0, user entered invalid length
    if (length < 1) {
        fprintf(stderr, "invalid length: '%s'\n", argv[1]);
        fprintf(stderr, "Usage: ng [LENGTH]\n");
        exit(1);
    }

    // Setup the name buffer
    char name[length + 1];
                          
    for (int i = 0; i < length; ++i)
        name[i] = random(97, 122);

    // It's C, we have to do stuff like this. *sigh*
    name[length + 1] = '\0';

    // Finally!
    printf("%s\n", name);
}
