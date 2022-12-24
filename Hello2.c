static int sub1(void) {
	return (0); // EXIT_SUCCESS;
}

volatile int main(void) {
	int (*func)(void) = sub1;
	return func();
}
