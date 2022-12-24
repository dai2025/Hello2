static int defer(void) {
	return (0); // EXIT_SUCCESS;
}

volatile int main(void) {
	int (*func)(void) = defer;
	return func();
}
