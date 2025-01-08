#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first, *last = NULL;
struct SLL *createNode(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    if (NewNode == NULL)
    {
        return NULL;
    }
    else
    {
        NewNode->data = element;
        NewNode->next = NULL;
        return NewNode;
    }
}

void insertAtBeginning(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
    {
        printf("memory allocation failed");
    }
    else
    {
        if (first == NULL) // list is empty
        {
            first = last = NewNode;
        }
        else
        {
            NewNode->next = first;
            first = NewNode;
        }

        printf("%d was Inserted at the beginning \n", first->data);
    }
}

void insertAtEnd(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
    {
        printf("memory allocation failed");
    }
    else
    {
        if (first == NULL) // list is empty
        {
            first = last = NewNode;
        }
        else
        { // list has one or more elements
            last->next = NewNode;
            last = NewNode;
        }

        printf("%d was Inserted at the end\n \n", last->data);
    }
}

int deleteFromBeginning()
{
    struct SLL *temp;
    int element = -1;
    if (first == NULL) // i.e list is empty
    {
        printf("LIST IS EMPTY \n");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        element = temp->data;
        free(temp);
    }
    return element;
}

int deleteFromEnd()
{
    struct SLL *temp;
    int element = -1;
    if (first == NULL) // i.e list is empty
    {
        printf("LIST IS EMPTY \n");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        element = temp->data;
        free(temp);
        last->next = NULL;
    }
    return element;
}

void display()
{
    struct SLL *temp;
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        temp = first;
        do
        {
            printf("%d ->", temp->data);
            temp = temp->next;

        } while (temp != NULL);
        printf("NULL\n");
    }
}

void insertAtSpecific(int element, int position)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
    {
        printf("Memory allocation failed\n");
    }

    if (position == 1)
    {
        insertAtBeginning(element);
    }

    struct SLL *temp = first;
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
        temp->next = NewNode;
        if (NewNode->next == NULL)
        {
            last = NewNode;
        }
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

    struct SLL *temp = first;
    struct SLL *prev = NULL;
    int i;
    for (i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return -1;
    }

    if (temp == last)
    {
        last = prev;
    }

    prev->next = temp->next;
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
    insertAtBeginning(500);
    display();
    data = deleteFromBeginning();
    insertAtSpecific(100, 2);
    display();
    insertAtSpecific(400, 2);
    display();
    deleteAtSpecific(1);
    display();
    if (data != -1)
    {
        printf("%d was deleted from the beginning\n", data);
    }
    display();
    data = deleteFromEnd();
    if (data != -1)
    {
        printf("%d was deleted from the end\n");
    }
    display();
    return 0;
}