/******************************************************************************

An operating system assigns job to print queues based on the
number of pages to be printed (1 to 50 pages). You may assume
that the system printers are able to print 10 page per minute.
Smaller print jobs are printed before larger print jobs and print
jobs are processed from a single print queue implemented as a
priority queue). The system administrators would like to compare
the time required to process a set of print jobs using 1, 2, or 3
system printers. Write a program which simulates processing 100
print jobs of varying lengths using either 1, 2, or 3 printers.
Assume that a print request is made every minute and that the
number of pages to print varies from 1 to 50 pages. To be fair,
you will need to process the same set of print jobs each time you
add a printer. The output from your program should indicate the
order in which the jobs were received, the order in which they
were printed, and the time required to process the set of print
jobs. If more than one printer is being used, indicate which
printer each job was printed on.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PAGES 50
#define NUM_JOBS 100
#define PRINT_SPEED 1
typedef struct job
{
    int id;
    int pages;
    int printer;
    struct job *next;
} Job;
Job *newJob(int id, int pages)
{
    Job *job = (Job *)malloc(sizeof(Job));
    job->id = id;
    job->pages = pages;
    job->printer = 0;
    job->next = NULL;
    return job;

}
void printJob(Job *job, int printer)
{
    job->printer = printer;
    printf("Printer %d printed job %d with %d pages\n", printer, job->id,job->pages);
}
int main()
{
    srand(time(NULL));
    printf("Enter the number of printers: \n");
    int n;
    scanf("%d", &n);
    Job *queue = NULL;
    for (int i = 0; i < NUM_JOBS; i++)
    {
        int pages = rand() % MAX_PAGES + 1;
        Job *job = newJob(i + 1, pages);
        if (queue == NULL)
        {
            queue = job;
        }
        else
        {
            Job *curr = queue;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = job;
        }
    }
    for (int numPrinters = n; numPrinters <= n; numPrinters++)
    {
        printf("Processing jobs with %d printer(s)\n", numPrinters);
        Job *curr = queue;
        int printerSpeeds[numPrinters];
        for (int i = 0; i < numPrinters; i++)
        {
            printerSpeeds[i] = PRINT_SPEED;
        }
        
        int time = 0;
        while (curr != NULL)
        {
            int shortest = 0;
            for (int i = 1; i < numPrinters; i++)
            {
                if (printerSpeeds[i] < printerSpeeds[shortest])
                {
                    shortest = i;
                }
            }
            if (printerSpeeds[shortest] > 0)
            {
                printJob(curr, shortest + 1);
                printerSpeeds[shortest] -= curr->pages;
                curr = curr->next;
            }
            else
            {
                time++;
                for (int i = 0; i < numPrinters; i++)
                {
                    printerSpeeds[i] = (printerSpeeds[i] < 0) ? 0 :
        
                    printerSpeeds[i] + PRINT_SPEED;
        
                }
            }
        }
        printf("Total time with %d printer(s): %d minutes\n", numPrinters,time);
    }
    return 0;
}
