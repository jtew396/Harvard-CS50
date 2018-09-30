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
 * caesar.py
 *
 * Executes caesar.c as caesar.py
 */
"""

import cs50
import sys

# starting python code mirror to c code


def main():
    if len(sys.argv) != 2:
        sys.exit(1)
    key = int(sys.argv[1])
    print("plaintext: ", end="")
    plaintext = cs50.get_string()
    print()
    print("ciphertext: ", end="")
    for character in plaintext:
        if str.isalpha(character):
            if str.isupper(character):
                print(chr(((ord(character) + key - 65) % 26) + 65), end="")
            else:
                print(chr(((ord(character) + key - 97) % 26) + 97), end="")
        else:
            print(character, end="")
    print()


main()