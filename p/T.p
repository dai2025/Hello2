"""
- I import the T module from the re package
- I create sample code using the T module
- The T module provides various functions and constants for working with text patterns
- Some of the functions are: T.match, T.search, T.sub, T.split, T.compile
- Some of the constants are: T.I, T.M, T.S, T.X
"""

# This is a sample code that uses argparse, doctest and re modules
# It takes a file name as an argument and runs doctests on it
# It also prints the number of matches for the letter T in the file

from argparse import FileType # import FileType class from argparse module
from doctest import master # import master object from doctest module
from re import T # import T pattern from re module

# Create an argument parser object
parser = argparse.ArgumentParser(description="Run doctests on a file and count T's")

# Add a positional argument for the file name
parser.add_argument("file", type=FileType("r"), help="The file to test")

# Parse the arguments
args = parser.parse_args()

# Run doctests on the file and print the results
results = master.run(args.file, verbose=True)
print(f"Ran {results.attempted} tests, {results.failed} failed.")

# Count the number of matches for T in the file and print the result
matches = len(T.findall(args.file.read()))
print(f"Found {matches} occurrences of T in the file.")
