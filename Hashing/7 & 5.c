/******************************************************************************
WAP to simulate employee database as a hash table. Search a
perticular faculty by using Mid square Method as a hash function
for linear probing with chaining with replacement method of
collision handling technique. Assume suitable data for faculty
record.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct
{
    int id;
    char name[50];
    char department[50];
    float salary;
} Employee;

typedef struct
{
    int key;
    Employee employee;
} HashEntry;

typedef struct
{
    HashEntry *entries;
    int size;
} HashTable;

int hash(int key, int size)
{
    int square = key * key;
    int mid = (square / 100) % 10000;
    return mid % size;
}

void initHashTable(HashTable *hashTable, int size)
{
    hashTable->entries = calloc(size, sizeof(HashEntry));
    hashTable->size = size;
    for (int i = 0; i < size; i++)
    {
        hashTable->entries[i].key = -1;
    }
}

void insertEmployee(HashTable *hashTable, Employee employee)
{
    int key = employee.id;
    int index = hash(key, hashTable->size);
    int i = 0;
    while (i < hashTable->size)
    {
        if (hashTable->entries[index].key == -1)
        {
            hashTable->entries[index].key = key;
            hashTable->entries[index].employee = employee;
            return;
        }
        else if (hashTable->entries[index].key == key)
        {
            hashTable->entries[index].employee = employee;
            return;
        }
        i++;
        index = (index + i) % hashTable->size;
    }
    printf("Hash table is full!\n");
}

Employee *searchEmployee(HashTable *hashTable, int key)
{
    int index = hash(key, hashTable->size);
    int i = 0;
    while (i < hashTable->size)
    {
        if (hashTable->entries[index].key == key)
        {
            return &(hashTable->entries[index].employee);
        }
        else if (hashTable->entries[index].key == -1)
        {
            return NULL;
        }
        i++;
        index = (index + i) % hashTable->size;
    }
    return NULL;
}

void displayEmployees(HashTable *hashTable)
{
    printf("ID\tName\tDepartment\tSalary\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < hashTable->size; i++)
    {
        if (hashTable->entries[i].key != -1)
        {
            Employee employee = hashTable->entries[i].employee;
            printf("%d\t%s\t%s\t%.2f\n", employee.id, employee.name, employee.department, employee.salary);
        }
    }
    printf("-------------------------------------------\n");
}

int main()
{
    HashTable hashTable;
    initHashTable(&hashTable, MAX_EMPLOYEES);
    int choice;

    Employee employee1 = {1, "Aakash Matkar", "Sales", 50000};
    Employee employee2 = {2, "Akshay Jadhav", "Technical", 60000};
    Employee employee3 = {3, "AL Hussain", "Finance", 65000};
    Employee employee4 = {4, "Anish Bonde", "Operation", 70000};

    insertEmployee(&hashTable, employee1);
    insertEmployee(&hashTable, employee2);
    insertEmployee(&hashTable, employee3);
    insertEmployee(&hashTable, employee4);

    printf("All employees in the database:\n");
    displayEmployees(&hashTable);

    printf("..............................................\n");
    printf("Choose any option below : \n");
    printf("1 : Insert Employee in Database \n");
    printf("2 : Search Employee in Database \n");
    printf("3 : Exit\n");
    printf("Enter Your Choice : \n");
    scanf("%d", &choice);

    while (choice == 1 || choice == 2)
    {
        if (choice == 1)
        {
            Employee newemp ;
            printf("Enter Employee Data : \n");
            printf("Enter the Employee ID : \n");
            scanf("%d", &newemp.id);
            while (searchEmployee(&hashTable, newemp.id) != NULL)
            {
                printf("Employee with given ID exists \n");
                printf("Please choose a different ID \n");
                printf("Enter the Employee ID : \n");
                scanf("%d", &newemp.id);
            }
           
            printf("Enter Name of Employee : \n");
            fflush(stdin);
            gets(newemp.name);

            printf("Enter Salary : \n");
            scanf("%f", &newemp.salary);

            printf("Enter Department : \n");
            fflush(stdin);
            gets(newemp.department);

    
            insertEmployee(&hashTable, newemp);
            printf("Employee id : %d  added Successfully !! ", newemp.id);
        }
        if (choice == 2)
        {
            int searchId;
            printf("Enter ID of Employee\n");
            scanf("%d", &searchId);
            Employee *foundEmployee = searchEmployee(&hashTable, searchId);
            if (foundEmployee != NULL)
            {
                printf("Employee with ID %d found:\n", searchId);
                printf("ID\tName\tDepartment\tSalary\n");
                printf("-------------------------------------------\n");
                printf("%d\t%s\t%s\t%.2f\n", foundEmployee->id, foundEmployee->name, foundEmployee->department, foundEmployee->salary);
                printf("-------------------------------------------\n");
            }
            else
            {
                printf("Employee with ID %d not found.\n", searchId);
            }
        }

        printf("..............................................\n");
        printf("Choose any option below : \n");
        printf("1 : Insert Employee in Database \n");
        printf("2 : Search Employee in Database \n");
        printf("3 : Exit\n");
        printf("\nEnter Your choice : \n");
        scanf("%d", &choice);
    }

    printf("\nProgram Terminated Successfully !! ");

    return 0;
}
