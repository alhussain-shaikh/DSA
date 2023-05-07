/******************************************************************************
WAP to store k keys into an array of size n at the location
computed using a hash function, loc = key / n, where k<=n and k
takes values from [1 to m], m>n. To handle the collisions use the
following collision resolution techniques, a. Linear probing with
chaining with replacement b. Quadratic probing technique.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int val[30];
int check[30];
int chain[30];
int N;
int probbing = 1;
int hash(int key)
{
    return key % N;
}
int insert(int x)
{
    int temp1;
    int cnt = 0;
    int i, j;
    temp1 = hash(x);
    if (probbing == 0)
    {
        if (check[temp1] == 0)
        {
            val[temp1] = x;
            check[temp1] = 1;
        }
        else if (val[temp1] % N == x % N)
        {
            j = temp1;
            while (check[j] == 1 && cnt < N)
            {
                j = (j + 1) % N;
                cnt++;
            }
            if (cnt == N)
            {
                printf("Hash Table is Full\n");
                return 0;
            }
            while (chain[temp1] != -1)
            {
                temp1 = chain[temp1];
            }
            val[j] = x;
            check[j] = 1;
            chain[temp1] = j;
        }
        else
        {
            j = temp1;
            cnt = 0;
            while (check[j] == 1 && cnt < N)
            {
                j = (j + 1) % N;
                cnt++;
            }
            if (cnt == N)
            {
                printf("Hash Table is Full\n");
                return 0;
            }
            i = val[temp1] % N;
            while (chain[i] != temp1)
            {
                i = chain[i];
            }
            chain[i] = chain[temp1];
            while (chain[i] != -1)
            {
                i = chain[i];
            }
            val[j] = val[temp1];
            check[j] = 1;
            chain[i] = j;
            val[temp1] = x;
            chain[temp1] = -1;
        }
    }
    else if (probbing == 1)
    {
        if (check[temp1] == 0)
        {
            val[temp1] = x;
            check[temp1] = 1;
        }
        else if (val[temp1] % N == x % N)
        {
            j = temp1;
            int temp2 = 1;
            while (check[j] == 1 && cnt < N)
            {
                j = (j + temp2 * temp2) % N;
                cnt++;
                temp2++;
            }
            if (cnt == N)
            {
                printf("Hash Table is Full\n");
                return 0;
            }
            while (chain[temp1] != -1)
            {
                temp1 = chain[temp1];
            }
            val[j] = x;
            check[j] = 1;
            chain[temp1] = j;
        }
        else
        {
            j = temp1;
            cnt = 0;
            int temp2 = 1;
            while (check[j] == 1 && cnt < N)
            {
                j = (j + temp2 * temp2) % N;
                cnt++;
                temp2++;
            }
            if (cnt == N)
            {
                printf("Hash Table is Full\n");
                return 0;
            }
            i = val[temp1] % N;
            while (chain[i] != temp1)
            {
                i = chain[i];
            }
            chain[i] = chain[temp1];
            while (chain[i] != -1)
            {
                i = chain[i];
            }
            val[j] = val[temp1];
            check[j] = 1;
            chain[i] = j;
            val[temp1] = x;
            chain[temp1] = -1;
        }
    }
    return 0;
}

void display()
{

    for (int i = 0; i < N; i++)
    {
        if (check[i] == 1)
        {
            printf("%d %d %d\n", i, val[i], chain[i]);
        }
        else
        {
            printf("%d -1 %d\n", i, chain[i]);
        }
    }
}

int main()
{
    int menu;
    printf("Enter the size of Hash Table: \n");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        check[i] = 0;
        chain[i] = -1;
    }
    printf("enter the Type of probbing 0.Linear Probbing 1.Quadratic Probbing:");
    scanf("%d", &probbing);
    while (1)
    {
        printf("\n Select an option 1. Insert key into the hash table\n 2.Print hash table \n 3. Exit \n");
        scanf("%d", &menu);
        if (menu == 1)
        {
            int key;
            printf("Enter the key to be inserted:");
            scanf("%d", &key);
            insert(key);
        }
        else if (menu == 2)
        {
            display();
        }
        else
        {
            break;
        }
    }
}

