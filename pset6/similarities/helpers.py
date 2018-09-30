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
 * helpers.py
"""

from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    """take in string inputs a, b"""
    """split each string into lines"""
    """compute a list of all lines that appear in both a and b"""
    """return the list"""

    string_a = a
    string_b = b
    list_a = string_a.split('\n')
    list_b = string_b.split('\n')
    set_a = set(list_a)
    set_b = set(list_b)
    set_c = set_a & set_b
    list_c = list(set_c)

    return list_c


def sentences(a, b):
    """Return sentences in both a and b"""
    """sent_tokenize, given a str as input, returns a list of English sentences therein.
    It assumes that its input is indeed English text (and not, e.g. code, which might coincidentally have periods too"""
    """take in string inputs a,b"""
    """split each string into sentences"""
    """compute list of all sentences appearing in both a and b"""
    """return the list"""

    string_a = a
    string_b = b
    list_a = sent_tokenize(string_a)
    list_b = sent_tokenize(string_b)
    set_a = set(list_a)
    set_b = set(list_b)
    set_c = set_a & set_b
    list_c = list(set_c)
    return list_c


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    """take in string inputs a, b, and substring length n
    split each string into all substrings of length n
    compute list of all substrings appearing in both a and b
    return the list"""
    """extract substirngs from string
        s[i:j] returns the substring of s from index i to (but not including) index j
        may want to write a helper function
    """

    string_a = a
    string_b = b
    substring_length = n
    list_a = substring_helper(string_a, substring_length)
    list_b = substring_helper(string_b, substring_length)
    set_a = set(list_a)
    set_b = set(list_b)
    set_c = set_a & set_b
    list_c = list(set_c)
    return list_c


def substring_helper(s, n):

    string_length = len(s)
    substring_length = n
    substring_list = []
    if substring_length > string_length:
        return substring_list
    i = 0
    while i <= (string_length - substring_length):
        substring_list.append(s[i:(i + substring_length)])
        i += 1

    return (substring_list)