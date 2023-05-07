/******************************************************************************
Write a Program to implement Kruskals algorithm to find
minimum spanning tree of a user defined graph. Use Adjacency
List to represent a graph.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 9999

struct node {
  char vertex;
  int cost;
  int visited;
  struct node* next;
};

struct Graph{
    int num_vertices;
    struct node* ptr[MAX]; //array of pointers to node for list
};

struct Graph g;

struct node* insert(struct node *head, char vertex, int cost)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex=vertex;
    newNode->cost=cost;
    newNode->next=NULL;
    newNode->visited=0;
    struct node* temp;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;
}

int findNode(struct node *head, char vertex)
{
    struct node* temp = head;
    while (temp != NULL) {
        if(temp->vertex==vertex){

            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int countedges(struct node* head)
{
    struct node* temp=head->next;
    int count=0;
    printf("Existing edges are:\n");
    while(temp!=NULL){
        printf("Vertex %c cost %d\n", temp->vertex, temp->cost);
        temp=temp->next;
        count++;
    }
    return count;
}

void printGraph(struct Graph g)
{
    for(int i=1; i<=g.num_vertices; i++)
    {
        printf("\nVertex: %c->", g.ptr[i]->vertex);
        g.ptr[i] = g.ptr[i]->next;
        while (g.ptr[i] != NULL)
        {
            printf(" %c", g.ptr[i]->vertex);

            g.ptr[i] = g.ptr[i]->next;
        }
        printf("\n");
    }
}

//struct Graph kruskals(struct Graph g)
void kruskals(struct Graph g)
{
    printf("The edges of Minimum Cost Spanning Tree are\n");
    int i,j,k,a1, b1, edgecount=1;
    char a,b;
    int min=MAX;
    int mincost=0;
    struct Graph* temp;
    struct node* tempNode;
    while(edgecount<g.num_vertices)
    {
        min=MAX;
        temp=&g;
        for(i=1;i<=g.num_vertices;i++)
        {

            tempNode = temp->ptr[i];

            while(tempNode!=NULL)
            {
                if(tempNode->cost < min && tempNode->cost!=0 && tempNode->visited!=1)
                {
                    min=tempNode->cost;
                    a=temp->ptr[i]->vertex;
                    a1=i;
                    b=tempNode->vertex;
                    for(int k=1; k<=g.num_vertices; k++){
                        if(g.ptr[k]->vertex==b){
                            b1=k;
                            break;
                        }
                    }
                }
                tempNode = tempNode->next;
                //j++;
            }
        }

        mincost = mincost+min;
        if(edgecount==1){
            for(int i=1; i<=g.num_vertices; i++){
            tempNode = g.ptr[i];
            while(tempNode!=NULL){
                if(tempNode->vertex==a){
                    tempNode->visited=1;
                }
                tempNode=tempNode->next;
            }
            }
        }
        else{

            tempNode = g.ptr[b1];
            while(tempNode!=NULL){
            if(tempNode->vertex==a){
                tempNode->visited=1;
                break;
            }
            tempNode=tempNode->next;
            }
        }
        //tempNode = g.ptr[a];
        for(int i=1; i<=g.num_vertices; i++){
            tempNode = g.ptr[i];
            while(tempNode!=NULL){
                if(tempNode->vertex==b){
                    tempNode->visited=1;

                }
                tempNode=tempNode->next;
            }
        }

        printf("%d edge (%c,%c) =%d\n",edgecount++,a,b,min);

    }

    printf("\nMinimum cost = %d\n",mincost);

}

int main()
{
    int num_vertices, edges, cost;
    char vertex;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    fflush(stdin);
    g.num_vertices = num_vertices;
    struct node* head = NULL;
    for(int i=1; i<=num_vertices; i++){
        printf("Enter vertice %d: ", i);
        scanf("%c", &vertex);
        fflush(stdin);
        g.ptr[i]=insert(head, vertex, 0);
    }

    for(int i=1; i<=num_vertices; i++)
    {
        //printf("\nEnter vertice %d: ", i);
        //scanf("%d", &vertex);
        printf("Vertex %c: Enter number of edges: ", g.ptr[i]->vertex);
        //fflush (stdin);
        scanf("%d", &edges);
        int count = countedges(g.ptr[i]);
        if (count==0) printf("\nNone\n");
        //g.ptr[i] = insert(head, vertex, 0);
        for(int j=count+1; j<=edges; j++)
        {
            printf("Edge %d ", j);
            printf("Enter vertex and cost: ");
            scanf(" %c %d", &vertex, &cost);
            //printf("%c %d", vertex, cost);
            int find = findNode(g.ptr[i], vertex);
            //printf("find %d ", find);
            fflush(stdin);
            if(find==1){
                printf("\nAlready Exists");
                j--;
            }
            else{
                g.ptr[i] = insert(g.ptr[i], vertex, cost);
                //struct Graph *tempGraph = &g;
                //struct node* tempNode = g.ptr[i];
                for(int k=i+1; k<=num_vertices; k++){
                    //printf("g.ptr.k = %c", g.ptr[k]->vertex);
                    if(g.ptr[k]->vertex==vertex){
                        g.ptr[k]=insert(g.ptr[k], g.ptr[i]->vertex, cost);
                        break;
                    }
                }
            }
        }
    }

    printGraph(g);
    kruskals(g);
    //g = kruskals(g);
    //printGraph(g);
    return 0;
}
