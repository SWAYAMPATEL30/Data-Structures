#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *next;
    int data;
}*top;

void push()
{
    int val;
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted in the stact ");
    scanf("%d",&val);
    ptr->data=val;
        if(top==NULL){
            top=ptr;
            ptr->next=NULL;
        }
        else{
            ptr->next=top;
            top=ptr;
        }
    
}

void pop()
{
    struct node *prev,*temp;
    if(top==NULL){
        printf("Empty ll");

    }
    else{
        temp=top;
        top=temp->next;
        free(temp);
        

    }
}

void peek()
{
    if(top==NULL){
        printf("Empty ll");

    }
    else{
        printf("The top element is %d",top->data);
    }
}

void display()
{
    struct node *temp;
    if(top==NULL){
        printf("Empty ll");

    }
    else{
        temp=top;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
}
}
int  main()
{int c;
    while(1){
        
        printf("Enter the choice : \n 1. push \n 2. pop \n 3. display \n 4. peek\n ");
        scanf("%d",&c);
        switch(c)
        {
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
            peek();
            break;

            case 5:
            exit(0);
            break;
        }
    }
    return 0;
}