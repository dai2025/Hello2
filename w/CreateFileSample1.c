// Include the necessary header files
#include <windows.h>
#include <stdio.h>

void main()
{
  HANDLE hFile; // Handle to the existing file
  HANDLE hAppend; // Handle to the file opened for appending
  DWORD  dwBytesRead, dwBytesWritten, dwPos; // Variables to store the number of bytes read, written and the file pointer position
  BYTE   buff[4096]; // Buffer to store the data to be appended

  // Open the existing file with read access
  hFile = CreateFile(TEXT("one.txt"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  // Check if the file is opened successfully
  if (hFile == INVALID_HANDLE_VALUE)
  {
    printf("Could not open one.txt.\n");
    return;
  }

  // Read the data from the existing file into the buffer
  if (ReadFile(hFile, buff, sizeof(buff), &dwBytesRead, NULL))
  {
    printf("Read %d bytes from one.txt.\n", dwBytesRead);
  }
  else
  {
    printf("Could not read from one.txt.\n");
    return;
  }

  // Close the handle to the existing file
  CloseHandle(hFile);

  // Open the same file with write access and append mode
  hAppend = CreateFile(TEXT("one.txt"), FILE_APPEND_DATA, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

  // Check if the file is opened successfully
  if (hAppend == INVALID_HANDLE_VALUE)
  {
    printf("Could not open one.txt for appending.\n");
    return;
  }

  // Move the file pointer to the end of the file
  dwPos = SetFilePointer(hAppend, 0, NULL, FILE_END);

  // Check if the file pointer is moved successfully
  if (dwPos == INVALID_SET_FILE_POINTER)
  {
    printf("Could not move the file pointer.\n");
    return;
  }

  // Write the data from the buffer to the end of the file
  if (WriteFile(hAppend, buff, dwBytesRead, &dwBytesWritten, NULL))
  {
    printf("Wrote %d bytes to one.txt.\n", dwBytesWritten);
  }
  else
  {
    printf("Could not write to one.txt.\n");
    return;
  }

  // Close the handle to the file opened for appending
  CloseHandle(hAppend);

}
