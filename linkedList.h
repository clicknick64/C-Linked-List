#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    LIST_STRING,
    LIST_POINTER
} ListMode;

typedef struct ListNode{
    void *data;
    struct ListNode *next;
} *ListNode;

typedef char* String;
typedef String (*GetKeyFunc)(ListNode);
typedef char bool;

typedef struct List{
    GetKeyFunc getKey;
    ListNode head;
    unsigned int size;
} *List;

String get_key_string(ListNode);
String get_key_pointer(ListNode);

GetKeyFunc assignGetKey(ListMode mode);


/*
LIST_STRING
LIST_POINTER
*/
List List_Create(char mode);
void List_Insert(List list, void *data);
ListNode List_Search(List list, void *value);
bool List_Exists(List list, void *value);
void List_Print(List list);
ListNode List_Next(ListNode node);
ListNode List_Begin(List list);
void List_Delete(List list);
void List_Insert_Sorted(List list, void *data);

/*
Returns index of key, -1 if not in list
*/
int List_Index(List list, String key);
void *List_Pop(List list);
ListNode List_At(List list, int index);
int List_Size(List list);