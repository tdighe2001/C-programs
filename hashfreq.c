//
//  hashfreq.c
//  
//
//  Created by Tanisha Dighe on 04/09/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    int count;
    struct node *next;
};

struct node *listHead = NULL;
void listsearch (char *searchName, struct node **current, struct node **previous, struct node *listHead, int *found);
void listinsert(char *newName);
unsigned hashfunc(char *newName);

#define TABLESIZE 19

int main()
{
    int i,n;
    char newName[20];
    struct node *current;
    int array[TABLESIZE], key, tablesize = TABLESIZE, result;
    /*struct node *head = NULL;*/
    struct node *listIndex;
    
    
    printf("Enter list elements: ");
    for (i = 0; i < TABLESIZE+1; i++)
    {
        scanf("%s", newName);
        listinsert(strdup(newName));
    }
    
    printf("The list of elements is: \n");
    for (listIndex = listHead; listIndex != NULL; listIndex = listIndex->next)
    {
        printf("%s, %d \n", listIndex->name, listIndex->count);
    }

    return 0;
}

void listinsert(char *newName)
{
    struct node *previous, *current, *newNode;
    int found, hashtable[TABLESIZE];
        
    previous = NULL;
    listHead = hashtable[hashfunc(newName)];

    current = listHead;
    
    listsearch(newName, &current, &previous, listHead, &found);
    
    if (found == 1)
        current->count++;
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));  /*equivalent to "new" of Pascal*/
        newNode->name = newName;
        newNode->count = 1;
        if (previous != NULL)
        {
        newNode->next = previous->next;
        previous->next = newNode;
        }
        else
        {
        newNode->next = listHead;
        hashtable[hashfunc(newName)] = newNode;
        listHead = newNode;
        }
    }
}

void listsearch (char *searchName, struct node **current, struct node **previous, struct node *listHead, int *found)
{
    int notFound, strcmpResult;
    
    *previous = NULL;
    notFound = 1;
    *current = listHead;
    *found = 0;
        
    while (notFound && *current != NULL)
    {
        if ((strcmpResult = strcmp(searchName,(*current)->name)) <= 0)
            notFound = 0;
        else
        {
            *previous = *current;
            *current = (*current)->next;
        }
        printf("%d ", strcmpResult);
    }
    
    if (*current != NULL)
    {
        if (strcmpResult == 0)
        {
            *found = 1;
        }
        else *found = 0;
    }
}
/*
int hashfunc(char *newName)

{
   ** hash:  form hash value for string s **
    #define HASHSIZE 101
     static struct nlist *hashtab[HASHSIZE];
    */
unsigned hashfunc(char *newName)
    {
       unsigned hashval;
    for (hashval = 0; *newName != '\0'; newName++)
           hashval = *newName + 31 * hashval;
       return hashval % TABLESIZE;
    }


   
    
    
    
    
    
