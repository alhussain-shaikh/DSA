/******************************************************************************

Write a Program to create a Binary Tree and perform following
nonrecursive operations on it. a. Levelwise display b. Mirror
image c. Display height of a tree.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* left;
  struct node* right;
};
struct node* newnode(int data){
  struct node* new = malloc(sizeof(struct node));
  new->data = data;
  new->left = new->right = NULL;
  return new;
}

void printlevel(struct node* head, int n, int space){
  if(head != NULL){
    if(n == 1){
        for(int i=0;i<space;i++){
        printf(" ");
        }
        printf("%d\t",head->data);
        return;
    }
    else if (n>1){
        printlevel(head->left, n-1, space-n);
        printlevel(head->right, n-1, space-n);
    }
  
  }
  
}
int height(struct node* head){
  if(head == NULL)
    return 0;
  else{
    int lheight = height(head->left);
    int rheight = height(head->right);
    if(lheight > rheight)
      return (lheight+1);
    else
      return (rheight+1);
  }
}
void display(struct node* head){
  if(head == NULL)
    return;
  else{
    for(int i=1;i<=height(head);i++){
      int a=15-i*2;
      printf("Level %d: ",i);
      printlevel(head, i, a);
      printf("\n");
    }
  }
  printf("\n");
}

void mirror(struct node* head){
  struct node* temp;
  if(head == NULL){
    return;
  }
  else{
    mirror(head->left);
    mirror(head->right);
    temp = head->left;
    head->left = head->right;
    head->right = temp;
  }
}
int main(){
    
    struct node *root = newnode(1); 
	root->left	 = newnode(2); 
	root->right	 = newnode(3); 
	root->left->left = newnode(4);
	
	root->left->right = newnode(5); 
    root->right->left = newnode(6);
    root->right->right = newnode(7);
//  	root->left->left->right=newnode(9);
//     root->left->right->left =newnode(10);
// 	root->left->right->right=newnode(11);
	
  
  printf("Level Wise display \n");
  display(root);
  
  printf("Mirror node\n");
  mirror(root);
  
  
  display(root);
  int n=height(root);
  printf("Height of node = %d\n\n",n);
  return 0;
}

