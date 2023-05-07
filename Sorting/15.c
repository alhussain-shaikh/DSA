/******************************************************************************

Arrange the list of employees as per the average of their height
and weight by using appropriate sorting method.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float height;
    float weight;
} Employee;

void merge(Employee arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        float avg1 = (L[i].height + L[i].weight) / 2;
        float avg2 = (R[j].height + R[j].weight) / 2;
        if (avg1 >= avg2) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
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

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n, i;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    Employee employees[n];
    printf("Enter the details of the employees:\n");
    for (i = 0; i < n; i++) {
        printf("Employee %d:\n", i+1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Height: ");
        scanf("%f", &employees[i].height);
        printf("Weight: ");
        scanf("%f", &employees[i].weight);
    }

    mergeSort(employees, 0, n-1);

    printf("\nName\t\tHeight\t\tWeight\t\tAverage\n");
    for (i = 0; i < n; i++) {
        printf("%s\t\t%.2f\t\t%.2f\t\t%.2f\n", employees[i].name, employees[i].height, employees[i].weight, (employees[i].height + employees[i].weight) / 2);
    }

    return 0;
}

