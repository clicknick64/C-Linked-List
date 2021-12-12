#include "linkedList.h"

String get_key_string(ListNode node)
{
    return (String)(node->data);
}

String get_key_pointer(ListNode node)
{
    return NULL;
}

GetKeyFunc assignGetKey(ListMode mode)
{
    switch (mode)
    {
    case LIST_STRING:
        return get_key_string;
    case LIST_POINTER:
        return get_key_pointer;
    }

    printf("ERROR: Not able to resolve type: %c\n", mode);
    return NULL;
}

List List_Create(char mode)
{
    List list = malloc(sizeof(*list));
    list->getKey = assignGetKey(mode);
    list->head = NULL;
    list->size = 0;
    return list;
}

void List_Insert(List list, void *data)
{
    ListNode node = malloc(sizeof(*node));
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}

ListNode List_Search(List list, void *value)
{
    ListNode node = list->head;
    while (node != NULL)
    {

        if (!strcmp((String)value, list->getKey(node)))
            return node;
        node = node->next;
    }
    return NULL;
}

bool List_Exists(List list, void *value)
{
    return List_Search(list, value) != NULL;
}

void List_Print(List list)
{
    ListNode node = list->head;
    int i = 0;
    while (node != NULL)
    {
        printf("(%d) %s\n", i, list->getKey(node));
        node = node->next;
        i++;
    }
}

ListNode List_Next(ListNode node)
{
    return node->next;
}

ListNode List_Begin(List list)
{
    return list->head;
}

void List_Delete(List list)
{
    ListNode node = list->head;
    ListNode prev_node;

    while (node != NULL)
    {
        prev_node = node;
        node = node->next;
        free(prev_node);
    }
    free(list);
}

void List_Insert_Sorted(List list, void *data)
{
    list->size++;
    ListNode node = malloc(sizeof(*node));
    node->data = data;
    ListNode current;
    if (list->head == NULL || strcmp(list->getKey(list->head), list->getKey(node)) > 0)
    {
        node->next = list->head;
        list->head = node;
        return;
    }
    current = list->head;
    while (current->next != NULL && strcmp(list->getKey(current->next), list->getKey(node)) < 0)
    {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
}

int List_Index(List list, String key)
{
    ListNode node = list->head;
    int i = 0;
    while (node != NULL)
    {
        if (!strcmp(list->getKey(node), (String)key))
        {
            return i;
        }
        node = node->next;
        i++;
    }
    return -1;
}

void *List_Pop(List list)
{
    if (list->head == NULL)
        return NULL;

    list->size--;
    ListNode old_head = list->head;
    list->head = old_head->next;
    void *data = old_head->data;
    free(old_head);
    return data;
}

ListNode List_At(List list, int index)
{
    ListNode node = List_Begin(list);
    for (int i = 0; i < index; i++)
    {
        node = List_Next(node);
    }
    return node;
}

int List_Size(List list)
{
    return list->size;
}