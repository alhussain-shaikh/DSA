/******************************************************************************
WAP to simulate faculty database as a hash table. Search a
perticular faculty by using MOD as a hash function for linear
probing with chaining with replacement method of collision
handling technique. Assume suitable data for faculty record.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
struct faculty {
    char name[50];
    char department[50];
    int salary;
};
struct element {
    int key;
    struct faculty f;
};
struct hash_table {
    struct element elements[MAX_SIZE];
};
int hash(int key) {
    return key % MAX_SIZE; // using MOD as hash function

}
void insert(struct hash_table *table, int key, struct faculty f) {
    int index = hash(key);
    int i = index;
    while (table->elements[i].key != -1) {
        i = (i + 1) % MAX_SIZE;
        if (i == index) {
            printf("Error: hash table is full\n");
            return;
        }
        if (table->elements[i].key == key) {
            printf("Error: duplicate key %d\n",key);
            
            return;
        }
    }
    table->elements[i].key = key;
    table->elements[i].f = f;
}
struct faculty search(struct hash_table table,int key) {
    int index = hash(key);
    int i = index;
    while (table.elements[i].key != -1) {
        if (table.elements[i].key == key) {
            return table.elements[i].f;
        }
        i = (i + 1) % MAX_SIZE;
        if (i == index) {
            break;
        }
    }
    struct faculty empty = {"","", 0};
    return empty;
}
int main() {
    int n;
    printf("Enter number of faculty records to insert: ");
    scanf("%d", &n);
    
    struct hash_table table;
    for (int i = 0; i < MAX_SIZE; i++) {
        table.elements[i].key = -1;
    }
    for (int i = 0; i < n; i++) {
        int key;
        struct faculty f;
        printf("Enter faculty ID (must be unique): ");
        scanf("%d", &key);
        
        if (search(table, key).salary != 0) {
            printf("Error: duplicate key %d\n",key);
            i--;
            continue;
        }
        printf("Enter faculty name: ");
        scanf(" %49[^\n]", f.name);
        printf("Enter faculty department: ");
        scanf(" %49[^\n]", f.department);
        printf("Enter faculty salary: ");
        
        scanf("%d", &f.salary);
        insert(&table, key, f);
    }
    int search_key;
    printf("Enter faculty ID to search for: ");
    scanf("%d", &search_key);
    
    struct faculty result = search(table,search_key);
    if (strcmp(result.name,"") == 0) {
        printf("Faculty with ID %d not found\n",search_key);
    }
    else {
        printf("Faculty record found for ID %d:\n", search_key);
        printf("Name: %s\n", result.name);
        
        printf("Department: %s\n",result.department);
        
        printf("Salary: %d\n", result.salary);
    
    }
    return 0;
}

