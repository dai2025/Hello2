#include <stdio.h>
#include <stdlib.h>

// a function to allocate memory for an array of size n
double* create_array(int n) {
  double* arr = (double*)malloc(n * sizeof(double));
  if (arr == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  return arr;
}

// a function to print an array of size n
void print_array(double* arr, int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%.2f", arr[i]);
    if (i < n - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

// a function to convolve two arrays of size m and n
double* convolve(double* x, double* h, int m, int n) {
  // the output array has size m + n - 1
  int p = m + n - 1;
  double* y = create_array(p);

  // loop over the output elements
  for (int i = 0; i < p; i++) {
    // initialize the output element to zero
    y[i] = 0;
    // loop over the input elements
    for (int j = 0; j < m; j++) {
      // check if the index is valid
      if (i - j >= 0 && i - j < n) {
        // add the product of the input elements to the output element
        y[i] += x[j] * h[i - j];
      }
    }
  }
  return y;
}

int main1() {
  // create some example arrays
  double x[] = {1, 2, 3};
  double h[] = {0, 1, 0.5};
  int m = sizeof(x) / sizeof(x[0]);
  int n = sizeof(h) / sizeof(h[0]);

  printf("m = %d\n", m);
  printf("n = %d\n", n);

  // print the input arrays
  printf("x = ");
  print_array(x, m);
  printf("h = ");
  print_array(h, n);

  // convolve the input arrays
  double* y = convolve(x, h, m, n);

  // print the output array
  printf("y = ");
  print_array(y, m + n - 1);

  // free the memory allocated for the output array
  free(y);

  return 0;
}
