# numpy_convolve2
# Sample program
import numpy as np

def convolve(a, b):
  # Get the lengths of a and b
  m = len(a)
  n = len(b)
  # Determine the length of the output array
  k = m + n - 1
  # Initialize the output array with zeros
  c = np.zeros(k)
  # Calculate the convolution
  for i in range(k):
    # Determine the indices of the overlapping part of a and b
    start = max(0, i - n + 1)
    end = min(i + 1, m)
    # Multiply and add the elements of the overlapping part of a and b
    for j in range(start, end):
      c[i] += a[j] * b[i - j]
  # Return the output array
  return c

# Arrays for testing
a = np.array([1, 2, 3])
b = np.array([0, 1, 0.5])

# Display the result of convolution
print(convolve(a, b))
