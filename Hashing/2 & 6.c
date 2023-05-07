/******************************************************************************
WAP to simulate faculty database as a hash table. Search a
particular faculty by using 'divide' as a hash function for linear
probing with chaining without replacement method of collision
handling technique. Assume suitable data for faculty record.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#define MAX 10

struct faculty {
    int id;
    char name[20];
    char department[20];
    char designation[20];
};

struct faculty hashtable[MAX];

void init() {
    int i;
    for(i=0; i<MAX; i++) {
        hashtable[i].id = -1;
        strcpy(hashtable[i].name, "");
        strcpy(hashtable[i].department, "");
        strcpy(hashtable[i].designation, "");
    }
}

void insert(int id, char* name, char* department, char* designation) {
    int index = id % MAX;
    int i = 0;
    while(hashtable[index].id != -1) {
        index = (id + (++i)) % MAX;
    }
    hashtable[index].id = id;
    strcpy(hashtable[index].name, name);
    strcpy(hashtable[index].department, department);
    strcpy(hashtable[index].designation, designation);
}

void display() {
    int i;
    printf("\nIndex\tID\tName\t\tDepartment\tDesignation\tChaining\n");
    for(i=0; i<MAX; i++) {
        printf("%d\t%d\t%s\t\t%s\t\t%s\t\t%d\n", i, hashtable[i].id, hashtable[i].name, hashtable[i].department, hashtable[i].designation,hashtable[i].id%MAX);
    }
}

int search(int id) {
    int index = id % MAX;
    int i = 0;
    while(hashtable[index].id != id) {
        if(hashtable[index].id == -1) {
            return -1;
        }
        index = (id + (++i)) % MAX;
    }
    return index;
}

int main() {
     init();
    int choice = 0;
    while(choice != 4) {
        printf("\nMenu:\n1. Add faculty record\n2. Search faculty record\n3. Display all faculty records\n4. Exit\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int id;
                char name[20], department[20], designation[20];
                printf("\nEnter faculty ID: ");
                scanf("%d", &id);
                printf("Enter faculty name: ");
                fflush(stdin);
                gets(name);
                gets(name);
                // scanf("%s", name);
                printf("Enter faculty department: ");
                scanf("%s", department);
                printf("Enter faculty designation: ");
                fflush(stdin);
                gets(designation);
                gets(designation);
                // scanf("%s", designation);
                insert(id, name, department, designation);
                break;
            }
            case 2: {
                int id;
                printf("\nEnter faculty ID to search: ");
                scanf("%d", &id);
                int index = search(id);
                if(index == -1) {
                    printf("\nFaculty with ID %d not found.", id);
                } else {
                    printf("\nFaculty with ID %d found at index %d.", id, index);
                    printf("\nID\tName\t\tDepartment\tDesignation\n");
                    printf("%d\t%s\t\t%s\t\t%s\n", hashtable[index].id, hashtable[index].name, hashtable[index].department, hashtable[index].designation);
                }
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                printf("\nExiting program...");
                break;
            }
            default: {
                printf("\nInvalid choice! Please enter a valid choice (1-4).");
                break;
            }
        }
    }
    return 0;
}
