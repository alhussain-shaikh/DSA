/******************************************************************************
Write a program to illustrate operations on a BST holding numeric
keys. The menu must include: • Insert • Mirror Image • Find •
Post order (nonrecursive)
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    int flag ;
    struct node *left, *right;
};

// struct node *root = NULL;

struct stack {
    struct node* arr[100] ;
    int top ;
};


struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->flag = 0 ;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("  %d  ", root->key);
        inorder_traversal(root->right);
    }
}

void mirrorImage(struct node *node)
{
    if (node == NULL)
        return;
    else
    {
        struct node *temp;

        mirrorImage(node->left);
        mirrorImage(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void push(struct node *node , struct stack *st){
    if(st->top==100){
        printf("\nStackOverflow!!\n");
    }else{
        // printf("\nEntered into the push frame");
        st->arr[++st->top] = node ;
        // printf("\nExited from the push frame");

    }
}

struct node *pop(struct stack *st){
    if(st->top==-1){
        printf("\nUnderFlow!!\n");
    }else{
        return st->arr[st->top--];
    }
}

void postOrder(struct node *t , struct stack *st)
{
   while(1){
    // printf("\nEntered into the while loop\n");
        while(t!=NULL){
            // printf("\ndata %d is pushed into stack with flag : %d\n",t->key,t->flag);

             push(t,st);
            // printf("\ndata %d is pushed into stack with flag : %d\n",t->key,t->flag);

             t = t->left;
           
        }
    if(st->arr[st->top]->flag==1){
    // printf("\n Inside printing \n");
        
        if(st->top!=-1){
            t = pop(st);
            // printf("\nPopped data is %d",t->key);
            printf("..%d..",t->key);
            t = NULL ;
        }else{
            printf("\nSuccessfully Printed");
            break;
        }
    }else{
        // printf("\nstack top is : %d",st->arr[st->top]->key);
        if(st->arr[st->top]->right!=NULL){
        t = st->arr[st->top]->right ;
        }
        // printf("outer else flag of data %d ",st->arr[st->top]->key);
        st->arr[st->top]->flag = 1 ;
    }
   }
}

struct node* find(struct node *node, int data)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (data == node->key)
    {   
        // printf("\n.........compared the data with key and is equal.......\n");
        return node;
    }
    else if (data < node->key)
    {
        // printf("\n.........compared the data with key and is less.......\n");
        return find(node->left, data);
    }
    else{
    // {printf("\n.........compared the data with key and is more.......\n");
        return find(node->right, data);
    }
}

int main()
{

    struct node* root = NULL;
    int n, data;
    int temp;
    struct node *found_node = NULL ;
    int a;

    struct stack st ;
    st.top = -1 ;
    

    do
    {
        printf("\n\nEnter any choice : \n");
        printf("1.  Insert into BST\n");
        printf("2.  Find a Node in BST\n");
        printf("3.  Mirror Image of BST\n");
        printf("4.  Post Order Traversal non-recursive\n");
        printf("Enter your choice : ");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            printf("Enter the number of nodes in BST: ");
            scanf("%d", &n);

            printf("Enter the data for each node: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root = insert(root, data);
            }
            printf("\n Inorder Traversal of BST is : \n");
            inorder_traversal(root);
            printf("\nThe root node is %d : ",root->key);
            break;
        case 3:
            printf("\n Before Mirror image inorder Traversal : \n");
            inorder_traversal(root);
            mirrorImage(root);
            printf("\n After Mirror image inorder Traversal : \n");
            inorder_traversal(root);
            break;
        case 2:
            printf("\nEnter the value to find in BST : ");
            scanf("%d", &temp);
            found_node = find(root, temp);
            if (found_node == NULL)
            {
                printf("Node with value %d not found\n", temp);
            }
            else
            {
                printf("Node with value %d found at memory location %p\n", found_node->key, found_node);
            }
            break;
        case 4:
            postOrder(root,&st);
            break;

        default:
            break;
        }
    } while (1);

    return 0;
}
