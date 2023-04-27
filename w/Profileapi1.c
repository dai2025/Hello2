// #include <sdkddkver.h>
#include <Windows.h>
#include <profileapi.h>
#include <stdio.h>

// This program demonstrates how to use the QueryPerformanceCounter and QueryPerformanceFrequency functions
// to measure the execution time of a code segment in microseconds.

int main()
{
    // Declare variables to store the performance counter values and the frequency
    LARGE_INTEGER start, end, freq;
    
    // Get the frequency of the performance counter
    QueryPerformanceFrequency(&freq);
    
    // Get the current value of the performance counter before the code segment
    QueryPerformanceCounter(&start);
    
    // The code segment to be measured
    printf("Hello, world!\n");
    
    // Get the current value of the performance counter after the code segment
    QueryPerformanceCounter(&end);
    
    // Calculate the elapsed time in microseconds
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart * 1000000;
    
    // Print the result
    printf("The code segment took %.2f microseconds to execute.\n", elapsed);
    
    return 0;
}
