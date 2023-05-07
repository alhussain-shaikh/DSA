/******************************************************************************

Assume that an array A with n elements was sorted in an ascending
order, but two of its elements swapped their positions by a mistake
while maintaining the array. Write a code to identify the swapped
pair of elements and their positions in the asymptotically best
possible time. [Assume that all given elements are distinct
integers.]

*******************************************************************************/
#include <stdio.h>

void identifySwappedPair(int arr[], int n) {
    int firstIndex = -1, secondIndex = -1, i;
    for (i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            if (firstIndex == -1) {
                firstIndex = i;
            } else {
                secondIndex = i+1;
                break;
            }
        }
    }
    if (secondIndex == -1) {
        secondIndex = firstIndex + 1;
    }

    printf("Swapped elements are %d and %d\n", arr[firstIndex], arr[secondIndex]);
    printf("Their positions are %d and %d\n", firstIndex+1, secondIndex+1);
}

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    identifySwappedPair(arr, n);

    return 0;
}

