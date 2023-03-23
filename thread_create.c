#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void *counter_parallel (void *object);

int main (int argc, char *argv[])
{
    pthread_t thread;

    pthread_create (&thread, NULL, counter_parallel, NULL);

    for (int i = 1; i <= 100; i++)
    {
        printf ("Main counts: %d\n", i);
        usleep (10000);
    }

    return 0;
}

static void *counter_parallel (void *object)
{
    (void)object;

    for (int i = 1; i <= 100; i++)
    {
        printf ("Thread counts: %d\n", i);
        usleep (100000);
    }

    return NULL;
}