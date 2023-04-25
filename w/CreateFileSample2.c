#include <windows.h>
#include <stdio.h>

void main()
{
HANDLE hFile;
HANDLE hAppend;
DWORD dwBytesRead, dwBytesWritten, dwPos;
BYTE buff[4096];

// Open the existing file.

hFile = CreateFile(TEXT("one.txt"), // file name
GENERIC_READ, // open for reading
0, // do not share
NULL, // default security
OPEN_EXISTING, // existing file only
FILE_ATTRIBUTE_NORMAL, // normal file
NULL); // no template

if (hFile == INVALID_HANDLE_VALUE)
{
printf("Could not open one.txt\n");
return;
}

// Open the existing file for writing.

hAppend = CreateFile(TEXT("two.txt"), // file name
FILE_APPEND_DATA, // open for writing at end
FILE_SHARE_READ, // share for reading
NULL, // default security
OPEN_ALWAYS, // open or create
FILE_ATTRIBUTE_NORMAL,// normal file
NULL); // no template

if (hAppend == INVALID_HANDLE_VALUE)
{
printf("Could not open two.txt\n");
CloseHandle(hFile);
return;
}

// Append the data from one.txt to two.txt.

while (TRUE)
{
if (ReadFile(hFile, buff, sizeof(buff), &dwBytesRead, NULL))
{
if (dwBytesRead == 0) break; // end of file

// Move to the end of two.txt and lock it.

dwPos = SetFilePointer(hAppend, 0, NULL, FILE_END);
LockFile(hAppend, dwPos, 0, dwBytesRead, 0);

// Write the data and unlock it.

WriteFile(hAppend, buff, dwBytesRead, &dwBytesWritten, NULL);
UnlockFile(hAppend, dwPos, 0, dwBytesRead, 0);
}
else
{
printf("Could not read from one.txt\n");
break;
}
}

// Close both files.

CloseHandle(hFile);
CloseHandle(hAppend);
}
