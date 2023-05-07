/*
Question: WAP to merge two sorted Doubly linked lists and display the result.
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *ptr;
    struct node *qtr;
    int data;
};
void sortt(struct node *first)
{
    struct node *temp1 = first;
    while (temp1->ptr != NULL)
    {
        struct node *temp2 = temp1->ptr;
        struct node *min = temp1;
        while (temp2 != NULL)
        {
            if (min->data > temp2->data)
            {
                min = temp2;
            }
            temp2 = temp2->ptr;
        }
        if (min != temp1)
        {
            int tdata = temp1->data;
            temp1->data = min->data;
            min->data = tdata;
        }
        temp1 = temp1->ptr;
    }
}
struct node *merge(struct node *first, struct node *second)
{
    struct node *new = NULL;
    struct node *temp1 = first;
    struct node *temp2 = second;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            if (new == NULL)
            {
                new = temp2;
                temp2 = temp2->ptr;

                new->ptr = NULL;
                new->qtr = NULL;
            }
            else
            {
                struct node *t = new;
                while (t->ptr != NULL)
                {
                    t = t->ptr;
                }
                t->ptr = temp2;
                t->ptr->qtr = t;
                temp2 = temp2->ptr;
                t->ptr->ptr = NULL;
            }
        }
        else
        {
            if (new == NULL)
            {
                new = temp1;
                temp1 = temp1->ptr;
                new->ptr = NULL;
                new->qtr = NULL;
            }
            else
            {
                struct node *s = new;
                while (s->ptr != NULL)
                {
                    s = s->ptr;
                }
                s->ptr = temp1;
                s->ptr->qtr = s;
                temp1 = temp1->ptr;

                s->ptr->ptr = NULL;
            }
        }
    }
    struct node *temp3 = new;
    while (temp3->ptr != NULL)
    {
        temp3 = temp3->ptr;
    }
    if (temp1 != NULL)
    {
        while (temp1 != NULL)
        {
            temp3->ptr = temp1;
            temp1->qtr = temp3;
            temp3 = temp1;
            temp1 = temp1->ptr;
        }
    }
    else if (temp2 != NULL)
    {
        while (temp2 != NULL)
        {
            temp3->ptr = temp2;
            temp2->qtr = temp3;
            temp3 = temp2;
            temp2 = temp2->ptr;
        }
    }
    return new;
}
struct node *insert(struct node *first, int x)
{
    struct node *new = (struct node *)(malloc(sizeof(struct node)));
    if (first == NULL)
    {
        first = new;
        new->data = x;
        new->ptr = NULL;
        new->qtr = NULL;
    }
    else
    {
        struct node *temp = first;
        while (temp->ptr != NULL)
        {
            temp = temp->ptr;
        }
        temp->ptr = new;
        new->data = x;
        new->ptr = NULL;
        new->qtr = temp;
    }
    return first;
}
int main()
{
    int n, m;
    struct node *first = NULL;
    struct node *second = NULL;
    printf("Enter the length of first doubly linked list:");
    scanf("%d", &n);
    printf("Enter the elements of first doubly linked list:");
    for (int i = 0; i < n; i++)
    {
        int fdata;
        scanf("%d", &fdata);
        first = insert(first, fdata);
    }
    printf("Enter the length of second doubly linked list:");
    scanf("%d", &m);
    printf("Enter the elements of second doubly linked list:");
    for (int j = 0; j < m; j++)
    {
        int sdata;
        scanf("%d", &sdata);
        second = insert(second, sdata);
    }
    printf("Below is the sorted merged doubly Linked list\n");
    sortt(second);
    sortt(first);
    struct node *new = merge(first, second);
    struct node *temp = new;
    while (temp != NULL)
    {
        printf("data=%d previous Address=%p current address=%p next address=%p\n", temp->data, temp->qtr, temp, temp->ptr);
        temp = temp->ptr;
    }
    return 0;
}

