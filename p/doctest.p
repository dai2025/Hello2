"""
- I use the doctest module to test my code snippets
- The master function runs all the tests in a given file
- Here is an example of how I write sample code with doctest:
"""

def add(x, y):
    """
    Returns the sum of x and y.

    >>> add(2, 3)
    5
    >>> add(-1, 1)
    0
    """
    return x + y

if __name__ == "__main__":
    import doctest
    doctest.master()
