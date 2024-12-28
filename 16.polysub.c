#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *next;
    int power;
    int coeff;
}*start1=NULL,*start2=NULL,*result=NULL;

struct node  *create(struct node **start){
    int c,p,n;
    struct node *temp,*ptr;
    printf("Enter th number of terms :");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the coeff:");
        scanf("%d",&c);
        printf("Enter its power :");
        scanf("%d",&p);

        ptr=(struct node*)malloc(sizeof(struct node));
       ptr->coeff=c;
        ptr->power=p;
        ptr->next=NULL;

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
    return start;

}

void Cresult(int c,int p){
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
   ptr->coeff=c;
    ptr->power=p;
    ptr->next=NULL;

    if(result==NULL){
        result=ptr;
    }
    else{
        temp=result;
        while(temp!=result){
            temp=temp->next;
        }
        temp->next=ptr;
    }
}

void sub()
{
    int c,p;
    struct node*temp1,*temp2;
    temp1=start1;
    temp2=start2;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->power==temp2->power){
            c=temp1->coeff-temp2->coeff;
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
        else{
            c=temp2->coeff;
            p=temp2->power;
            Cresult(c,p);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        Cresult(temp1->coeff,temp1->power);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        Cresult(temp2->coeff,temp2->coeff);
        temp2=temp2->next;
    }

}
void display(struct node *poly) {
    if (poly == NULL) {
        printf("Empty\n");
    } else {
        while (poly != NULL) {
            // Print term in the format 'coeff*x^power'
            printf("%d*x^%d", poly->coeff, poly->power);

            // Move to the next term
            poly = poly->next;

            // Add '+' only if it's not the last term
            if (poly != NULL) {
                printf(" + ");
            }
        }
        printf("\n"); // Print newline after the polynomial
    }
}


int main()
{
    start1=start2=result=NULL;
    create(&start1);
    create(&start2);

    sub();

    display(result);
    return 0;
}