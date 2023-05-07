/******************************************************************************
A person is living in house having five rooms. These rooms are
adjacent to each other. There is a treasure which is electronically
locked and to unlock it we need a code. In fifth room there is a
box in which decimal number is written. We need to convert
that number into binary to open treasure which is kept in first
room. We need to move from room no. 1 to 2 to 3 and so on and
follow the reverse way to come back i.e. from 5 to 4 to 3 etc.
Apply suitable logic to implement this scenario using stack.

*******************************************************************************/

#include <stdio.h>
#define size 5
int array[size];
int top = -1;
int binaryArray[32];
int binaryNumber[32];
int ind = 0;

void push()
{
    int x;

    if (top == size - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top++;
        array[top] = x;
    }
}

void show()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else if (top == 4)
    {
          dtob(array[top]);
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", array[i]);
    }
}

void dtob(int n)
{
    if (n != 0)
    {
        binaryArray[ind++] = n % 2;
        dtob(n / 2);
    }
}

void pop()
{

    while (top != 0)
    {
        printf("\nPopped element: %d", array[top]);
        top--;
    }

    printf("\nIn The Room 1 Treasure is Unlocked !!!!");
}

int main()
{

    printf("\nWelcome to Treasure HUNT !!!.......\n\n");

    for (int i = 0; i < 5; i++)
    {
        push();
    }

    show();

    int numIndex = 0;

    for (int i = ind - 1; i >= 0; i--)
    {
        binaryNumber[numIndex++] = binaryArray[i];
    }
    for (int i = 0; i < numIndex; i++)
    {
        printf("%d", binaryNumber[i]);
    }
    printf("\n");

    pop();

    return 0;
}
