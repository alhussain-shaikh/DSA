/*
Given a list, split it into two sublists — one for the front half,
and one for the back half. If the number of elements is odd,
the extra element should go in the front list. So
FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two
lists {2, 3, 5} and {7, 11}. Getting this right for all the cases is
harder than it looks. You should check your solution against
a few cases (length = 2, length = 3, length=4) to make sure
that the list gets split correctly near the short-list boundary
conditions. If it works right for length=4, it probably works
right for length=1000. You will probably need special case
code to deal with the (length <2) cases.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *ptr;
};

struct node *list = NULL;
struct node *left = NULL;
struct node *right = NULL;

void insert(int data) {
   struct node *new = (struct node*) malloc(sizeof(struct node));
   struct node *current;


   new->data = data;
   new->ptr = NULL;

   if(list == NULL) {
      list = new;
      return;
   }
   current = list;
   
   while(current->ptr!=NULL) { 
      current = current->ptr; 
      }
   current->ptr = new; 
}

void display(struct node *head) {
   struct node *tmp = head;

   while(tmp != NULL) {    
      printf(" %d -->",tmp->data);
      // printf("Current node address [ %d ] pointer pointing to next address [ %d ] \n",&tmp->data,tmp->ptr);
      tmp = tmp->ptr;
   }
   printf("NULL");
}

void splitList(struct node *list, struct node **left, struct node **right , int len){
    if(len<2){
      *left = list ;
      *right = NULL ;
      return ;
    }

    struct node* current = list;
 
    int traverseCount = (len - 1) / 2;   
    for (int i = 0; i < traverseCount; i++) {
        current = current->ptr;
    }

    *left = list;
    *right = current->ptr;
    current->ptr = NULL;
   
}

int main() {
   int inp ;
   int val ;

   printf("Enter the number of Records : ");
   scanf("%d",&inp);

   for(int i = 0; i < inp; i++) {
    printf("Enter elements to be inserted in list at %d index : ",i);
    scanf("%d",&val);
    insert(val);
    }

   printf("Complete list: \n");
   display(list);

   splitList(list,&left,&right,inp);

   printf("\nLeft List : ");
   display(left);
   printf("\nRight List : ");
   display(right);
}

