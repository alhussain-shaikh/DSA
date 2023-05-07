/*
multiplication of two polynomials using linked list
*/

#include <stdio.h>
#include <stdlib.h>
  

struct Node {
    int coeff, power;
    struct Node* next;
};
  

struct Node* addnode(struct Node* start, int coeff, int power)
{
   
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;
  
    
    if (start == NULL)
        return newnode;
  
    struct Node* ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;
  
    return start;
}
  

void printList(struct Node* ptr)
{
    while (ptr->next != NULL) {
        printf("%dx^%d",ptr->coeff,ptr->power);
        //cout << ptr->coeff << "x^" << ptr->power ;
       if( ptr->next!=NULL && ptr->next->coeff >=0)
          //cout << "+";
          printf("+");
  
        ptr = ptr->next;
    }
   // cout << ptr->coeff << "\n";
    printf("%d",ptr->coeff);
}
  

void removeDuplicates(struct Node* start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
  
    
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
  
        while (ptr2->next != NULL) {
  
            // If powerer of two elements are same
            if (ptr1->power == ptr2->next->power) {
  
                // Add their coefficients and put it in 1st element
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
  
                // remove the 2nd element
                //delete (dup);
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
  
// Function two Multiply two polynomial Numbers
struct Node* multiply(struct Node* poly1, struct Node* poly2,struct Node* poly3)
{

    struct Node *ptr1, *ptr2;
    ptr1 = poly1;
    ptr2 = poly2;
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            int coeff, power;
            coeff = ptr1->coeff * ptr2->coeff;
            power = ptr1->power + ptr2->power;
            poly3 = addnode(poly3, coeff, power);
  
            ptr2 = ptr2->next;
        }
        ptr2 = poly2;
        ptr1 = ptr1->next;
    }
    removeDuplicates(poly3);
    return poly3;
}
  
// Driver Code
int main()
{
  
    struct Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
  
    // Creation of 1st Polynomial: 3x^2 + 5x^1 + 6
    poly1 = addnode(poly1, 3, 3);
    poly1 = addnode(poly1, 6, 1);
    poly1 = addnode(poly1, -9, 0);
  
    // Creation of 2nd polynomial: 6x^1 + 8
    poly2 = addnode(poly2, 9, 3);
    poly2 = addnode(poly2, -8, 2);
    poly2 = addnode(poly2, 7, 1);
    poly2 = addnode(poly2, 2, 0);
  
    // Displaying 1st polynomial
    //cout << "1st Polynomial:- ";
    printf("1st Polynomial:- ");
    printList(poly1);
  
    // Displaying 2nd polynomial
    //cout << "2nd Polynomial:- ";
    printf("\n2nd Polynomial:- ");
    printList(poly2);
  
    // calling multiply function
    poly3 = multiply(poly1, poly2, poly3);
  
    // Displaying Resultant Polynomial
    //cout << "Resultant Polynomial:- ";
    printf("\nResultant Polynomial:- ");
    printList(poly3);
  
    return 0;
}
