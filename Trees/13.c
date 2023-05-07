/******************************************************************************
Write a Program to create a Binary Search Tree and display its
mirror image with and without disturbing the original tree. Also
display height of a tree using nonrecursion.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void push(struct StackNode** top, struct TreeNode* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = *top;
    *top = stackNode;
}

struct TreeNode* pop(struct StackNode** top) {
    struct TreeNode* node = (*top)->node;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return node;
}

int isEmpty(struct StackNode* top) {
    return !top;
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
void inorderTraversal(struct TreeNode* root) {
    if(!root) return;

    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while(current || !isEmpty(stack)) {
        while(current) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->val);
        current = current->right;
    }
}

struct TreeNode* mirrorTree(struct TreeNode* root) {
    if(!root) return root;

    struct TreeNode* left = mirrorTree(root->left);
    struct TreeNode* right = mirrorTree(root->right);
    root->left = right;
    root->right = left;

    return root;
}
void mirror(struct TreeNode* head){
  struct TreeNode* temp;
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

// struct TreeNode* createMirrorTree(struct TreeNode* root) {
//     if(!root) return root;

//     struct TreeNode* newNode = createNode(root->val);
//     newNode->left = createMirrorTree(root->right);
//     newNode->right = createMirrorTree(root->left);

//     return newNode;
// }

// int height(struct TreeNode* root) {
//     if(!root) return 0;

//     struct StackNode* stack = NULL;
//     int maxHeight = 0;
//     struct TreeNode* current = root;
//     struct TreeNode* prev = NULL;

//     while(current || !isEmpty(stack)) {
//         while(current) {
//             push(&stack, current);
//             current = current->left;
//         }

//         current = pop(&stack);
//         if(!current->right || current->right == prev) {
//             if(stack == NULL) maxHeight++;
//             prev = current;
//             current = NULL;
//         } else {
//             push(&stack, current);
//             current = current->right;
//         }
//     }

//     return maxHeight;
// }

int main() {
    struct TreeNode* root = NULL;

    root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    printf("Inorder traversal: \n");
    display(root);
    printf("\n");

    printf("Mirror tree (original tree is not disturbed):\n ");
    mirror(root);
    // struct TreeNode* mirroredRoot = createMirrorTree(root);
    // inorderTraversal(mirroredRoot);
    display(root);
    printf("\n");

    printf("Mirror tree (original tree is disturbed): \n");
    mirror(root);
    display(root);
    printf("\n");
    printf("Height of the tree: %d\n", height(root));

    return 0;
    
}
    

