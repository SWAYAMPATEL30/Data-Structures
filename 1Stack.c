#include<stdio.h>
#include<stdlib.h>
#define size 50
int stack[size];
int top= -1;

void push()
{
    int a;
    if(top==size-1){
        printf("stack overflow");
    }
    else{
        printf("Enter the element to push in stack :");
        scanf("%d",&a);
        top++;
        stack[top]=a;
    }
}

void pop()
{
    if(top==-1){
        printf("stack is empty");
    }
    else{
        printf("Element '%d' is poped from stack ",stack[top]);
        top--;
    }
}

void display()
{
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("\n%d",stack[i]);
        }
        }
    
}

int main()
{
    int choice;
    
    while(1){
    printf("\n1. push in stack \n 2.pop in stack \n 3.display in \n 4.Exit\n");
    printf("Enter your choice :");
    scanf("%d",&choice);

        switch(choice){
            case 1:
            push();
            break;

            case 2:
            pop();
            break;
            
            case 3:
            display();
            break;

            case 4:
            exit (0);
            break;

            default:
            printf("Enter the number between 1-3 ");
            break;
        }
    }
}