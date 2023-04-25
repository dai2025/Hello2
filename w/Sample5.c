#include <windows.h>
#include <time.h>

#include <profileapi.h>

// This is a blog post about how to use the Windows API to manipulate file times and measure performance.

// The Windows API provides several functions to work with file times, which are 64-bit values that represent the number of 100-nanosecond intervals since January 1, 1601 (UTC). One of these functions is SetFileTime, which allows you to set the creation time, last access time, and last write time of a file.

// However, SetFileTime requires a FILETIME structure as an argument, which is not very convenient to use in C or C++. A more common way to represent time in these languages is the time_t type, which is the number of seconds since January 1, 1970 (UTC). So how can we convert between time_t and FILETIME?

// One way is to use the SystemTimeToFileTime function, which converts a SYSTEMTIME structure (which contains year, month, day, hour, minute, second, and millisecond fields) to a FILETIME structure. However, this requires us to first convert time_t to SYSTEMTIME, which can be done using the gmtime_s or localtime_s functions. This is a bit cumbersome and may introduce some errors due to time zone differences or leap seconds.

// A simpler and more efficient way is to use some arithmetic operations to directly convert time_t to FILETIME. The idea is to multiply time_t by 10^7 (the number of 100-nanosecond intervals in one second) and then add a constant offset that represents the difference between the two epochs (January 1, 1601 and January 1, 1970). This offset is equal to 116444736000000000 in decimal or 0x019DB1DED53E8000 in hexadecimal.

// Here is a function that implements this conversion:

void TimetToFileTime(time_t t, LPFILETIME pft)
{
    ULARGE_INTEGER time_value;
    time_value.QuadPart = (t * 10000000LL) + 116444736000000000LL;
    pft->dwLowDateTime = time_value.LowPart;
    pft->dwHighDateTime = time_value.HighPart;
}

// To convert back from FILETIME to time_t, we can reverse the process by subtracting the offset and dividing by 10^7.

// Now that we have a way to convert between time_t and FILETIME, we can use SetFileTime to change the last write time of a file to the current system time. Here is an example:

BOOL SetFileToCurrentTime(HANDLE hFile)
{
    FILETIME ft;
    SYSTEMTIME st;
    BOOL f;

    GetSystemTime(&st);              // Gets the current system time
    SystemTimeToFileTime(&st, &ft);  // Converts the current system time to file time format
    f = SetFileTime(hFile,           // Sets last-write time of the file 
        (LPFILETIME) NULL,           // to the converted current system time 
        (LPFILETIME) NULL, 
        &ft);    

    return f;
}

// Another useful function in the Windows API is QueryPerformanceCounter, which returns a high-resolution performance counter value. This can be used to measure the execution time of a code segment or the frequency of an event. The performance counter value is a 64-bit integer that increases at a constant rate regardless of processor speed or power-saving mode.

// However, QueryPerformanceCounter also requires a LARGE_INTEGER structure as an argument, which is not very convenient to use in C or C++. A more common way to represent performance counter values in these languages is the int64_t type, which is a signed 64-bit integer. So how can we convert between LARGE_INTEGER and int64_t?

// Fortunately, this conversion is very easy because LARGE_INTEGER is actually a union that contains a QuadPart field of type int64_t. So we can simply access this field directly and cast it to int64_t if needed.

// Here is a function that wraps the QueryPerformanceCounter call and returns an int64_t value:

int64_t GetTicks()
{
    LARGE_INTEGER ticks;
    if (!QueryPerformanceCounter(&ticks))
    {
        // Handle error
    }
    return ticks.QuadPart;
}

// ...
