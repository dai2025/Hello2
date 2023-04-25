#include <windows.h>
#include <tchar.h>
#include <stdio.h>

void _tmain(int argc, TCHAR *argv[])
{
WIN32_FIND_DATAA finddata_a;
WIN32_FIND_DATAW finddata_b;

// Initialize the structures with zeros
ZeroMemory(&finddata_a, sizeof(finddata_a));
ZeroMemory(&finddata_b, sizeof(finddata_b));

// ...
}
