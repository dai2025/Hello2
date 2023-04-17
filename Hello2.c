#include <stdio.h>
//#include <stdlib.h>
//#include <cxxabi.h>

#define print(x) printf(#x ": %s = %s\n", _Generic((x), \
    int: "int", \
    double: "double", \
    char *: "char *", \
    const char*: "const char*", \
    default: "unknown"), #x)

//#define print2(x) printf("%s = %s\n", type_name(&(x)), #x)

int mainn() {
return 0;
}

static int sub1(void) {
	return (0); // EXIT_SUCCESS;
}

int main() {
//      https://en.wikipedia.org/wiki/Name_mangling
//      const char *mangled_name = "_ZNK3MapI10StringName3RefI8GDScriptE10ComparatorIS0_E16DefaultAllocatorE3hasERKS0_";
//      int status = -1;
//      char *demangled_name = abi::__cxa_demangle(mangled_name, NULL, NULL, &status);
//      printf("Demangled: %s\n", demangled_name);
//      free(demangled_name);
const char* mai="mainn";
//print2(mai);
print(mai);
print(mainn);
int (*func)(void) = sub1;
//print(sub1);
return func();
}

//volatile int main(void) {
//		
//}
