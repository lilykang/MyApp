/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"


/**
 * define the size of the hash table, which should be greater than the number of words in the dictionary
 */
 
#define SIZE 200000

/**
 * This node struture contains a value, which is stored as an array of characters
 * under the maximum length requirement, and a pointer that enables a linked list.
 */

typedef struct node 
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// make a hash table 
node *hashtable[SIZE] = {NULL};

// initialize dictionary size counter 
int SizeofDictionary = 0;

// initialize loading status
bool loaded = false;

int hash(const char *word)
{
    /**
    * Hash function via reddit user:
    * https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
    */
    
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i<n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % SIZE;

}

/**
 * Returns true if word is in dictionary else false.
 */
 
bool check(const char *word)
{
    
    // declare a character array to store lower-case word and an integer to store the length of the word 
    char converted_word[LENGTH + 1];
    int n = strlen(converted_word);
    
    // covert words into lowercase 
    for (int i = 0; i < n; i++)
    {
        converted_word[i] = tolower(word[i]);
    }
    
    // end the coverted word 
    converted_word[n] = '\0';
    
    // check the entire linked list in the bucket
    
    while (hashtable[hash(word)] != NULL)
    {
        // if the word and the 
        if (strcmp(hashtable[hash(word)]->word,converted_word) == 0)
        {
            return true;
        }
        
        hashtable[hash(word)] = hashtable[hash(word)]->next;
    }
    
    if (hashtable[hash(word)] == NULL)
    {
        return false;
    }
    
    return false;
}


/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
 
bool load(const char *dictionary)
{
    // open the dictionary file with read access
    FILE *fp = fopen(dictionary, "r");
   
    if (fp == NULL)
    {
        return false;
    }
    
    char word[LENGTH + 1];
    
    // loop until reaching the end of the dictionary file
    while (fscanf(fp, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        
        strcpy(new_node->word, word);
        
        /**
         * if the index at hash(word) is not null, the value of the new_node needs to be inserted 
         * to avoid breaking the linked list, the new node has to first point to the previous first node 
         * before the original head pointer points to the new node
         */ 
        if (hashtable[hash(word)] != NULL)
        {
            new_node->next = hashtable[hash(word)];
            hashtable[hash(word)] = new_node;
            SizeofDictionary++;
        }
        
        // if at index hash(word) the value is null, the new word will take up that index 
        else
        {
            hashtable[hash(word)] = new_node;
            new_node->next = NULL;
            SizeofDictionary++;
        }
        
    }
    
    fclose(fp);
    loaded = true;
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (loaded == true)
    {
        return SizeofDictionary;
    }
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashtable[i] != NULL)
        {
            node *temp = hashtable[i];
            hashtable[i] = hashtable[i]->next;
            free(temp);
        }
    }
    loaded = false;
    return true;
}
