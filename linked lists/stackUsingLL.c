#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the stack
struct Node {
    int data;           // Data to store the value
    struct Node *next;  // Pointer to the next node
};

// Global pointer to represent the top of the stack
struct Node* top = NULL;

// Function to traverse and print all elements in the stack
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data); // Print the data of the current node
        ptr = ptr->next; // Move to the next node
    }
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    if (top == NULL) { // If top is NULL, the stack is empty
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the stack is full (unable to allocate memory)
int isFull(struct Node* top) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node)); // Try to allocate memory
    if (p == NULL) { // If malloc fails, stack is full
        return 1;
    } else {
        free(p); // Free the allocated memory if successful
        return 0;
    }
}

// Function to push an element onto the stack
struct Node* push(struct Node* top, int x) {
    if (isFull(top)) { // Check if the stack is full
        printf("Stack Overflow\n");
    } else {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
        n->data = x;  // Set the data
        n->next = top; // Point the new node's next to the current top
        top = n;       // Update the top pointer
        return top;    // Return the updated top pointer
    }
}

// Function to pop an element from the stack
int pop(struct Node* tp) {
    if (isEmpty(tp)) { // Check if the stack is empty
        printf("Stack Underflow\n");
    } else {
        struct Node* n = tp; // Temporary pointer to the current top
        top = (tp)->next;    // Move the top pointer to the next node
        int x = n->data;     // Store the data from the popped node
        free(n);             // Free the memory of the popped node
        return x;            // Return the popped value
    }
}

// Main function to demonstrate stack operations
int main() {
    // Push elements onto the stack
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    
    // Display the current stack
    linkedListTraversal(top);
    
    // Pop an element from the stack
    int element = pop(top);
    printf("Popped element is %d\n", element);
    
    // Display the stack after popping
    linkedListTraversal(top);
    
    return 0;
}
