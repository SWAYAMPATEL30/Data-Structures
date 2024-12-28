#include<stdio.h>
#include<stdlib.h>
#define size 3
int deq[size];

int front =0;
int rear =0;
int count =0;

void rearEnque()
{
    int a;
    if(count==size)
    {
        printf("Queue is full");
    }
    else{
        printf("Enter the element ");
        scanf("%d",&a);
        deq[rear]=a;
        rear=(rear+1)%size;
        count++;
    }

}

void frontEnque()
{
    int a;
    if(count==size)
    {
        printf("Queue is full");
    }
    else{
        printf("Enter the element :");
        scanf("%d",&a);
        front=(front-1+size)%size;
        deq[front]=a;
        count++;    
     }
}

void frontDequeue()
{
    if(count==0){
        printf("Queue is empty");
    }
    else{
        printf("Element %d removed from queue ",deq[front]);
        front=(front+1)%size;
        count--;
    }
}

void rearDequeue()
{
    if(count==0)
    {
        printf("Queue is empty");
    }
    else{
        rear=(rear-1+size)%size;
        printf("Element %d is removed from queue ",deq[rear]);
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
        for (int i=front;j!=0;j--){
            printf("\n%d",deq[i]);
            i=(i+1)%size;
        }
    }
}


int main()
{
    int c;
    while(1){
        printf("Enter your choice accoudingly :\n 1.Enter a element at last \n 2.Enter the element in begging \n3.remove a element from front \n4.remove a element from ending\n 5.display\n 6.exit ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            rearEnque();
            break;

            case 2:
            frontEnque();
            break;

            case 3:
            frontDequeue();
            break;

            case 4:
            rearDequeue();
            break;

            case 5:
            display();
            break;

            case 6:
            exit (0);
            break;

            default:
            printf("Enter chooice between 1-6");
            break;
        }
    }
    return 0;
}
