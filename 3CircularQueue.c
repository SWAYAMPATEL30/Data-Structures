#include<stdio.h>
#include<stdlib.h>
#define size 10

int cq[size];
int front=0;
int rear=0;
int count=0;


void enque()
{
    int a;
    if(count==size){
        printf("Queue is Full");
    }
    else{
        printf("Enter the element to be inserted in queue:");
        scanf("%d",&a);
        cq[rear]=a;
        rear=(rear+1)%size;
        count++;
    }
}


void deque()
{
    if(count==0){
        printf("Queue is empty");
    }
    else{
        printf("Element %d is remover from queue :",cq[front]);
        front=(front+1)%size;
        count--;
    }
}


void display()
{
    if(count==0){
        printf("The queue is empty");
    }
    else{
        int j=count;
        for(int i=front;j!=0;j--){
            printf("%d",cq[i]);
            i=(i+1)%size;
        }
    }
}


int main()
{
    int c;
    while(1){
        printf("1. enqueue \n 2.dequeue \n 3.display \n 4. exit \n");
        printf("Enter the choice :");
        scanf("%d",&c);
        switch(c){
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
            exit (0);
            break;

            default:
            printf("Enter chooice between 1-4");
            break;
        }
    }
    return 0;
}