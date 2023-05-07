/*
Consider a CopyList() function that takes a list and returns a
complete copy of that list. One pointer can iterate over the
original list in the usual way. Two other pointers can keep
track of the new list: one head pointer, and one tail pointer
which always points to the last node in the new list.

*/

#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL");
}
 
// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    // allocate a new node in a heap and set its data
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
 
    // set the `.next` pointer of the new node to point to the current
    // first node of the list.
    newNode->next = *head;
 
    // change the head pointer to point to the new node, so it is
    // now the first node in the list.
    *head = newNode;
}
 
// Function takes a linked list and returns its complete copy
struct Node* copyList(struct Node* head)
{
    struct Node* current = head;    // used to iterate over the original list
    struct Node* newList = NULL;    // head of the new list
    struct Node* tail = NULL;       // point to the last node in a new list
 
    while (current != NULL)
    {
        // special case for the first new node
        if (newList == NULL)
        {
            newList = (struct Node*)malloc(sizeof(struct Node));
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        }
        else {
            tail->next = (struct Node*)malloc(sizeof(struct Node));
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }
        current = current->next;
    }
 
    return newList;
}
 
int main(void)
{
    // input keys
    int keys[] = {1, 2, 3, 4};
    int n = sizeof(keys)/sizeof(keys[0]);
 
    // points to the head node of the linked list
    struct Node* head = NULL;
 
    // construct a linked list
    for (int i = n-1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    // copy linked list
    struct Node* dup = copyList(head);
 
    // print duplicate linked list
    printList(dup);
 
    return 0;
}
