/*
Implement single (circular or non-circular) linked list to perform the following operations
i) Insert by order ii) Delete at beginning iii) Search for an item by key iv) Delete by key
Display the list contents after each operation.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;
typedef struct List
{
    int size;
    Node *head;
} List;

void insertbyorder(List *, int);
void deleteAtStart(List *);
int searchByKey(List *, int);
void deleteByKey(List *, int);
Node *createnode(int);
void initialize(List *);
void display(List *list);
void append(List *list, int val);
void freelist(List *list);

int main()
{
    int ch, key, val, pos;
    List list;
    initialize(&list);
    printf("Menu: \n1. Display\n2. Append\n3. Insert by order\n4. Delete at start\n5. Search by key\n6. Delete by key\n");

    while (1)
    {
        printf("Enter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display(&list);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            append(&list, val);
            display(&list);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            insertbyorder(&list, val);
            display(&list);
            break;
        case 4:
            deleteAtStart(&list);
            display(&list);
            break;
        case 5:
            printf("Enter key: ");
            scanf("%d", &key);
            int pos = searchByKey(&list, key);
            if (pos != -1)
                printf("The key is found at %d.\n", pos);
            else
                printf("Key is NOT found.\n");
            display(&list);
            break;
        case 6:
            printf("Enter the key to be deleted: ");
            scanf("%d", &key);
            deleteByKey(&list, key);
            display(&list);
            break;
        case 7:
            freelist(&list);
            exit(0);
        default:
            printf("Invalid choice..\n");
        }
    }
}
Node *createnode(int val)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = val;
    new->link = NULL;
    return new;
}
void initialize(List *l)
{
    l->size = 0;
    Node *new = createnode(0);
    l->head = new;
}
void insertbyorder(List *l, int val)
{
    Node *current = l->head->link;
    Node *prev = l->head;
    Node *new = createnode(val);
    if (current == NULL)
    {
        l->head->link = new;
        l->size++;
        return;
    }
    while (current != NULL && current->data < val)
    {
        prev = current;
        current = current->link;
    }
    new->link = prev->link;
    prev->link = new;
    l->size++;
}

void deleteAtStart(List *list)
{
    Node *current = list->head->link;
    if (current == NULL)
    {
        printf("List is empty");
        return;
    }
    int ele = current->data;
    list->head->link = current->link;
    free(current);
    list->size--;
    printf("%d is deleted.\n", ele);
}
int searchByKey(List *list, int key)
{
    Node *current = list->head->link;
    if (current == NULL)
    {
        printf("List is empty..\n");
        return -1;
    }
    int pos = 1;
    while (current != NULL)
    {
        if (current->data == key)
            return pos;
        pos++;
        current = current->link;
    }
    return -1;
}
void deleteByKey(List *list, int key)
{
    Node *current = list->head->link;
    if (current == NULL)
    {
        printf("List is Empty..\n");
        return;
    }
    Node *prev = list->head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            prev->link = current->link;
            int ele = current->data;
            free(current);
            list->size--;
            printf("%d is deleted..\n", ele);
            return;
        }
        prev = current;
        current = current->link;
    }
    printf("Key Not found..\n");
}
void display(List *list)
{
    Node *current = list->head->link;
    if (current == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    printf("List:\t");
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->link;
    }
    printf("\n");
}

void append(List *list, int val)
{
    Node *current = list->head;
    Node *new = createnode(val);
    while (current->link != NULL)
        current = current->link;
    current->link = new;
}
void freelist(List *list)
{
    Node *current = list->head;
    Node *temp = NULL;
    while (current != NULL)
    {
        temp = current->link;
        free(current);
        current = temp;
    }
}