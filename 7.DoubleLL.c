#include<stdio.h>
#include<stdlib.h>

struct node{
struct node *next;
struct node *prev;
int data;
}*head;

void bInsert(){
    int val;
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Overflow");
    }
    else{
        printf("Enter the data");
        scanf("%d",&val);
        ptr->data=val;
        if(head==NULL){
            ptr->prev=NULL;
            ptr->next=NULL;
            head=ptr;
        }
        else{
            ptr->prev=NULL;
            ptr->next=head;
            head=ptr;
        }
    }
}

void linsert()
{
    int val;
    struct node *temp;
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));

    if(ptr==NULL)
    {
        printf("Over flow");

    }
    else{
        printf("Enter the data");
        scanf("%d",&val);
        ptr->data=val;
        if(head==NULL)
        {
            ptr->prev=NULL;
            ptr->next=NULL;
            head=ptr;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            ptr->next=NULL;
            ptr->prev=temp;
            temp->next=ptr;
        }
    }
}

void rInsert()
{
    struct node *ptr,*temp;
    int val,loc;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Overfloe");

    }
    else{
        printf("Enter loc");
        scanf("%d",&loc);
         ptr->data=val;
        if(head==NULL)
        {
            ptr->prev=NULL;
            ptr->next=NULL;
            head=ptr;
        }
        else{
            temp=head;
            for(int i=1;i<loc;i++){
                temp=temp->next;
            }
            ptr->next=temp->next;
            ptr->prev=temp;
            temp->next->prev=ptr;
            temp->next=ptr;
        }

    }


}

void bDelete()
{
struct node *temp;
if(head==NULL){
    printf("THe Empty ll");

}
else{
    temp=head;
    head=temp->next;
    head->prev=NULL;
    free(temp);

}
}
void lDelete()
{
struct node *temp,*prev;
if(head==NULL){
    printf("THe Empty ll");

}
else{
    temp=head;
    
    while(temp!=NULL);
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
}



void rDelete()
{
    int loc;
struct node *temp,*prev;
if(head==NULL){
    printf("THe Empty ll");

}
else{
    printf("Enter Loc :");
    scanf("%d",&loc);
    temp=head;
    for (int i=0;i<loc;i++)
{
    prev=temp;
    temp=temp->next;

}
prev->next=temp->next;
free(temp);
}



}
void display(){
    struct node  *temp;
    temp=head;
    if(head==NULL){
        printf("Empty ll");

    }
    else{
        while(temp->next!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
            
        
        }           
        printf("%d",temp->data);

    }
}


int main()
{
    int c;
    while(1){
        printf("\n 1.binsert\n 2.display\n3.exit\n4.linsert \n 5.rinsert \n 6.bdelete  \n 7. alter the list \nalter the rist ");

        scanf("%d",&c);
        
        switch(c){
            case 1:
            bInsert();
            break;

            case 2:
            display();
            break;


            case 3:
            exit(0);
            break;

            case 4:
            linsert();
            break;

            case 5:
        }
    }
    return 0;
}