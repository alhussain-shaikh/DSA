/******************************************************************************
This program now includes the implementation of Bubble Sort, Quick Sort, Insertion Sort, 
Merge Sort, Selection Sort, and Heap Sort & Bucket on the array of Student structures, 
with the number of swaps performed for each sorting algorithm being counted 
and printed to the console.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10

// Student structure
struct Student {
    char student_name[50];
    int student_roll_no;
    float total_marks;
};

typedef struct node {
    struct Student data;
    struct node* next;
} Node;

void insertion(Node* bucket) {
    if (!bucket) {
        return;
    }
    Node *i, *j;
    for (i = bucket->next; i != NULL; i = i->next) {
        struct Student temp = i->data;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data.total_marks < temp.total_marks) {
                temp = j->data;
            }
        }
        if (temp.total_marks != i->data.total_marks) {
            i->data = temp;
        }
    }
}

void bucketSort(struct Student arr[], int n) {
    int i, j;
    Node* buckets[BUCKET_SIZE];
    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }
    for (i = 0; i < n; i++) {
        int bucket_index = (int) (arr[i].total_marks / BUCKET_SIZE);
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = arr[i];
        new_node->next = buckets[bucket_index];
        buckets[bucket_index] = new_node;
    }
    for (i = 0; i < BUCKET_SIZE; i++) {
        insertion(buckets[i]);
    }
    int index = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        Node* node = buckets[i];
        while (node) {
            arr[index++] = node->data;
            node = node->next;
        }
    }
    for (i = 0; i < BUCKET_SIZE; i++) {
        Node* node = buckets[i];
        while (node) {
            Node* next_node = node->next;
            free(node);
            node = next_node;
        }
    }
}

// Bubble Sort function
int bubbleSort(struct Student arr[], int n) {
    int i, j, count = 0;
    struct Student temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].student_roll_no > arr[j+1].student_roll_no) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    }
    return count;
}

// Quick Sort function
int quickSort(struct Student arr[], int low, int high) {
    int i, j, count = 0;
    struct Student pivot, temp;
    if (low < high) {
        pivot = arr[high];
        i = low - 1;
        for (j = low; j <= high-1; j++) {
            if (arr[j].student_roll_no < pivot.student_roll_no) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                count++;
            }
        }
        temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        count++;
        int pi = i+1;
        count += quickSort(arr, low, pi-1);
        count += quickSort(arr, pi+1, high);
    }
    return count;
}
int insertionSort(struct Student arr[], int n) {
    int i, j, count = 0;
    struct Student key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].student_roll_no > key.student_roll_no) {
            arr[j+1] = arr[j];
            j = j - 1;
            count++;
        }
        arr[j+1] = key;
    }
    return count;
}

// Merge Sort function
void merge(struct Student arr[], int l, int m, int r, int *count) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    struct Student L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].student_roll_no <= R[j].student_roll_no) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            (*count) += n1 - i;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Student arr[], int l, int r, int *count) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }
}
void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(struct Student arr[], int n, int* count) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j].student_roll_no < arr[min_idx].student_roll_no) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
            (*count)++;
        }
    }
}

void heapify(struct Student arr[], int n, int i, int* count) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left].student_roll_no > arr[largest].student_roll_no) {
        largest = left;
    }

    if (right < n && arr[right].student_roll_no > arr[largest].student_roll_no) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        (*count)++;
        heapify(arr, n, largest, count);
    }
}

void heapSort(struct Student arr[], int n, int* count) {
    int i;
    for (i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i, count);
    }
    for (i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        (*count)++;
        heapify(arr, i, 0, count);
    }
}

int main() {
    int n, i, count;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student arr[n];
    for (i = 0; i < n; i++) {
        printf("Enter the details of student %d:\n", i+1);
        printf("Name: ");
        gets(arr[i].student_name);
        gets(arr[i].student_name);
        //scanf("%s", arr[i].student_name);
        printf("Roll Number: ");
        scanf("%d", &arr[i].student_roll_no);
        printf("Total Marks: ");
        scanf("%f", &arr[i].total_marks);
    }
    // Copying the array for Quick Sort
    struct Student arr_copy[n];
    struct Student arr_merge[n];
    struct Student arr_insertion[n];
    struct Student arr_selection[n];
    struct Student arr_heap[n];
    struct Student arr_bucket[n];
    memcpy(arr_merge,arr,sizeof(arr));
    memcpy(arr_copy, arr, sizeof(arr));
    memcpy(arr_insertion, arr, sizeof(arr));
    memcpy(arr_selection, arr, sizeof(arr));
    memcpy(arr_heap, arr, sizeof(arr));
    memcpy(arr_bucket, arr, sizeof(arr));
    
    // Bubble Sort
    count = bubbleSort(arr, n);
    printf("Sorted array using Bubble Sort:\n");
    printf("Roll No.\tName\t\tTotal Marks\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%.2f\n", arr[i].student_roll_no, arr[i].student_name, arr[i].total_marks);
    }
    printf("Number of swaps performed: %d\n", count);
    
    // Quick Sort
    count = quickSort(arr_copy, 0, n-1);
    printf("\nSorted array using Quick Sort:\n");
    printf("Roll No.\tName\t\tTotal Marks\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%.2f\n", arr_copy[i].student_roll_no, arr_copy[i].student_name, arr_copy[i].total_marks);
    }
    printf("Number of swaps performed: %d\n", count);
    
    // Insertion Sort
    count = insertionSort(arr_insertion, n);
    printf("Sorted array using Insertion Sort:\n");
    printf("Roll No.\tName\t\tTotal Marks\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%.2f\n", arr_insertion[i].student_roll_no, arr_insertion[i].student_name, arr_insertion[i].total_marks);
    }
    printf("Number of swaps performed using Insertion Sort: %d\n", count);
    
    // Merge Sort
    count = 0;
    mergeSort(arr_merge, 0, n-1, &count);
    printf("Sorted array using Merge Sort:\n");
    printf("Roll No.\tName\t\tTotal Marks\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%.2f\n", arr_merge[i].student_roll_no, arr_merge[i].student_name, arr_merge[i].total_marks);
    }
    printf("Number of swaps performed using Merge Sort: %d\n", count);
    
    // Selection Sort
    count = 0;
    selectionSort(arr_selection, n, &count);
    printf("Sorted array using Selection Sort:\n");
    printf("Roll No.\tName\t\tTotal Marks\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%.2f\n", arr_selection[i].student_roll_no, arr_selection[i].student_name, arr_selection[i].total_marks);
    }
    printf("Number of swaps performed using Selection Sort: %d\n", count);
    
    // Heap Sort
    count = 0;
    heapSort(arr_heap, n, &count);
    printf("Sorted array using Heap Sort:\n");
    printf("Roll No.\tName\t\tTotal Marks\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%.2f\n", arr_heap[i].student_roll_no, arr_heap[i].student_name, arr_heap[i].total_marks);
    }
    printf("Number of swaps performed using Heap Sort: %d\n", count);
    
    //Bucket sort
    bucketSort(arr_bucket, n);
    printf("Sorted array using Bucket Sort:\n");
    printf("Roll No.\tName\t\tTotal Marks\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%.2f\n", arr_bucket[i].student_roll_no, arr_bucket[i].student_name, arr_bucket[i].total_marks);
    }
    return 0;
    
}

