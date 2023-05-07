/******************************************************************************

Write a program to arrange the data of the faculties recruited in the
institute. There are three categories of faculties in the every
department namely professor, Associate professor, and assistant
professor. Recruitment is done as mentioned below. 1. Every
professor has two associate professors. 2. Every Associate has two
assistant professors. Data is given randomly. Suggest suitable
sorting method and implement.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPARTMENTS 10
#define MAX_FACULTIES 30

struct faculty {
    char name[50];
    char department[50];
    char designation[50];
};

int compareFaculties(const void *a, const void *b) {
    const struct faculty *fa = (const struct faculty *)a;
    const struct faculty *fb = (const struct faculty *)b;
    int cmp;

    // first, compare based on department
    cmp = strcmp(fa->department, fb->department);
    if (cmp != 0) {
        return cmp;
    }

    // if departments are equal, compare based on designation
    cmp = strcmp(fa->designation, fb->designation);
    if (cmp != 0) {
        return cmp;
    }

    // if designations are also equal, compare based on name
    return strcmp(fa->name, fb->name);
}

void printFaculties(struct faculty faculties[], int n) {
    int i;
    printf("Name\tDepartment\tDesignation\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%s\t%s\n", faculties[i].name, faculties[i].department, faculties[i].designation);
    }
}

void arrangeFaculties(struct faculty faculties[], int n) {
    // sort the faculties based on department, designation, and name
    qsort(faculties, n, sizeof(struct faculty), compareFaculties);

    // assign associate professors to professors and assistant professors to associate professors
    int i, j;
    for (i = 0; i < n; i++) {
        if (strcmp(faculties[i].designation, "Professor") == 0) {
            for (j = 0; j < 2; j++) {
                strcpy(faculties[i+j+1].designation, "Associate Professor");
            }
        } else if (strcmp(faculties[i].designation, "Associate Professor") == 0) {
            for (j = 0; j < 2; j++) {
                strcpy(faculties[i+j+1].designation, "Assistant Professor");
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of faculties: ");
    scanf("%d", &n);
    struct faculty faculties[n];
    for (i = 0; i < n; i++) {
        printf("Enter the name of faculty %d: ", i+1);
        gets(faculties[i].name);
        gets(faculties[i].name);
        //scanf("%s", faculties[i].name);
        printf("Enter the department of faculty %d: ", i+1);
        gets(faculties[i].department);
        //gets(faculties[i].department);
        //scanf("%s", faculties[i].department);
        printf("Enter the designation of faculty %d (Professor, Associate Professor, or Assistant Professor): ", i+1);
        gets(faculties[i].designation);
        //gets(faculties[i].designation);
        //scanf("%s", faculties[i].designation);
    }
    printf("\n");

    arrangeFaculties(faculties, n);
    printf("Arranged faculties:\n");
    printFaculties(faculties, n);

    return 0;
}

