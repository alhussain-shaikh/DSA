/******************************************************************************
Write a Program to create a Binary Search Tree and perform
following nonrecursive operations on it. a. Preorder Traversal b.
Postorder Traversal c. Display total Number of Nodes d. Display
Leaf nodes.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *left;
    struct node *right;
    int flag;
};
struct stack
{
    struct node *arr[100];
    int top;
};
struct stack s;
struct node *top()
{
    if (s.top == -1)
    {
        return NULL;
    }
    else
    {
        return s.arr[s.top];
    }
}
void push(struct node *temp)
{
    if (s.top == 99)
    {
        return;
    }
    else
    {
        s.arr[++s.top] = temp;
    }
}
struct node *pop()
{
    if (s.top == -1)
    {
        return NULL;
    }
    else
    {
        return s.arr[s.top--];
    }
}
int empty()
{
    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void clear()
{
    if (s.top == -1)
    {
        return;
    }
    else
    {
        while (s.top != -1)
        {
            s.top--;
        }
    }
}

struct node *insert(struct node *root, int data)
{
    struct node *new = (struct node *)(malloc(sizeof(struct node)));
    new->flag = 0;
    if (root == NULL)
    {
        new->val = data;
        new->left = NULL;
        new->right = NULL;
        root = new;
        return root;
    }
    else
    {
        struct node *temp = root;
        while (1)
        {
            if (temp->val > data)
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                }
                else
                {
                    new->val = data;
                    new->left = NULL;
                    new->right = NULL;
                    temp->left = new;
                    return root;
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                }
                else
                {
                    new->val = data;
                    new->left = NULL;
                    new->right = NULL;
                    temp->right = new;
                    return root;
                }
            }
        }
    }
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct node *temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            printf("%d ", temp->val);
            if (temp->right != NULL)
            {
                push(temp->right);
            }
            temp = temp->left;
        }
        if (!empty())
        {
            temp = pop();
        }
        else
        {
            break;
        }
    }
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct node *temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            push(temp);
            temp = temp->left;
        }
        if (top()->flag == 1)
        {
            if (!empty())
            {
                temp = pop();
                printf("%d ", temp->val);
                temp = NULL;
            }
            if (empty())
            {
                break;
            }
        }
        else
        {
            top()->flag = 1;
            temp = top()->right;
        }
    }
}
int countNodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    push(root);
    int count = 0;
    while (!empty())
    {
        struct node *temp = pop();
        count++;
        if (temp->right != NULL)
        {
            push(temp->right);
        }
        if (temp->left != NULL)
        {
            push(temp->left);
        }
    }
    return count;
}
void LeafNodes(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct node *temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                printf("%d ", temp->val);
            }

            if (temp->right != NULL)
            {
                push(temp->right);
            }
            temp = temp->left;
        }
        if (!empty())
        {
            temp = pop();
        }
        else
        {
            break;
        }
    }
}
int main()
{
    s.top = -1;
    int n;
    printf("Enter the number of nodes in the BST:");
    scanf("%d", &n);
    printf("Enter the data of nodes:");
    struct node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Pre-Order Traversal:\n");
    preorder(root);
    clear();
    printf("\n");
    printf("Postorder Traversal:\n");
    postorder(root);
    clear();
    printf("\n");
    printf("The Number Of Nodes In the BST: %d", countNodes(root));
    printf("\n");
    clear();
    printf("The Leaf Nodes of the BST:\n");
    LeafNodes(root);
}

