// This is a code snippet that demonstrates how to use the Windows API to measure the execution time of a function.

// Include the necessary header files
//#include <sdkddkver.h>
#include <Windows.h>
#include <profileapi.h>
#include <stdio.h>

// Define a function to test
void foo()
{
    // Do some work here
    for (int i = 0; i < 1000000; i++)
    {
        printf("%d\n", i);
    }
}

// Define a macro to get the current time in microseconds
#define GET_TIME_US() (QueryPerformanceCounter(&li) ? (li.QuadPart * 1000000 / freq.QuadPart) : 0)

int main()
{
    // Declare variables to store the time and frequency
    LARGE_INTEGER li;
    LARGE_INTEGER freq;

    // Get the frequency of the performance counter
    QueryPerformanceFrequency(&freq);

    // Get the start time
    long long start = GET_TIME_US();

    // Call the function to test
    foo();

    // Get the end time
    long long end = GET_TIME_US();

    // Calculate and print the elapsed time in microseconds
    printf("Elapsed time: %lld us\n", end - start);

    return 0;
}
