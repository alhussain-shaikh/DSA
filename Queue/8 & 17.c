/******************************************************************************
Write a C program to implement descending priority queue
using arrays.
*******************************************************************************/
#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heap_size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < heap_size && heap[left_child] > heap[largest]) {
        largest = left_child;
    }

    if (right_child < heap_size && heap[right_child] > heap[largest]) {
        largest = right_child;
    }

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

void insert(int value) {
    if (heap_size == MAX_SIZE) {
        printf("Overflow: Could not insert value %d\n", value);
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

int extract_max() {
    if (heap_size == 0) {
        printf("Underflow: Could not extract max\n");
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size--;
    heapify(0);
    return max;
}

void display() {
    printf("Descending priority queue: ");
    for (int i = 0; i < heap_size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    display();

    printf("Extracted max: %d\n", extract_max());

    display();

    printf("Extracted max: %d\n", extract_max());

    display();

    printf("Extracted max: %d\n", extract_max());

    display();

    return 0;
}

