#include "trie.h"

typedef struct TrieNode { 
    struct TrieNode *children[ALPHABET_SIZE]; 
    char letter;
    long unsigned int count;
    int isEndOfWord; //if the node is a leaf (false=0, true=1)
}TrieNode;


/*This function initialized the node with children null */
 TrieNode *initializeNode()
{
    TrieNode *node= ( TrieNode *)malloc(sizeof( TrieNode));
        node->count = 0;
        node->isEndOfWord = 0; //false
         node->letter=' ';
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            node->children[i] = NULL;
        }   
   
    return node;
}


/*This function insert a word to the Trie*/
void insert( TrieNode *root, char word[])
{
    char index=0;
    int i=0;
    // struct TrieNode *current = root;
    

    while((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')){
                word[i] = tolower(word[i]); //move to lowercase
                index = word[i]; //go to the location in the children
                if (root->children[index-'a'] == NULL)
                { //null
                    root->children[index-'a'] = initializeNode();
                    root->children[index-'a']->letter = word[i]; //put the letter of the word in the node children letter
                  
                }
                i++;
                root = root->children[index-'a'];
            }

       
            // word++;  

    root->isEndOfWord = 1; //true
    root->count++; // the end of the word
        
    }



/*This function is clear all the trie*/
void EmptyTheTrie( TrieNode *root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    { //recorsive call
        if (root->children[i] != NULL)
        { //have children
            EmptyTheTrie(root->children[i]);
        }
    }
    if (root)
    {
        free(root);
    }
}



/* This function is recursive and will print the word */
void PrintWords( TrieNode *current, char word[], int level)
{
    if (current->isEndOfWord == 1 && current->letter!=' ' )// isn't a root
    {
        word[level]=current->letter;
        word[level+1] = '\0';

        printf("%s ", (word+1)); //print the line as ask
        printf("%lu\n", current->count);
    }
    
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (current->children[i] )
        {
            word[level] = current->letter;
             PrintWords(current->children[i], word, level + 1);
        }
    }
}

/* This function is recursive and will print the word reverse */
void PrintWordsReverse( TrieNode *current, char word[], int level)
{
    if (current->isEndOfWord == 1 && current->letter!=' ')//is the start && isn't the root
    {
         if(current->letter>='a'&&current->letter<='z'){
            word[level] = current->letter;
            }
        word[level+1]='\0';
        printf("%s ", word); //print the line as ask
        printf("%lu\n", current->count);
    }

    for (int i = ALPHABET_SIZE - 1; i >= 0; i--)
    {
        if (current->children[i])
        {
            int add=0;
            if(current->letter>='a'&&current->letter<='z'){
            word[level] = current->letter;
            add=1;
            }
            PrintWordsReverse(current->children[i], word, level+add);
        }
    }
}

// test valgrind- the class
// int main(){
//       TrieNode *root=initializeNode();
//       char word[]={"shani"};
//       char word2[]={"shalel"};
//       char temp[]="";
//       insert(root, word);
//       insert(root, word2);
//       PrintWords(root, temp, 0);
//       PrintWordsReverse(root, temp, 0);
//       EmptyTheTrie(root);
// }
