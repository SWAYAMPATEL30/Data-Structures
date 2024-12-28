#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *next;
    int power;
    int coeff;
    
}*start1=NULL,*start2=NULL,*result=NULL;

void create(struct node **start)
{

    int c,p,n;
    struct node *ptr,*temp;
    
    printf("Enter the no of elements in expressio n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the coeff:");
        scanf("%d",&c);
        printf("Enter the powwer :");
        scanf("%d",&p);
        ptr=(struct node *)malloc(sizeof(struct node));
    }
    if(*start==NULL){
        *start=ptr;
    }
    else
    {
        temp=*start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;

    }

}

void Cresult(int c,int p)
{
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->coeff=c;
    ptr->power=p;
    ptr->next=NULL;

    if(result==NULL)
    {
        result=ptr;
    }
    else{
        temp=result;

        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
    }

    void add()
    {
        struct node *temp1,*temp2;
        int c,p;
        temp1=start1;
        temp2=start2;
        while(temp1!=NULL&&temp2!=NULL){
            if(temp1->coeff==temp2->coeff){
                c=temp1->coeff+temp2->coeff;
                p=temp1->power;
                Cresult(c,p);
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1->coeff>temp2->coeff){
                c=temp1->coeff;
                p=temp1->power;
                Cresult(c,p);
                temp1=temp1->next;
                
            }
            else {
                c=temp2->coeff;
                p=temp2->power;
                Cresult(c,p);
                temp2=temp2->next;
        }
        
    }
    while(temp1!=NULL){
     c=temp1->coeff;
                p=temp1->power;
                Cresult(c,p);
                temp1=temp1->next;

    }
    while(temp2!=NULL){

c=temp2->coeff;
                p=temp2->power;
                Cresult(c,p);
                temp2=temp2->next;
    }
    }

    void display(struct node *poly ){
        while(poly!=NULL){
        printf("%d^%d",poly->coeff,poly->power);
        poly=poly->next;
        if(poly!=NULL){
            printf("+");
        }}

    }
int main()
{
    create(&start1);
    create(&start2);

    add();

    display(result);
    return 0;

}


