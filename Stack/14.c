/******************************************************************************
Write a program to implement multiple stack i.e. two stacks
using array and perform following operations ion it. A. Push, B.
Pop, C. StackFull, D. StackEmpty, E. Display full stack, F. Display
selected Stack

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Global variables for two stacks
int stack[MAX_SIZE];
int top1 = -1, top2 = MAX_SIZE;

// Function to check if stack 1 is full
int isStack1Full() {
    return (top1 == top2 - 1);
}

// Function to check if stack 2 is full
int isStack2Full() {
    return (top2 == top1 + 1);
}

// Function to check if stack 1 is empty
int isStack1Empty() {
    return (top1 == -1);
}

// Function to check if stack 2 is empty
int isStack2Empty() {
    return (top2 == MAX_SIZE);
}

// Function to push an element into stack 1
void pushStack1(int data) {
    if (isStack1Full()) {
        printf("Error: Stack 1 is full\n");
        return;
    }
    stack[++top1] = data;
}

// Function to push an element into stack 2
void pushStack2(int data) {
    if (isStack2Full()) {
        printf("Error: Stack 2 is full\n");
        return;
    }
    stack[--top2] = data;
}

// Function to pop an element from stack 1
int popStack1() {
    if (isStack1Empty()) {
        printf("Error: Stack 1 is empty\n");
        return -1;
    }
    return stack[top1--];
}

// Function to pop an element from stack 2
int popStack2() {
    if (isStack2Empty()) {
        printf("Error: Stack 2 is empty\n");
        return -1;
    }
    return stack[top2++];
}

// Function to display the entire stack
void displayStack() {
    printf("Stack 1: ");
    for (int i = top1; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");

    printf("Stack 2: ");
    for (int i = top2; i < MAX_SIZE; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

// Function to display the selected stack
void displaySelectedStack(int choice) {
    if (choice == 1) {
        printf("Stack 1: ");
        for (int i = top1; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    } else if (choice == 2) {
        printf("Stack 2: ");
        for (int i = top2; i < MAX_SIZE; i++)
            printf("%d ", stack[i]);
        printf("\n");
    } else {
        printf("Error: Invalid choice\n");
    }
}

// Main function
int main() {
    int choice, data, selectedStack;

    while (1) {
        printf("Select an operation:\n");
        printf("1. Push into Stack 1\n");
        printf("2. Push into Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Check if Stack 1 is full\n");
        printf("6. Check if Stack 2 is full\n");
        printf("7. Check if Stack 1 is empty\n");
        printf("8. Check if Stack 2 is empty\n");
        printf("9. Display entire stack\n");
        printf("10. Display selected stack\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the Element to be push in stack 1 ");
                scanf("%d",&data);
                pushStack1(data);
                break;
            case 2:
                printf("Enter the Element to be push in stack 2 ");
                scanf("%d",&data);
                pushStack2(data);
                break;
            case 3:
                popStack1();
                break;
            case 4:
                popStack2();
                break;
            case 5:
                isStack1Full();
                break;
            case 6:
                isStack2Full();
                break;
            case 7:
                isStack1Empty();
                break;
            case 8:
                isStack2Empty();
                break;
            case 9:
                displayStack();
                break;
            case 10:
                printf("Choose the following\n1.For Stack 1\n2. For Stack 2\n");
                int choose;
                scanf("%d",&choose);
                if(choose==1){
                    displaySelectedStack(1);
                    break;
                }else{
                    displaySelectedStack(2);
                    break;
                }
        }
    }
    
}

