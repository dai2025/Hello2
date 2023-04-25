// This is a code block for a blog post about how to use the FindFirstFile function in Windows
// The code is written in C and uses the TCHAR header for compatibility with different character sets
// The code takes a file name as an argument and prints out various information about the file

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

void _tmain(int argc, TCHAR *argv[])
{
    // Declare variables to store the file data
    // WIN32_FIND_DATAA finddata_a;
    // WIN32_FIND_DATAW finddata_w;
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;

    // Check if the argument is valid
    if (argc != 2)
    {
        _tprintf(TEXT("Usage: %s <file name>\n"), argv[0]);
        return;
    }

    // Use the FindFirstFile function to get the file data
    hFind = FindFirstFile(argv[1], &FindFileData);

    // Check if the function succeeded
    if (hFind == INVALID_HANDLE_VALUE)
    {
        _tprintf(TEXT("FindFirstFile failed (%d)\n"), GetLastError());
        return;
    }

    // Print out the file data
    printf ("dwFileAttributes; (%lu)\n", FindFileData.dwFileAttributes);
    printf ("ftCreationTime.dwLowDateTime; (%lu)\n", FindFileData.ftCreationTime.dwLowDateTime);
    printf ("ftCreationTime.dwHighDateTime; (%lu)\n", FindFileData.ftCreationTime.dwHighDateTime);
    printf ("ftLastAccessTime.dwLowDateTime; (%lu)\n", FindFileData.ftLastAccessTime.dwLowDateTime);
    printf ("ftLastAccessTime.dwHighDateTime; (%lu)\n", FindFileData.ftLastAccessTime.dwHighDateTime);
    printf ("ftLastWriteTime.dwLowDateTime; (%lu)\n", FindFileData.ftLastWriteTime.dwLowDateTime);
    printf ("ftLastWriteTime.dwHighDateTime; (%lu)\n", FindFileData.ftLastWriteTime.dwHighDateTime);
    printf ("nFileSizeHigh; (%lu)\n", FindFileData.nFileSizeHigh);
    printf ("nFileSizeLow; (%lu)\n", FindFileData.nFileSizeLow);
    printf ("dwReserved0; (%lu)\n", FindFileData.dwReserved0);
    printf ("dwReserved1; (%lu)\n", FindFileData.dwReserved1);
    _tprintf (TEXT("cAlternateFileName; (%s)\n"), FindFileData.cAlternateFileName);

    // Close the handle
    FindClose(hFind);
}
