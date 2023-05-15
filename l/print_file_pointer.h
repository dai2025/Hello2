// This function prints the contents of a file pointer
void print_file_pointer(FILE *fp) {
  // Check if the file pointer is valid
  if (fp == NULL) {
    printf("Invalid file pointer.\n");
    return;
  }
  // Get the base and current position of the read buffer
  char *base = fp->_IO_read_base;
  char *ptr = fp->_IO_read_ptr;
  // Loop through the buffer and print each character
  while (ptr < base + fp->_IO_read_end) {
    putchar(*ptr);
    ptr++;
  }
}
