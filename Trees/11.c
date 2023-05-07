/******************************************************************************
Write a Program to create a Binary Search Tree and perform
deletion of a node from it. Also display the tree in nonrecursive
postorder way.

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
    struct StackNode* temp = *top;
    struct TreeNode* node = temp->node;
    *top = (*top)->next;
    free(temp);
    return node;
}

void postorderTraversal(struct TreeNode* root) {
    if(!root) return;

    struct TreeNode* curr = root;
    struct StackNode* stack = NULL;

    do {
        while(curr) {
            if(curr->right) push(&stack, curr->right);
            push(&stack, curr);
            curr = curr->left;
        }

        curr = pop(&stack);

        if(curr->right && stack && curr->right == stack->node) {
            pop(&stack);
            push(&stack, curr);
            curr = curr->right;
        } else {
            printf("%d ", curr->val);
            curr = NULL;
        }
    } while(stack);
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

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Deleting node with value 7\n");
    root = deleteNode(root, 7);

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

