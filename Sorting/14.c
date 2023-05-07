/******************************************************************************
Using Quick sort, assign the roll nos. to the students of your class
as per their previous years result. i.e. topper will be roll no. 1.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int roll;
    float marks;
} Student;

int partition(Student arr[], int low, int high) {
    Student pivot = arr[high];
    int i = low - 1, j;
    for (j = low; j < high; j++) {
        if (arr[j].marks >= pivot.marks) {
            i++;
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Student temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
    }
}

int main() {
    int n, i;
    printf("Enter the number of students in the class: ");
    scanf("%d", &n);
    Student students[n];
    printf("Enter the details of the students:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    quickSort(students, 0, n-1);

    printf("\nRoll No.\tName\t\tMarks\n");
    for (i = 0; i < n; i++) {
        students[i].roll = i+1;
        printf("%d\t\t%s\t\t%.2f\n", students[i].roll, students[i].name, students[i].marks);
    }

    return 0;
}

