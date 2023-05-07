/******************************************************************************
Write a Program to create a Binary Search Tree and perform
following nonrecursive operations on it. a. Inorder Traversal b.
Postorder Traversal c. Display Height of a tree d. Count total no.
of nodes

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct StackNode {
    struct Node *node;
    struct StackNode *next;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(struct StackNode **top, struct Node *node) {
    struct StackNode *newNode = (struct StackNode *) malloc(sizeof(struct StackNode));
    newNode->node = node;
    newNode->next = *top;
    *top = newNode;
}

struct Node *pop(struct StackNode **top) {
    struct Node *node = (*top)->node;
    struct StackNode *temp = *top;
    *top = (*top)->next;
    free(temp);
    return node;
}

int isEmpty(struct StackNode *top) {
    return top == NULL;
}

void inorderTraversal(struct Node *root) {
    struct StackNode *stack = NULL;
    struct Node *current = root;
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

void postorderTraversal(struct Node *root) {
    struct StackNode *stack1 = NULL;
    struct StackNode *stack2 = NULL;
    push(&stack1, root);
    while (!isEmpty(stack1)) {
        struct Node *current = pop(&stack1);
        push(&stack2, current);
        if (current->left != NULL) {
            push(&stack1, current->left);
        }
        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }
    while (!isEmpty(stack2)) {
        struct Node *current = pop(&stack2);
        printf("%d ", current->data);
    }
}

int height(struct Node *root) {
    int height = 0;
    struct StackNode *stack = NULL;
    struct Node *current = root;
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        if (current->right != NULL && current->right != root) {
            push(&stack, current);
            current = current->right;
        } else {
            if (current->right == root) {
                height++;
            }
            root = current;
            current = NULL;
        }
    }
    return height;
}

int countNodes(struct Node *root) {
    int count = 0;
    struct StackNode *stack = NULL;
    struct Node *current = root;
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
            count++;
        }
        current = pop(&stack);
        current = current->right;
    }
    return count;
}

int main() {
    struct Node *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);
    
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    printf("Height of tree: %d\n", height(root));
    
    printf("Total no. of nodes in tree: %d\n", countNodes(root));
    
    return 0;
    
}


