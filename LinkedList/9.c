/*
WAP to store at most 10 digit integer in a Doubly linked list
and perform arithmetic operations on it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 10

typedef struct node {
    int digit;
    struct node *prev;
    struct node *next;
} Node;

void insert(Node **head, int digit) {
    Node *new_node = malloc(sizeof(Node));
    new_node->digit = digit;
    new_node->prev = NULL;
    new_node->next = *head;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
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

Node *add_numbers(Node *num1, Node *num2) {
    Node *result = NULL;
    int carry = 0;
    while (num1 != NULL || num2 != NULL || carry != 0) {
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
        sum %= 10;
        insert(&result, sum);
    }
    return result;
}

Node *subtract_numbers(Node *num1, Node *num2) {
    Node *result = NULL;
    int borrow = 0;
    while (num1 != NULL) {
        int diff = num1->digit - borrow;
        if (num2 != NULL) {
            diff -= num2->digit;
            num2 = num2->next;
        }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        insert(&result, diff);
        num1 = num1->next;
    }
    while (result->next != NULL && result->digit == 0) {
        Node *temp = result;
        result = result->next;
        result->prev = NULL;
        free(temp);
    }
    return result;
}

int main() {
    char num1_str[MAX_DIGITS + 1];
    char num2_str[MAX_DIGITS + 1];
    printf("Enter two numbers (up to %d digits each): ", MAX_DIGITS);
    scanf("%s %s", num1_str, num2_str);
    Node *num1 = NULL;
    Node *num2 = NULL;
    int len1 = strlen(num1_str);
    int len2 = strlen(num2_str);
    for (int i = len1 - 1; i >= 0; i--) {
        insert(&num1, num1_str[i] - '0');
    }
    for (int i = len2 - 1; i >= 0; i--) {
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



