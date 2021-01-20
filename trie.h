#ifndef _TRIE_H_
#define _TRIE_H_

#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>

// Alphabet size  
#define ALPHABET_SIZE (26) 

/*This is a counstructor*/
 
typedef struct TrieNode TrieNode;

TrieNode *initializeNode();
void insert(struct TrieNode *root,  char word[]);
void EmptyTheTrie (struct TrieNode *root);
void PrintWords  ( struct TrieNode* current, char word[],  int level );
void PrintWordsReverse  ( struct TrieNode* current, char word[],  int level );


#endif







