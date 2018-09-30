/**
 * J.T. Williams
 *
 * Tech901 Code1.0
 *
 * CS50
 *
 * Problem Set 5
 *
 * dictionary.c
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

typedef struct node
{
    bool is_word;
    struct node *children[27];
}
node;

//create a root node
node *root;
//node *cursor;

/**
 * You can print a representation of a trie & its children.
 */
void printTrie(node *t) {
    printf("\n---- trie at %p -----\n", t);
    printf("- is_word: %d\n", t -> is_word);
    printf("- children: ");
    for(int i=0; i < 27; i++) {
        if(t->children[i] == NULL) {
            printf(" | _");
        } else {
            printf(" | %d", i);
        }
    }
    printf("\n");
}

//go ahead and declare a create a node function
node* createnode()
{
    node *t = malloc(sizeof(node));
    for (int i = 0; i < 27; i++)
    {
        t -> children[i] = NULL;
    }
    t -> is_word = false;
    return t;
}

//go ahead and declare a function to free the memory at the node
void freeTrie(node *t)
{
    //iterate through the trie node
    for (int i = 0; i < 27; i++)
    {
        //if the node pointer has a child, use recursion
        if(t -> children[i] != NULL)
        {
            freeTrie(t -> children[i]);
        }
    }
    //free the node
    free(t);
}


//malloc root node for global use
//root = malloc(sizeof(node));

//total number of words
int wordcount = 0;

//getting the number for the index
int getnumber(char c)
{
    if(c == '\'')
    {
        return 26;
    }
    else
    {
        return c - 97;
    }
}

void insert(const char* word, const int i)
{
        node *cursor = root;
        int index = 0;
        for (int k = 0; k < i; k++)
        {
            index = getnumber(word[k]);
            if(cursor -> children[index] == NULL)
            {
                //printf("checking to malloc for new node\n");
                //node *newnode = createnode();
                //cursor -> children[index] = newnode;
                cursor -> children[index] = createnode();
                //printf("successfully malloc for new node\n");
            }
            //printTrie(cursor);
            cursor = cursor -> children[index];
            //printf("print the cursor\n");
            //printTrie(cursor);
            //printf("it should have printed the cursor\n");
        }
        cursor -> is_word = true;
        wordcount++;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    node *cursor = root;

    for(int i = 0; i < strlen(word); i++)
    {
        int letter = getnumber(tolower(word[i]));
        if(cursor -> children[letter] == NULL)
        {
            return false;
        }
        cursor = cursor -> children[letter];
        /*
        if(cursor -> children[letter] != NULL)
        {
            cursor = cursor -> children[letter];
        }
        */
    }

    if(cursor -> is_word == true)
    {
        return true;
    }

    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    //create a root node
    root = createnode();

    //open the dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        //printf("Could not load dictionary.");
        return false;
    }
    char word[LENGTH];
    int i = 0;
    while (!feof(dict))
    {
        //printf("start the while loop\n");
        //int i = 0;
        char c = fgetc(dict);
        if(isalpha(c) || (c == '\''))
        {
            //printf("inserting char to word\n");
            word[i] = c;
            //printf("char inserted\n");
            i++;
        }
        if(c == 10)
        {
            insert(word, i);
            i = 0;
        }
    }
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return wordcount;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    freeTrie(root);
    //if(root != NULL)
    //{
    //    return false;
    //}
    return true;
}