/******************************************************************************
WAP to traverse the heap of the array elements using explicit
stack.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Define stack structure
struct Stack {
    int* data;
    int top;
};

// Function to create a stack
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->data = (int*) malloc(sizeof(int) * size);
    stack->top = -1;
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to traverse the heap of array elements
void traverseHeap(int* heap, int size) {
    // Create a stack to hold heap indices
    struct Stack* stack = createStack(size);
    // Push the root index onto the stack
    push(stack, 0);
    // Traverse the heap using the stack
    while (!isEmpty(stack)) {
        // Pop an index from the stack
        int index = pop(stack);
        // Print the value at the index
        printf("%d ", heap[index]);
        // Push the left child index onto the stack
        if (2*index+1 < size) {
            push(stack, 2*index+1);
        }
        // Push the right child index onto the stack
        if (2*index+2 < size) {
            push(stack, 2*index+2);
        }
    }
}

int main() {
    int heap[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(heap) / sizeof(heap[0]);
    traverseHeap(heap, size);
    return 0;
}

