/******************************************************************************
Write a program to illustrate operations on a BST holding
numeric keys. The menu must include: • Insert • Delete • Find •
Show

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;


Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}


Node *find(Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return find(root->left, data);
    }
    return find(root->right, data);
}


Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}



Node *delete(Node *root, int data)
{
    if (root == NULL)
    {
        // printf("root==NuLL \n");
        return root;
    }
    if (data < root->data)
    {
        // printf("Data < root\n");
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        
        // printf("Data > root\n");
        root->right = delete (root->right, data);
    }
    
       
    else if (root->left == NULL && root->right == NULL)
        {
            
            return root;
        }
  
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    
    return root;
}



void display(struct node *ptr)
{


    if (ptr != NULL)
    {
       display(ptr->left);
        printf("%d ", ptr->data); 
        display(ptr->right);
    }
}


int main()
{
    Node *root = NULL;
    int choice, data;


    while (choice != 5)
    {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Find\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("%d inserted successfully.\n", data);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = delete (root, data);
            printf("%d deleted successfully.\n", data);
            break;
        case 3:
            printf("Enter data to find: ");
            scanf("%d", &data);
            if (find(root, data) != NULL)
            {
                printf("%d found in the tree.\n", data);
            }
            else
            {
                printf("%d not found in the tree.\n", data);
            }
            break;
        case 4:
            printf("Elements in the BST (inorder): ");
            display(root);
            printf("\n");
            break;
       
 default:
            printf("INVALID INPUTT!!"); 
            break;
            ;
        }
    }
}

