/******************************************************************************
Write a Program to create a Binary Tree and perform following
Nonrecursive operations on it. a. Inorder Traversal b. Preorder
Traversal c. Display Number of Leaf Nodes d. Mirror Image

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>

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
    struct StackNode* temp = *top;
    struct TreeNode* node = temp->node;
    *top = (*top)->next;
    free(temp);
    return node;
}

void inorderTraversal(struct TreeNode* root) {
    struct TreeNode* curr = root;
    struct StackNode* stack = NULL;

    while(curr || stack) {
        while(curr) {
            push(&stack, curr);
            curr = curr->left;
        }
        curr = pop(&stack);
        printf("%d ", curr->val);
        curr = curr->right;
    }
}

void preorderTraversal(struct TreeNode* root) {
    if(!root) return;

    struct TreeNode* curr = root;
    struct StackNode* stack = NULL;

    push(&stack, curr);

    while(stack) {
        curr = pop(&stack);
        printf("%d ", curr->val);
        if(curr->right) push(&stack, curr->right);
        if(curr->left) push(&stack, curr->left);
    }
}

int countLeafNodes(struct TreeNode* root) {
    if(!root) return 0;

    struct TreeNode* curr = root;
    struct StackNode* stack = NULL;
    int count = 0;

    push(&stack, curr);

    while(stack) {
        curr = pop(&stack);
        if(!curr->left && !curr->right) count++;
        if(curr->right) push(&stack, curr->right);
        if(curr->left) push(&stack, curr->left);
    }

    return count;
}

void mirrorImage(struct TreeNode* root) {
    if(!root) return;

    struct TreeNode* curr = root;
    struct StackNode* stack = NULL;

    push(&stack, curr);

    while(stack) {
        curr = pop(&stack);
        struct TreeNode* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        if(curr->right) push(&stack, curr->right);
        if(curr->left) push(&stack, curr->left);
    }
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    int leafNodes = countLeafNodes(root);
    printf("Number of Leaf Nodes: %d\n", leafNodes);
    printf("Mirror Image: ");
    mirrorImage(root);
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}

