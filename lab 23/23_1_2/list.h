#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

typedef struct listitem* List;

void initlist(List* list);
void insertfront(List* list, int val);
void insertback(List* list, int val);
void insertfront_by_name(List* list, char* str);
void insertback_by_name(List* list, char* str);
bool isempty(List list);
int length(List list);
void destroyItem(List* list, List node);
List getitem_by_number(List list, int n);
List getitem_by_name(List list, char* str);

#endif /* _LIST_H */
