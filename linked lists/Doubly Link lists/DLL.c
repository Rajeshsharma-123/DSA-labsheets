#include <stdio.h>
#include <stdlib.h>

struct DLL
{
    int data;
    struct DLL *prev;
    struct DLL *next;
};

struct DLL *first = NULL, *last = NULL;

struct DLL *createNode(int element)
{
    struct DLL *NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    if (NewNode == NULL)
    {
        return NULL;
    }
    NewNode->data = element;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    return NewNode;
}

void insertAtBeginning(int element)
{
    struct DLL *NewNode = createNode(element);
    if (NewNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    if (first == NULL) // List is empty
    {
        first = last = NewNode;
    }
    else
    {
        NewNode->next = first;
        first->prev = NewNode;
        first = NewNode;
    }
    printf("%d was inserted at the beginning\n", element);
}

void insertAtEnd(int element)
{
    struct DLL *NewNode = createNode(element);
    if (NewNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    if (first == NULL) // List is empty
    {
        first = last = NewNode;
    }
    else
    {
        last->next = NewNode;
        NewNode->prev = last;
        last = NewNode;
    }
    printf("%d was inserted at the end\n", element);
}

int deleteFromBeginning()
{
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
        return -1;
    }

    struct DLL *temp = first;
    int element = temp->data;

    if (first == last) // Only one element
    {
        first = last = NULL;
    }
    else
    {
        first = first->next;
        first->prev = NULL;
    }

    free(temp);
    printf("%d was deleted from the beginning\n", element);
    return element;
}

int deleteFromEnd()
{
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
        return -1;
    }

    struct DLL *temp = last;
    int element = temp->data;

    if (first == last) // Only one element
    {
        first = last = NULL;
    }
    else
    {
        last = last->prev;
        last->next = NULL;
    }

    free(temp);
    printf("%d was deleted from the end\n", element);
    return element;
}

void display()
{
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }

    struct DLL *temp = first;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtSpecific(int element, int position)
{
    if (position == 1)
    {
        insertAtBeginning(element);
        return;
    }

    struct DLL *NewNode = createNode(element);
    if (NewNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    struct DLL *temp = first;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(NewNode);
    }
    else
    {
        NewNode->next = temp->next;
        NewNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = NewNode;
        }
        else
        {
            last = NewNode;
        }
        temp->next = NewNode;
        printf("%d was inserted at position %d\n", element, position);
    }
}

int deleteAtSpecific(int position)
{
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
        return -1;
    }

    if (position == 1)
    {
        return deleteFromBeginning();
    }

    struct DLL *temp = first;
    for (int i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return -1;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    else
    {
        last = temp->prev;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    int element = temp->data;
    free(temp);
    printf("%d was deleted from position %d\n", element, position);
    return element;
}

int main()
{
    int data;
    insertAtBeginning(100);
    display();
    insertAtEnd(200);
    display();
    insertAtBeginning(300);
    display();
    insertAtSpecific(400, 2);
    display();
    data = deleteFromBeginning();
    if (data != -1)
    {
        printf("%d was deleted from the beginning\n", data);
    }
    display();
    data = deleteAtSpecific(2);
    if (data != -1)
    {
        printf("%d was deleted from position 2\n", data);
    }
    display();
    data = deleteFromEnd();
    if (data != -1)
    {
        printf("%d was deleted from the end\n", data);
    }
    display();
    return 0;
}
