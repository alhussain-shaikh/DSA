/******************************************************************************

Write a Program to create a Binary Tree and perform following
Nonrecursive operations on it. a. Inorder Traversal b. Preorder
Traversal c. Display Height of a tree d. Find Maximum

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
struct Node{
 struct Node *rptr;
 struct Node *lptr;
 int data;
 };
 int maxi(int a, int b){
 if(a>b)
    return a;
 else
    return b;
 }
 struct stack{
int top;
struct Node* add[30];
};
struct stack s;
void push(struct Node* a){
s.top ++;
s.add[s.top] = a;
if(s.top > 30){
    printf("stack is over flowing");
}

}
struct Node* pop() {
 if(s.top == 0)
    printf("stack is empty");
struct Node* x = s.add[s.top];
 s.top -- ;
    return x;
 }

struct Node* newNode(int num) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    temp->lptr = NULL;
    temp->lptr = NULL;
    return temp;
}
struct Node* buildTree(struct Node* root){
    printf("\n Enter the data if Null then enter -1 : ");
    int data;
    scanf("%d",&data);
    root = newNode(data);
    if(data == -1){
        return NULL;
    }
    printf("Enter the data for inserting in left of %d",data);
    root->lptr=buildTree(root->lptr);
    printf("Enter the data for inserting in right of %d",data);
    root->rptr=buildTree(root->rptr);

return root;
}
void preorder(struct Node* t){
while(1){
    while(t != NULL){
        printf(" %d ",t->data);
            if(t ->rptr != NULL)
                push(t ->rptr);
        t = t->lptr;
    }
    if(s.top != 0)
        t = pop();
    else
        break;


    }
}

void inorder(struct Node* t){
while(1){
    while(t != NULL){
              push(t);
        t = t->lptr;
    }
    if(s.top != 0){
        t = pop();
        printf(" %d ",t->data);
        t = t->rptr;
    }
    else
        break;


    }
}
int hieght(struct Node* t){
    int ldept = 0;
    int rdept = 0;
if( t == NULL)
    return 0;
else{
    ldept = hieght(t ->lptr );
    rdept = hieght(t ->rptr);
}
    if(ldept > rdept)
        return ldept+1;
    else
        return rdept+1;


}
int maximum(struct Node* t){
     int max = INT_MIN;
while(1){
    while(t != NULL){
            max = maxi(t ->data , max);
            if(t ->rptr != NULL)
                push(t ->rptr);
        t = t->lptr;
    }
    if(s.top != 0)
        t = pop();
    else
        break;


    }

        return max;
}


int main(){
    s.top = -1;
    s.top ++;
    struct Node *root = NULL;
    root = buildTree(NULL);
    printf("\n preorder traversal is: \n");
    preorder(root);
    printf("\n Inorder traversal is: \n");
    inorder(root);
    printf("\n Height of the tree is : %d", hieght(root));
    printf("\n Maximum number in tree is : %d", maximum(root));

return 0;
}
