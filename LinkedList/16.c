/*
Write a RemoveDuplicates()
function which takes a list sorted in increasing
order and deletes any duplicate nodes from the list.
*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;
void sortList(struct Node *head)
{
    struct Node *current;
    int temp;
    int swapped;
    do
    {
        swapped = 0;
        current = head;
        while (current->next != NULL)
        {
            if (current->data > current->next->data)
            {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    }while (swapped);
}
void removeDuplicates(struct Node *head)
{
    struct Node *current = head;
    struct Node *next_next;
    if (current == NULL)
        return;
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}
void insert(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (head == NULL)
    {
    head = newNode;
    printf("Inserted node at address %p as head node.\n", head);
    printf("\n");
    }
    else
    {
    struct Node *current = head;
    while (current->next != NULL)
    {
    current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    printf("Inserted node with value %d at address %p.\n", data, newNode);
    printf("Previous node is at address %p.\n", current);
    printf("Next node is at address %p.\n", newNode->next);
    printf("\n");
    }
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d\t", node->data);
        node = node->next;
        printf("\n");
    }
}
void printlist(struct Node *node)
{
    while (node != NULL)
    {
        printf("\nPrevious node is at address %p \n", node->prev);
        printf("\nNode with value %d is at address %p \n",node->data, node);
        printf("\nNext node is at address %p \n", node->next);
        node = node->next;
        printf("\n");
    
    }
}
int main()
{
    int n, x;
    printf("Enter the number of nodes to be inserted: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &x);
    insert(x);
    }
    printf("Before Sorting\n");
    printList(head);
    printf("After Sorting\n");
    sortList(head);
    printList(head);
    printf("After Removing Duplicates\n");
    removeDuplicates(head);
    printlist(head);
    return 0;
}
