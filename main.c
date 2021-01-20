#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    
    int i=0;
    int max=0;
    TrieNode *root=initializeNode(); // initiaize the root
    //memory allocation
    char *word= (char *)malloc(sizeof(*word)*2);
    //do we add 2 because /0 ?

    *word=0;
    *(word+1)=0;
    char lett;
    while((lett=getc(stdin))!=EOF){ //if success
       if(lett!='\n' && lett!='\t' && lett!=' ' && lett!=',' && lett!='\0' && lett!=' '){
           if((lett >= 'a' && lett <= 'z') || (lett >= 'A' && lett <= 'Z')){
            //put in the word
            //printf("%d i issssssssssssssssssssssssssssssssssssssssssssssssssssss=\n",i);

            *(word+i)=lett;
            i++;
            word=(char*)realloc(word, i+2); //will do realloc for the w
            //zero all the chars at array after realloc.
            for(int j=i;j<i+2;j++){
                
                *(word+j)=0; //initalize the location that add to the allocated space
            }
        }
       }
        
    if(lett=='\n' || lett=='\t' || lett==' ' || lett==',' || lett=='\0' || lett==' '){ //the word is finished
        insert(root,word);
        free(word);
        word= (char*)malloc(sizeof(char)*2);
        //initialize the char
        *word=0;
        *(word+1)=0;
            if(max>=i){
                max=i;
            }
        i=0;
        }
    }   
    
    if(i>0){//don't insert the last word
        insert(root,word);
        free(word);//free the allocate location
    word=NULL;
    }
    
    if(i==0){//entered the last word
    free(word);
    word=NULL;
    }
       

    char size[max];
    if(argc==1){
    PrintWords  ( root, size,  0 );
    }
    else if(argc==2){
        if (strcmp(argv[1],"r")==0){
            PrintWordsReverse(root, size,0);

        }
    }
    

EmptyTheTrie(root);

return 0;
}


