# Hello2

1. The use of volatile int main(void)
The volatile qualifier indicates that the contents of a variable may be changed at an unexpected time. volatile int main(void) indicates that the main function may be called from anywhere, which is inappropriate for a typical C program.

2. The use of `int (*func)(void) = sub1`
Calling the sub1 function via a function pointer means that the expected arguments and return value of the function may be modified. In this case, the sub1 function only returns a simple exit code, but calling it through a function pointer could overwrite other data in memory with that code.

3. Lack of options
While the CFLAGS includes an optimization option -O0, it is recommended to enable it by default from a security perspective. Additionally, enabling options such as `-fstack-protector` and `-Wformat-security` can enhance the security of the program.
