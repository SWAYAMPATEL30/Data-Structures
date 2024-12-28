#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *next;
    int data;
}*front,*rear;

void enque()
{
    int val;
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node ));
    printf("Enter the data to be added :");
    scanf("%d",&val);
    ptr->data=val;

    if(front==NULL){
        front=ptr;
        rear=ptr;
    }
    else{
        rear->next=ptr;
        rear=ptr;
    }
}
void deque()
{
    struct node *temp;
    if(front==NULL){
        printf("Queus is empty ");
    }
    else{
        printf("%d,is removed ",front->data);
        temp=front;
        front=front->next;
        free(temp);

    }

}
void display()

{
    struct node *temp;
    if(front==NULL){
        printf("Empty ll ");
    }
    else {
      temp=front;
        while(temp!=rear)
    {
      
        printf("%d",temp->data);
        temp=temp->next;
    } printf("%d",temp->data);
    
            
    }
}

int main()
{
    int c;
    while(1)
    {
        printf("Enter the choice \n 1. enque \n 2. deque \n 3.display");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            enque();
            break;

            case 2:
            deque();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;
        }
    }
    return 0;
}