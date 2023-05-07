/******************************************************************************

In a lab there were 10 computers which are having numbers as
21 to 30. Students registered for a lab are 10 only. Design
appropriate hash function to assign a computer to every
student. Now assume that three students are absent of this
batch so another batch students want to use computers in this
lab. Allocate the computers to these new students by using
linear probing with chaining without replacement.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


int data[30], flag[30];
int size;


int insert(int x)
{
    int start;
    int count = 0;
    int i, j;
    
    start = x % size;


    if (flag[start] == 0)
    {
        data[start] = x;
        flag[start] = 1;
    }
    else if (data[start] % size == x % size)
    {
        j = start;
        while (flag[j] == 1 && count < size)
        {
            j = (j + 1) % size;
            count++;
        }
        if (count == size)
        {
            printf("Hash Table is Full\n");
            return 0;
        }
        data[j] = x;
        flag[j] = 1;
    }
    else
    {
        j = start;
        count = 0;
        while (flag[j] == 1 && count < size)
        {
            j = (j + 1) % size;
            count++;
        }
        if (count == size)
        {
            printf("Hash Table is Full\n");
            return 0;
        }
        data[j] = data[start];
        flag[j] = 1;
        data[start] = x;
    }
    return 0;
}


void display()
{
    for (int i = 0; i < size; i++)
    {
        if (flag[i] == 1)
        {
            printf("%d %d\n", i, data[i]);
        }
        else
        {
            printf("%d ***** \n", i);
        }
    }
}


int main()
{
    int opt;


    size = 10;   // Number of computers


    for (int i = 0; i < size; i++)
    {
        flag[i] = 0;
    }
    int x;


    int absent[3];


    printf("Enter the students that are absent between roll no.21 to roll no.30\n");
    scanf("%d%d%d",&absent[0],&absent[1],&absent[2]);


    for(int i =21; i<=30; i++){
        if(i!=absent[0] && i!=absent[1] && i!=absent[2]){
            insert(i);
        }
    }
    printf("Computers alloted ! \n");
    display();


    int newStudents[3];


    printf("Enter the roll nos of 3 new students\n");
    scanf("%d%d%d",&newStudents[0],&newStudents[1],&newStudents[2]);


    insert(newStudents[0]);
    insert(newStudents[1]);
    insert(newStudents[2]);
    printf("Computers alloted to new Students \n");


    display();
}

