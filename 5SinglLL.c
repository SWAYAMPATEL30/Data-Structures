#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
} *head;

void beginInsert()
{
    struct node *ptr;
    int val;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("Overflow");
    }
    else
    {
        printf("Enter the Elememt to insert:");
        scanf("%d", &val);
        ptr->data = val;
        if (head == NULL)
        {
            ptr->next=NULL;
            head = ptr;
        }
        else
        {
            ptr->next = head;
            head = ptr;
        }
    }
}

void lastInsert()
{
    struct node *ptr, *temp;
    int val;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("Overflow");
    }
    else
    {
        printf("Enter the Elememt to insert:");
        scanf("%d", &val);
        ptr->data=val;
        if (head == NULL)
        {
            ptr->next=NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            
            temp->next = ptr;
            ptr->next = NULL;
            
        }
    }
}

void randomInsert()
{
    struct node *ptr, *temp;
    int val;
    int loc;
    ptr=(struct node*) malloc(sizeof(struct node ));
    if (ptr == NULL)
    {
        printf("Overflow");
    }
    else{
        printf("Enter the location you and to enter your dtaa:");
        scanf("%d",&loc);
        printf("Enter the data:");
        scanf("%d",&val);
        ptr->data=val;

        if(head==NULL){
            ptr->next=NULL;
            head=ptr;
        }
        else{
            temp=head;
            for(int i=1;i<loc;i++){
                temp=temp->next;
            }
            ptr->next=temp->next;
            temp->next=ptr;
        }
    }
}

void display()
{
    struct node *temp;
    if (head==NULL){
        printf("LL is empty ");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}

void beginDelete()
{
    struct node *temp;
    if(head==NULL){
        printf("LL is Empty");
    }
    else{
        temp=head;
        head=temp->next;
        free(temp);

    }
}
void lastDelete()
{
    struct node *temp,*prev;
    if(head==NULL){
        printf("list is empty");

    }
    else{
        temp=head;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);

    }
}

void randomDelete()
{
    struct node *temp,*prev;
    int loc;
    if(head==NULL){
        printf("Empty LL");
    }
    else{
        printf("Enter the loc to dellete");
        scanf("%d",&loc);
        temp=head;
        for(int i=0;i<loc;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
}


void reverse()
{
    struct node *prev,*next,*current=head;
    if(head==NULL){
        printf("empty list ");
    }
    else{
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;

        }
        head=prev;
        printf("the list is reversed ");
    }
}
int main()
{
    int c;

    while(1){
        printf("\n\n1.binsert\n 2.linsert \n 3.rinsert \n4.bDelete\n 5.ldelete \n 6.rdelete \n7.display \n7.exit");
        scanf("%d",&c);
        switch(c){
            case 1:
            beginInsert();
            break;
            
            case 2:
            lastInsert();
            break;

            case 3:
            randomInsert();
            break;

            case 4:
            beginDelete();
            break;
            
            case 5:
            lastDelete();
            break;

            case 6:
            randomDelete();
            break;
            
            case 7:
            display();
            break;

            case 9:
            reverse();
            break;

            case 8:
            exit(0);
            break;

            default:
            printf("enter number 1-5");
            break;


        }
    }
    return 0;
}