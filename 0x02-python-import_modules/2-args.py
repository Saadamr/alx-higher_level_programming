#!/usr/bin/python3

import sys

if __name__ == "__main__":
    args = sys.argv[1:]  # Exclude the script name itself

    # Print the number of arguments
    num_args = len(args)
    if num_args == 0:
        print("0 arguments.")
    elif num_args == 1:
        print("1 argument:")
    else:
        print(f"{num_args} arguments:")

    # Print the list of arguments with their positions
    for i, arg in enumerate(args, 1):
        print(f"{i}: {arg}")

