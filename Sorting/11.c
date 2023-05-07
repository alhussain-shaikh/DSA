/******************************************************************************
You have a fleet of N cars waiting for repair, with the estimated
repair times rk for the car Ci , 1 ≤ k ≤ N. What is the best repair
schedule (order of repairs) to minimize the total lost time for being
out-of-service. How much computation is needed to find the lost
service-times all schedules?

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void repairSchedule(int repairTimes[], int n) {
    int i, j, temp;
    // sort the repair times in ascending order
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (repairTimes[i] > repairTimes[j]) {
                temp = repairTimes[i];
                repairTimes[i] = repairTimes[j];
                repairTimes[j] = temp;
            }
        }
    }
    // print the repair schedule in order
    printf("Repair Schedule (in minutes):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", repairTimes[i]);
    }
    printf("\n");
    // calculate the total lost time
    int totalLostTime = 0;
    int currentTime = 0;
    for (i = 0; i < n; i++) {
        totalLostTime += currentTime;
        currentTime += repairTimes[i];
    }
    // print the total lost time
    printf("Total Lost Time: %d minutes\n", totalLostTime);
}

int main() {
    int n, i;
    printf("Enter the number of cars waiting for repair: ");
    scanf("%d", &n);
    int repairTimes[n];
    for (i = 0; i < n; i++) {
        printf("Enter the estimated repair time (in minutes) for Car %d: ", i+1);
        scanf("%d", &repairTimes[i]);
    }
    printf("\n");
    repairSchedule(repairTimes, n);
    return 0;
}

