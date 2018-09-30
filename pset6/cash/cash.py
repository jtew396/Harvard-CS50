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
 * cash.py
 *
 * Executes cash.c more as cash.py
 */
"""

import cs50


def main():
    change_dollars = 0
    change_cents = 0
    count = 0

    while change_dollars <= 0:  # validate for a positive input
        print("Sup dude, how much change is owed?\n")   # prompt the user for the change input
        change_dollars = cs50.get_float()   # gather the input as a float
    change_dollars = change_dollars * 100   # multiply the float to convert into cents
    change_cents = change_dollars   # store the rounded float into change_cents as an integer
    while change_cents >= 25:   # check for the amount of a quarter
        change_cents = change_cents - 25    # subtract the quarter from the total
        count += 1  # add one coin to the counter
    while change_cents >= 10:   # check for the amount of a dime
        change_cents = change_cents - 10    # subtract the dime from the total
        count += 1  # add one coin to the counter
    while change_cents >= 5:    # check for the amount of a nickel
        change_cents = change_cents - 5     # subtract the nickel from the total
        count += 1  # add one coin to the counter
    while change_cents >= 1:    # check for the amount of a penny
        change_cents = change_cents - 1     # subtract the penny from the total
        count += 1  # add one coin to the counter
    print("%d\n" % count)   # display the minimum amount of coins needed


main()