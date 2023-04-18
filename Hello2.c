#ifndef _WIN32
// #include <windows.h>
// #include <strsafe.h>
// WCHAR szBuffer[100];
// HRESULT hr = StringCbPrintfExW(szBuffer, sizeof(szBuffer), L"", ... 
// if (SUCCEEDED(hr))
// wprintf(L"... : %s\n", szBuffer);
/*
unsigned int random_number_urandom()
{
    unsigned int result;
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd == -1)
    {
        perror("open failed");
        exit(EXIT_FAILURE);
    }
    if (read(fd, &result, sizeof(result)) != sizeof(result))
    {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    close(fd);
    return result;
}
*/
#else
#include <stdio.h>
//#include <stdlib.h>
//#include <cxxabi.h>

/*
#include <pthread.h>
#include <lowlevellock.h>
int lock = 0;
int counter = 0;

void *worker(void *arg) {
for (int i = 0; i < 1000000; i++) {
acquire_lock();
counter++;
release_lock();
}
return NULL;
}

int pmain() {
pthread_t t1, t2;
pthread_create(&t1, NULL, worker, NULL);
pthread_create(&t2, NULL, worker, NULL);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
printf("Counter: %d\n", counter);
return 0;
}
*/

/*
unsigned int random_number_rand_s()
{
    unsigned int result;
    if (rand_s(&result) != 0)
    {
        perror("rand_s failed");
        exit(EXIT_FAILURE);
    }
    return result;
}
*/

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
	int a = 10;
int b[a];
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
