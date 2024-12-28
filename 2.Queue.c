#include<stdlib.h>
#include<stdio.h>
#define size 50

int que[size];
int front=-1;
int rear=-1;

void enque()
{
    int a;
    if(rear>size-1){
        printf("queue is full");
    }
    else
    {
        if(front==-1){
            front++;
        }
        rear++;
        printf("Enter the element to be inserted:");
        scanf("%d",&a);
        que[rear]=a;
    }
}

void deque()
{
    if(front==-1 || front>rear){
        printf("Queue is empty");
    }
    else{
        printf("Element '%d' removeed from queue ",que[front]);
        que[front++];
    }
}

void display()
{
    if(front==-1 || front>rear){
        printf("Queue is empty");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\n",que[i]);
        }
    }
}

int main()
{
    int c;
    while(1){
        printf("1.enqueue\n  2.Dequeue\n  3.display\n  4.exit");
        printf("\n Enter your chooice :");
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
            printf("Enter valid number from (1-3)");

        }
    }
    
    return 0;

}