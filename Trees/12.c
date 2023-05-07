/******************************************************************************

Write a Program to create a Binary Search Tree and display it
levelwise. Also perform deletion of a node from it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void enqueue(struct QueueNode** rear, struct TreeNode* node) {
    struct QueueNode* queueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    queueNode->node = node;
    queueNode->next = NULL;
    if(!*rear) *rear = queueNode;
    else {
        (*rear)->next = queueNode;
        *rear = queueNode;
    }
}

struct TreeNode* dequeue(struct QueueNode** front) {
    struct QueueNode* temp = *front;
    struct TreeNode* node = temp->node;
    *front = (*front)->next;
    free(temp);
    return node;
}

void printlevel(struct TreeNode* head, int n, int space){
  if(head != NULL){
    if(n == 1){
        for(int i=0;i<space;i++){
        printf(" ");
        }
        printf("%d\t",head->val);
        return;
    }
    else if (n>1){
        printlevel(head->left, n-1, space-n);
        printlevel(head->right, n-1, space-n);
    }
  
  }
  
}
int height(struct TreeNode* head){
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
void display(struct TreeNode* head){
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

struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while(current && current->left) current = current->left;
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(!root) return root;

    if(key < root->val) root->left = deleteNode(root->left, key);
    else if(key > root->val) root->right = deleteNode(root->right, key);
    else {
        if(!root->left) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if(!root->right) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}

int main() {
    struct TreeNode* root = NULL;

    root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    printf("Levelwise Display: \n");
    display(root);
    printf("\n");

    printf("Deleting node with value 7\n");
    root = deleteNode(root, 7);

    printf("Levelwise Display:\n ");
    display(root);
    printf("\n");

    return 0;
}

