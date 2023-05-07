/******************************************************************************
Write a program to convert binary number into decimal using
explicit stack.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    // Create a stack to hold binary digits
    struct Stack* stack = createStack(10);
    int decimal = 0;
    int i = 0;
    // Push binary digits onto the stack
    while (binary[i] != '\0') {
        push(stack, binary[i] - '0');
        i++;
    }
    // Pop binary digits from the stack and calculate decimal value
    int power = 0;
    while (!isEmpty(stack)) {
        int bit = pop(stack);
        decimal += bit * pow(2, power);
        power++;
    }
    return decimal;
}

int main() {
    char binary[] = "1010";
    int decimal = binaryToDecimal(binary);
    printf("Binary: %s\nDecimal: %d\n", binary, decimal);
    return 0;
}

