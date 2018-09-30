"""
/**
 * J.T. Williams
 *
 * Tech901 Code1.0
 *
 * CS50
 *
 * Problem Set 6
 *
 * mario.py
 *
 * Executes mario.c more as mario.py
 */
"""
import cs50


def main():
    space = 0   # declared space to be used later
    hashes = 0  # declared hash to be used later
    i = 0   # declared i to be used later
    height = -1     # declaring an integer height
    while height < 0 or height > 23:
        print("What is the height: ")
        height = cs50.get_int()
    while i < height:
        space = 1
        while space < (height - i):
            print(" ", end="")
            space += 1

        hashes = -1
        while hashes < (height - space):
            print("#", end="")
            hashes += 1

        print("  ", end="")

        hashes = -1
        while hashes < (height - space):
            print("#", end="")
            hashes += 1
        i += 1
        print("")


if __name__ == "__main__":
    main()