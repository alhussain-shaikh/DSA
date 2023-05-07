/*
WAP to store at most 10 digit integer in a Singly linked list
and perform arithmetic operations on it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 10

typedef struct node {
    int digit;
    struct node *next;
} Node;

void insert(Node **head, int digit) {
    Node *new_node = malloc(sizeof(Node));
    new_node->digit = digit;
    new_node->next = *head;
    *head = new_node;
}

void print_number(Node *head) {
    while (head != NULL) {
        printf("%d", head->digit);
        head = head->next;
    }
    printf("\n");
}

void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

Node *reverse_list(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *add_numbers(Node *num1, Node *num2) {
    Node *result = NULL;
    int carry = 0;
    while (num1 != NULL || num2 != NULL) {
        int sum = carry;
        if (num1 != NULL) {
            sum += num1->digit;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            sum += num2->digit;
            num2 = num2->next;
        }
        carry = sum / 10;
        insert(&result, sum % 10);
    }
    if (carry > 0) {
        insert(&result, carry);
    }
    return reverse_list(result);
}

Node *subtract_numbers(Node *num1, Node *num2) {
    Node *result = NULL;
    int borrow = 0;
    while (num1 != NULL || num2 != NULL) {
        int diff = borrow;
        if (num1 != NULL) {
            diff += num1->digit;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            diff -= num2->digit;
            num2 = num2->next;
        }
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        insert(&result, diff);
    }
    while (result->digit == 0 && result->next != NULL) {
        Node *temp = result;
        result = result->next;
        free(temp);
    }
    return reverse_list(result);
}

int main() {
    char num1_str[MAX_DIGITS + 1], num2_str[MAX_DIGITS + 1];
    printf("Enter the first number (up to %d digits): ", MAX_DIGITS);
    scanf("%s", num1_str);
    printf("Enter the second number (up to %d digits): ", MAX_DIGITS);
    scanf("%s", num2_str);
    Node *num1 = NULL;
    Node *num2 = NULL;
    int len1 = strlen(num1_str);
    int len2 = strlen(num2_str);
    for (int i = len1 - 1; i >= 0; i--) {
        insert(&num1, num1_str[i] - '0');
    }
    for(int i = len2 - 1; i >= 0; i--) {
        insert(&num2, num2_str[i] - '0');
    }
    printf("Num1: ");
    print_number(num1);
    printf("Num2: ");
    print_number(num2);
    Node *sum = add_numbers(num1, num2);
    printf("Sum: ");
    print_number(sum);
    Node *diff = subtract_numbers(num1, num2);
    printf("Difference: ");
    print_number(diff);
    free_list(num1);
    free_list(num2);
    free_list(sum);
    free_list(diff);
    return 0;
    
}



