#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteFirst(struct Node * head)
{
    struct Node * ptr = head;
    head = head ->next;
    free(ptr);
    return head;
}

struct Node * deleteNodeBetween(struct Node * head, int ind){
    // int ind;
    // printf("Enter the index:\n");
    // scanf("%d",ind);

    struct Node *p = head;
    struct Node *q = p->next;

    for (int i = 0; i < ind-1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
    
}

struct Node * deleteLast(struct Node * head){
      struct Node *p = head;
      struct Node *q = p->next;

      while (q->next != NULL)
      {
         p = p->next;
         q = q->next;
      }

      p->next = NULL;
      free(q);
      return head;
      
}
    
// Case 4: Deleting the element with a given value from the linked list
struct Node * deleteByValue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}


    
 
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));     // syntax for DMA: (castType*) malloc(size);
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 12;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
     
    printf("Linked list before deletion\n"); 
    linkedListTraversal(head);
    
    // head = deleteFirst(head);
    // head = deleteNodeBetween(head,2);
    // head = deleteLast(head);
    head = deleteByValue(head, 66);

    printf("Linked list after deletion\n");
    linkedListTraversal(head);
    return 0;
}
    
