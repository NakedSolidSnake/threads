#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void *sum (void *object);

int main (int argc, char *argv[])
{
    pthread_t thread;
    int limit = 100;
    int *result = NULL;

    pthread_create (&thread, NULL, sum, &limit);

    for (int i = 1; i <= 100; i++)
    {
        printf ("Main counts: %d\n", i);
        usleep (10000);
    }

    pthread_join (thread, (void **)&result);

    printf ("Result: %d\n", *result);

    free (result);
    return 0;
}

static void *sum (void *object)
{
    int *limit = (int *)object;

    int *total = calloc (1, sizeof (int));

    for (int i = 1; i <= *limit; i++)
    {
        *total += i;
    }

    return total;
}