# C Linked List

## What is special
This library's list can save:
- Pointers
- Strings
- Unsigned long ints
Using included compare functions

## Functions

- **Create an empty list:** List_Create \
*returns: List* 

- **Insert an item in the first place:** List_Insert

- **Search for an item in the list:** List_Search \
*returns: ListNode*

- **Find out if an item exists in list:** List_Exists \
*returns: bool*

- **Print list:** List_Print

- **Next element of list** List_Next \
*returns: ListNode*

- **First item of list:** List_Begin \
*returns: ListNode*

- **Delete list and free memory:** List_Delete

- **Insert item sorting it in:** List_Insert_Sorted

- **Get index of item in array:** List_Index \
*returns: int*

- **Pop first item of list:** List_Pop \
*returns: void\**

- **Get item at index:** List_At \
*returns: ListNode*

- **Get size of list:** List_Size \
*returns: int*

## Usage example
```c
#include "linkedList.h"

int main(){
    List list = List_Create(LIST_STRING);

    String str1 = "Hello";
    String str2 = malloc(6);
    strcpy(str2, "world");

    List_Insert(list, str1);
    List_Insert(list, str2);

    printf("\nList first time:\n");
    List_Print(list);

    String str3 = List_Pop(list);

    printf("\nList second time:\n");
    List_Print(list);

    printf("Popped item: %s\n", str3);

    List_Delete(list);
}
```
Output:
```
List first time:
(0) world
(1) Hello

List second time:
(0) Hello
Popped item: world
```

## Different types

```c
#include "linkedList.h"

int main(){
    List list1 = List_Create(LIST_LONG);
    List_Insert(list1, 5);
    List_Print(list1);

    List list2 = List_Create(LIST_STRING);
    List_Insert(list2, "Hello");
    List_Print(list2);
}
```
Output:
```
(0) 5
(0) Hello
```