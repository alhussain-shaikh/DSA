/*
Write an iterative Reverse () function that reverses a list by
rearranging all the .next pointers and the head pointer.
Ideally, Reverse () should only need to make one pass of the
list.
*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int number;
    struct Node *next;

};
struct Node *first = NULL;
struct Node *new1;
void printList(struct Node* n)
{
    while (n!= NULL) {
        printf("[%p, %d,  %p]   ",n, n->number, n->next);
        n = n->next;
    }
     printf("\n");

}
struct node* reverse(struct Node* first)
{
    struct Node* x = NULL;
    struct Node* y = first;
    struct Node* z = first->next;
    while (y != NULL) {
        y ->next = x;
        x = y;
        y = z;
        if(z != NULL){
        z = z ->next;
        }

    }
     first = x;
     return x;
}
struct Node* insert(struct Node *first,int num){
    if (first ==  NULL){
        new1 = (struct Node*) malloc(sizeof(struct Node));
        new1 -> number = num;
        new1-> next = NULL;
        first = new1;
             }
    else{
        new1 = (struct Node*) malloc(sizeof(struct Node));
        new1->number = num;
        new1 -> next = NULL;
        struct Node *temp = first;
        while(temp->next != NULL){
            temp =  temp -> next;
        }
    temp -> next = new1;
    }
    return first;
}

int main(){
    int n, size, i ;
    printf("Enter the size: ");
    scanf("%d",&size);
printf("\nEnter the numbers: ");
    for(i = 0; i < size ; i++){
        scanf("%d",&n);
        first = insert(first, n);
    }
    printf("list before reverse \n");
    printList(first);
    first = reverse(first);
    printf("list after reverse \n");
    printList(first);
    return 0;
}

