"""
- This is a sample code that demonstrates how to use the argparse module in Python
- The argparse module allows you to create command-line interfaces for your programs
- You can define the arguments and options that your program accepts and parse them easily
- The FileType argument type is a special type that opens a file with the given mode and encoding
- Here is an example of how to use the FileType argument type:
"""

import argparse

# Create a parser object
parser = argparse.ArgumentParser(description="A sample program that reads and writes files")

# Add a positional argument for the input file
parser.add_argument("infile", type=FileType("r"), help="The input file to read from")

# Add an optional argument for the output file
parser.add_argument("-o", "--outfile", type=FileType("w"), default=None, help="The output file to write to")

# Parse the arguments
args = parser.parse_args()

# Read the input file and print its contents
print(f"Reading from {args.infile.name}")
for line in args.infile:
    print(line, end="")

# Write to the output file if specified
if args.outfile:
    print(f"Writing to {args.outfile.name}")
    args.infile.seek(0) # Go back to the beginning of the input file
    for line in args.infile:
        args.outfile.write(line)

# Close the files
args.infile.close()
if args.outfile:
    args.outfile.close()
