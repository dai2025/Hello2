#include <iostream>

int freopen_h() {
  // freopen is a function that redirects the input/output stream to a file
  // The syntax is freopen(filename, mode, stream)
  // filename is a string literal that specifies the name of the file
  // mode is a string literal that specifies the mode of opening the file
  // stream is a pointer to a FILE object that identifies the stream
  // For example, freopen("input.txt", "r", stdin) redirects the standard input stream to the file input.txt
  freopen("output.txt", "w", stdout); // redirect the standard output stream to the file output.txt
  std::cout << "Hello, world!" << std::endl; // print "Hello, world!" to the file output.txt
  return 0;
}
