/******************************************************************************

Write a Program to create a Binary Tree and perform following
nonrecursive operations on it. a. Preorder Traversal b.
Postorder Traversal c. Count total no. of nodes d. Display height
of a tree.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);
        if (node->right) 
            stack[++top] = node->right;
        if (node->left) 
            stack[++top] = node->left;
    }
}

void postorder(struct Node* root) {
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left) 
            stack1[++top1] = node->left;
        if (node->right) 
            stack1[++top1] = node->right;
    }
    while (top2 >= 0) {
    struct Node* node = stack2[top2--];
    printf("%d ", node->data);
    }
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    
    int count = 0;
    struct Node* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            count++;
            current = current->right;
        } 
        else {
            struct Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
                predecessor = predecessor->right;
            if (predecessor->right == NULL) {
                predecessor->right = current;
                count++;
                current = current->left;
            } 
            else {
        predecessor->right = NULL;
        current = current->right;
        }
        }
    }
    return count;
}

int height(struct Node* root) {
    if (root == NULL) return -1;
    int height = -1;
    struct Node* stack[100];
    int top = -1;
    int maxHeight = 0;
    struct Node* lastVisited = NULL;
    while (top >= 0 || root != NULL) {
    
        if (root != NULL) {
            stack[++top] = root;
            root = root->left;
        } else {
            struct Node* peekNode = stack[top];
            if (peekNode->right != NULL && lastVisited != peekNode->right) {
            root = peekNode->right;
        } else {
            if (top > maxHeight) maxHeight = top;
            lastVisited = stack[top--];
            }
        }
    }
    return maxHeight;
}

void printTree(struct Node* root, int space) {
    if (root == NULL) return;
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main() {
struct Node* root = NULL;

int n;
printf("Enter the number of elements: ");

scanf("%d", &n);
printf("Enter the elements: ");
for (int i = 0; i < n; i++) {
int data;
scanf("%d", &data);
if (root == NULL) root = createNode(data);
else {
struct Node* current = root;

while (1) {
if (data < current->data) {
if (current->left == NULL) {
current->left = createNode(data);
break;
} else current = current->left;
}
else {
if (current->right == NULL) {
current->right = createNode(data);
break;

} else current = current->right;
}
}
}

}

printf("\nPreorder Traversal: ");
preorder(root);

printf("\nPostorder Traversal: ");
postorder(root);

printf("\nTotal number of nodes: %d", countNodes(root));
printf("\nHeight of the tree: %d", height(root));
printf("\nBinary Tree:\n");
printTree(root, 0);

return 0;
}

