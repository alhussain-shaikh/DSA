/******************************************************************************
In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Y.
students. Assume that all these students are on ground for a
function. We need to identify a student of S.Y. div. (X) whose
name is "XYZ" and roll no. is "17". Apply appropriate searching
method to identify a required student.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    char name[50];
    int rollNo;
} Student;

typedef struct {
    Student *data;
    int key;
} HashNode;

HashNode *hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(HashNode *node) {
    int key = hashFunction(node->key);
    while (hashTable[key] != NULL) {
        key = (key + 1) % TABLE_SIZE;
    }
    hashTable[key] = node;
}
void printHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == NULL) {
            printf("%d:\n", i);
        } else {
            printf("%d: %s (%d)\n", i, hashTable[i]->data->name, hashTable[i]->data->rollNo);
        }
    }
}


HashNode *search(int key) {
    int h = hashFunction(key);
    while (hashTable[h] != NULL && hashTable[h]->key != key) {
        h = (h + 1) % TABLE_SIZE;
    }
    if (hashTable[h] == NULL) {
        return NULL;
    } else {
        return hashTable[h];
    }
}

int main() {
    Student syStudents[] = {
        {"John", 10},
        {"Jane", 11},
        {"Jack", 12},
        {"Jill", 13},
        {"Joe", 14},
        {"Jessica", 15},
        {"Jacob", 16},
        {"XYZ", 17},
        {"Jason", 18},
        {"Jenny", 19},
    };

    int n = sizeof(syStudents) / sizeof(Student);

    for (int i = 0; i < n; i++) {
        HashNode *node = malloc(sizeof(HashNode));
        node->data = &syStudents[i];
        node->key = syStudents[i].rollNo;
        insert(node);
    }
    printHashTable();

    int searchRollNo = 17;
    HashNode *result = search(searchRollNo);

    if (result == NULL) {
        printf("Could not find student with roll no. %d\n", searchRollNo);
    } else {
        printf("Found student %s with roll no. %d\n", result->data->name, result->data->rollNo);
    }

    return 0;
}
