#ifndef _WIN32
// #include <windows.h>
// #include <strsafe.h>
// WCHAR szBuffer[100];
// HRESULT hr = StringCbPrintfExW(szBuffer, sizeof(szBuffer), L"", ... 
// if (SUCCEEDED(hr))
// wprintf(L"... : %s\n", szBuffer);
#else
#include <stdio.h>
//#include <stdlib.h>
//#include <cxxabi.h>

#ifndef __cplusplus 
#define print(x) printf(#x ": %s = %s\n", _Generic((x), \
    int: "int", \
    long: "long", \
    double: "double", \
    char *: "char *", \
    const char*: "const char*", \
    default: "unknown"), #x)
#endif

#define type_name(x) _Generic((x), \
int: "int", \
long: "long", \
double: "double", \
char *: "char *", \
		const char*: "const char *", \
default: "unknown")
#endif

//#define print2(x) printf("%s = %s\n", type_name(&(x)), #x)

int mainn(void) {
return 0;
}

static int sub1(void) {
	return (0); // EXIT_SUCCESS;
}

int main(void) {
const char* mai="mainn";
//print2(mai);
print(mai);
print(mainn);
int (*func)(void) = sub1;
//static int (*func2)(void) = mainn;
//func2 = func;
//print(sub1);
return func();
}

//volatile int main(void) {
//		
//}
