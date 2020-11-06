//
//  linklist.c
//  
//
//  Created by Tanisha Dighe on 11/08/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    struct node *next;
};

struct node *listHead = NULL;

void listinsert(char *newname);
void listsearch (char *searchName, struct node **current, struct node **previous, struct node *listHead, int *found);
void listdelete(char *oldName);

int main()
{
    int n=0, i, m;
    char newName[20];

    /*struct node *head = NULL;*/
    struct node *listIndex;
    
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    
    printf("Enter list elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", newName);
        listinsert(strdup(newName));
    }
    
    printf("The list of elements is: \n");
    for (listIndex = listHead; listIndex != NULL; listIndex = listIndex->next)
    {
        printf("%s \n", listIndex->name);
    }

    printf("Enter name to be deleted: ");
    scanf("%s", newName);
    
    listdelete(newName);

    printf("The updated list of elements is: \n");
    for (listIndex = listHead; listIndex != NULL; listIndex = listIndex->next)
    {
        printf("%s \n", listIndex->name);
    }
    
    return 0;
}

void listinsert(char *newName)
{
    struct node *previous, *current, *newNode;
    int found;
    
    printf("In listinsert %s\n", newName);
    
    previous = NULL;
    current = listHead;
    
    listsearch(newName, &current, &previous, listHead, &found);
    
    newNode = (struct node *)malloc(sizeof(struct node));  /*equivalent to "new" of Pascal*/
    newNode->name = newName;
    
    if (previous != NULL)
    {
        newNode->next = previous->next;
        previous->next = newNode;
    }
    else
    {
        newNode->next = listHead;
        listHead = newNode;
    }
}

void listdelete(char *oldName)
{
    struct node *previous, *current;
    int found = 0;
    
    previous = NULL;
    current = listHead;
    
    listsearch(oldName, &current, &previous, listHead, &found);
    
    if (found)
    {
        if (previous != NULL)
            previous -> next = current -> next;
        else
        {
            listHead = current -> next;
        }
        free (current);
    }
    else
        printf("not present - cannot delete\n");
}

void listsearch (char *searchName, struct node **current, struct node **previous, struct node *listHead, int *found)
{
    int notFound, strcmpResult;
    
    *previous = NULL;
    notFound = 1;
    *current = listHead;
    *found = 0;
    printf("In listsearch\n");

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
            *found = 1;
        else *found = 0;
    }
}
