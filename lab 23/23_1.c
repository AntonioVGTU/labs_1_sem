#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#define _LIST_H


typedef struct listitem
{
	int number;
	char name[80];
	struct listitem* next;
} *list;


void initlist(list* node)
{
	node = (list)malloc(sizeof(list));
}

void insertfront(list* node, int val)
{
	list newnode = malloc(sizeof(list));
	newnode->number = val;
	newnode->next = *node;
	*node = newnode;
}

void insertback(list* node, int val)
{
	list newnode = malloc(sizeof(list));
	newnode->number = val;
	newnode->next = NULL;
	if (*node == NULL)
	{
		*node = newnode;
		return;
	}
	list temp = *node;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}

void insertfront(list* node, char* str)
{
    list newnode = malloc(sizeof(struct listitem));
    strcpy(newnode->name, str);
    newnode->next = *node;
    *node = newnode;
}

void insertback(list* node, char* str) 
{
    list newnode = malloc(sizeof(list));
    strcpy(newnode->name, str);
    newnode->next = NULL;

    if (*node == NULL) 
    {
        *node = newnode;
        return;
    }

    list temp = *node;
    while (temp->next) 
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

bool isempty(list* node) //?????
{
    if (*node==NULL)
    {
        return *node == NULL;
    }
}

int length(list node) 
{
    int len = 0;
    while (node) 
    {
        len++;
        node = node->next;
    }
    return len;
}

void destroyItem(list* node, list nodee) 
{
    if (*node == NULL || node == NULL) return;

    if (*node == nodee) 
    {
        *node = nodee->next;
        free(nodee);
        return;
    }

    list temp = *node;
    while (temp->next && temp->next != nodee) 
    {
        temp = temp->next;
    }

    if (temp->next) 
    {
        temp->next = nodee->next;
        free(nodee);
    }
}

list getitem(list node, int n)
{
    while (node) 
    {
        if (node->number == n) 
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

list getitem(list node, char* str) 
{
    while (node)
    {
        if (strcmp(node->name, str) == 0) 
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}