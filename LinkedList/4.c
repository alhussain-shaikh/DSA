/*
Write an Append () function that takes two lists, 'a' and 'b',
appends 'b' onto the end of 'a', and then sets 'b' to NULL
(since it is now trailing off the end of 'a').
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *ptr;
} *temp , *new;


struct Node* insert(struct Node *first, int x){
    if(first==NULL){
        new = (struct Node*)malloc(sizeof(struct Node));
        new->data=x;
        new->ptr=NULL;
        return new;
    }
    else{
        new = (struct Node*)malloc(sizeof(struct Node));
        new->data=x;
        new->ptr=NULL;
        temp=first;
        while(temp->ptr!=NULL){
            temp=temp->ptr;
        }
        temp->ptr=new;
        return first;
    }
}

struct Node *append(struct Node *first, struct Node *second){
    temp=first;
    while(temp->ptr!=NULL){
        temp=temp->ptr;
    }
    temp->ptr=second;
    return first;
}

void printList(struct Node* first){
    
    temp=first;
    while(temp!=NULL){
        printf("[Current_node:%p data:%d Next_node%p]\n",temp,temp->data ,temp->ptr);
        temp=temp->ptr;
    }
    printf("\n");
}

int main()
{
    struct Node *a =NULL;
    int size,n;
    
    printf("Enter the size of a list:");
    
    scanf("%d",&size);
    printf("\nEnter the data for a list: ");
    for(int i = 0; i<size; i++){
        scanf("%d",&n);
        a = insert(a,n);
    }
    
    printList(a);
    
    struct Node *b = NULL;
    printf("\n Enter the size of b list:");
    
    scanf("%d",&size);
    printf("\nEnter the data for b list: ");
    for(int i = 0; i<size; i++){
        scanf("%d",&n);
        b = insert(b,n);
    }
    
    printList(b);
    
    a = append(a,b);
    
    printf("\nAfter appending \n");
    printList(a);
    b=NULL;
    printList(b);
    return 0;
}



