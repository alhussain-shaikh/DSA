
/*
WAP to perform addition of two polynomials using singly
linked list.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *link;
};
void print(struct node* head){
    if(head==NULL){
        printf("No polynomial.");
    }
    else{
        struct node* temp=head;
        while (temp!=NULL)
        {
            printf("%dx^%d",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL)
            printf(" +");
            else
            printf("\n");
            
        }
        int c=1;
        while(head!=NULL){
            
            printf("Address of node  %d is: %p \n",c,head);
            head=head->link;
            c++;
        }
        
    }
}
struct node* insert(struct node* head,int coeff,int expo){
    struct node* temp;
    struct node* newP= malloc(sizeof(struct node));
    newP->coeff=coeff;
    newP->expo=expo;
    newP->link=NULL;
    if(head==NULL || expo >head->expo){
        newP->link=head;
        head=newP;
    }
    else{
        temp=head;
        while(temp->link!=NULL && temp->link->expo >= expo){
            temp=temp->link;
        }
        newP->link=temp->link;
        temp->link=newP;
    }
    return head;
}


struct node* create(struct node* head){
    int n;
    printf("Enter number of terms:\n");
    scanf("%d",&n);
    int i,expo;
    int coeff;
    for(i=0;i<n;i++){
        printf("Enter the coefficient for term %d: ",i+1);
        scanf("%d",&coeff);
        printf("Enter the exponent of the  term %d: ",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head; 
}
void polyadd(struct node* head1,struct node* head2){
    struct node* head3=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->expo==head2->expo){
            head3=insert(head3,head1->coeff+head2->coeff,head1->expo);
            head1=head1->link;
            head2=head2->link;
        }
        else if(head1->expo > head2->expo){
             head3=insert(head3,head1->coeff,head1->expo);
             head1=head1->link;
             
        }
        else if(head1->expo < head2->expo){
            head3=insert(head3,head2->coeff,head2->expo);
            head2=head2->link;
            
        }
    }
    while(head1 != NULL){
        head3 = insert(head3,head1->coeff,head1->expo);
        head1=head1->link;
        
    }
    while(head2 != NULL){
        head3 = insert(head3,head2->coeff,head2->expo);
        head2=head2->link; 
    }
    printf("Added Polynomial is: ");
    print(head3);
}

int main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
printf("Enter the polynomial:\n");
head1=create(head1);//gives address of first node  
printf("Enter the polynomial:\n");
head2=create(head2);
polyadd(head1,head2);
    return 0;
}


