/*
WAP to find Max and Min. from set of elements using explicit
stack. Show the simulation of your program in output.
*/

#include <stdio.h>
struct stack
{
    int arr[100];
    int top;
};
struct stack s;
void push(int x)
{
    if (s.top >= 100)
    {
        printf("Stack overflow");
    }
    else
    {
        s.top++;
        s.arr[s.top] = x;
    }

}
int pop()
{
    if (s.top == -1)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return s.arr[s.top--];
    }
}
int top()
{
    if (s.top == -1)
    {
        return -1;
    }
    else
    {
        return s.arr[s.top];
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
    while (s.top != -1)
    {
        pop();
    }
}
void solve(struct stack s, int *min, int *max)
{
    if (empty())
    {
        return;
    }
    printf("The top element of the stack is %d\n", top());
    printf("Comparing the values of min and max variable with the top element of the stack\n");
    if (top() < *min)
    {
        printf("Changing the value of min variable which is %d to Top element of the stack%d\n", *min, top());
        *min = top();
    }
    if (top() > *max)
    {
        printf("Changing the value of max variable which is %d to Top element of the stack%d\n", *max, top());
        *max = top();
    }
    pop();
    solve(s, min, max);
}
int main()
{
    s.top = -1;
    int n;
    int brr[100];
    printf("Enter the total number of elements:\n ");
    scanf("%d", &n);
    printf("enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
            int temp1;
            scanf("%d", &temp1);
            brr[i] = temp1;
    }
    int min = brr[n - 1];
    int max = brr[n - 1];
    printf("Simulation of finding the minimum and maximum element:\n");
    printf("Pushing all the elements in th stack:\n");
    for (int i = 0; i < n; i++)
    {
        push(brr[i]);
    }
    solve(s, &min, &max);
    
    printf("the maximum element is:%d\n", max);
    printf("The minimum element is:%d\n", min);
}
