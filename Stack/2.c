/******************************************************************************
Write a program to implement following operations using stack.
A. Factorial of a given number 
B. Generation of Fibonacci series.
C. Decimal to binary conversion
*******************************************************************************/

#include <stdio.h>

int stk[100];
int Stack[100];
int stk2[100];
int size2=100;
int top2=-1;




int size=100;
int size1=100;
int ptr=-1;
int top1=-1;
void pushFib(int x){
    if (top2==size1-1){
        printf("OverFlow \n ");
        
    }else{
        ++top2;
        stk2[top2]=x;
        
    }
}

int popFib(){
    int item;
    if (top2==-1){
        printf("UnderFlow \n");
    }
    else{
        item=stk2[top2];
        --top2;
        return item;
    }
}
void pushD(int x){
    if (top1==size1-1){
        printf("OverFlow \n ");
        
    }else{
        ++top1;
        Stack[top1]=x;
        
    }
}
void popD(){
    if (top1==-1){
        printf("UnderFlow \n");
    }
    else{
        top1--;
    }
}

void push(int x){
    if (ptr==size-1){
        printf("OverFlow \n ");
        
    }else{
        ++ptr;
        stk[ptr]=x;
        
    }
}
int top(){
    if(ptr==-1){
        printf("UnderFlow \n");
        return -1;
        
    }else{
        return stk[ptr];
    }
}

void pop(){
    if (ptr==-1){
        printf("UnderFlow \n");
    }
    else{
        --ptr;
    }
}
int isempty(){
    if(ptr == -1){
        return 1;
        
    }else{
        return 0;
    }
}
void show()
{
    for (int i=ptr;i>=0;i--)
    {
        printf("\n %d\n",stk[i]);
    }
    if(ptr == -1)
    {
        printf("Stack is empty");
    }
}
void show2()
{
    for (int i=top2;i>=0;i--)
    {
        printf("\n %d\n",stk2[i]);
    }
    if(top2 == -1)
    {
        printf("Stack is empty");
    }
}
void fact(){
    int i,n,temp,k=0;
    
    while(k<3){
        printf("Enter the Number : ");
    scanf("%d",&n);
    
    push(1);
    for(i=2;i<=n;++i){
        temp=top();
        pop();
        push(temp*i);
    }
    
    printf("Factorial : %d",top());
    printf("\nThe Element Present In the Stack.");
    show();
    k++;
    }
}
void decimalToBinary() {
    int num;
    printf("\n Enter the Number : ");
    scanf("%d",&num);
   if (num == 0) {
      printf("0");
      return;
   }
   
   while (num > 0) {
     
      
      pushD(num % 2);
      
      num /= 2;
   }
   
   
   printf("\n The binary Value  is ");
   while (top1 != -1) {
      printf("%d", Stack[top1]);
      popD();
   }
}

void Fib(){
    int a,b,n,c;
    printf("\nEnter the first Element of the series: ");
    scanf("%d",&a);
    pushFib(a);
    printf("\nEnter the Second Element of the series: ");
    scanf("%d",&b);
    pushFib(b);
    printf("\nHow long you need a sequence:  ");
    scanf("%d",&n);
    while(0<n)
    {
        b=popFib();
        a=popFib();
        c=a+b;
        pushFib(a);
        pushFib(b);
        pushFib(c);
        n--;
        
        
    }
    printf("\n Element present in the Fib Stack ");
    show2();
    
    
    
}
int main()
{
    int choice;
    
    while(choice != 4)
    {
        printf("\n Choose one from the below options...\n");
        printf("\n1.Factorial of a given number\n2.Generation of Fibonacci series.\n3.Decimal to binary conversion\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                fact();
                break;
            }
            case 2:
            {
                Fib();
                break;
            }
            case 3:
            {
                decimalToBinary();
                break;
            }
            case 4:
            {
                printf("Exiting....");
                break;
            }
            default:
                {
                printf("Please Enter valid choice ");
                }
        };
    }
    return 0;
}
