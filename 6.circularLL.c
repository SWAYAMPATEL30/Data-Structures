    #include<stdio.h>
    #include<stdlib.h>

    struct node {
        struct node *next;
        int data;
    }*head;

    void bInsert(){
        struct node *ptr,*temp;;
        int val;
        ptr=(struct node *)malloc(sizeof(struct node ));
        if(ptr==NULL){
            printf("Overflow");
        }
        else{
            printf("Enter the data to be inserted:");
            scanf("%d",&val);
            ptr->data=val;
            if(head==NULL){
                head=ptr;
                ptr->next=head;
            
            }
            else{
                temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                ptr->next=head;
                temp->next=ptr;
                head=ptr;
            }

        }
    }

    void lInsert(){
        struct node *ptr,*temp;;
        int val;
        ptr=(struct node *)malloc(sizeof(struct node ));
        if(ptr==NULL){
            printf("Overflow");
        }
        else{
            printf("Enter the data to be inserted:");
            scanf("%d",&val);
            ptr->data=val;
            if(head==NULL){
                head=ptr;
                ptr->next=head;
                
                }
            else{
                temp=head;
                while(temp->next!=head){
                    temp=temp->next;

                }
                temp->next=ptr;
                ptr->next=head;
                
            }
    }
    }
    void rInsert(){
    struct node *temp,*ptr;;
    int val;
    int loc;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Overflow");

    }
    else{
        printf("Enter loc: ");
        scanf("%d",&loc);
        printf("Enter data :");
        scanf("%d",&val);

        ptr->data=val;
        if(head==NULL){
            ptr->next=head;
            head=ptr;
        }
        else{
            temp=head;
            for(int i=1;i<loc-1;i++){
                temp=temp->next;
            }
            ptr->next=temp->next;
            temp->next=ptr;
            
            
        }
    }


    }

    void bDelete(){
        struct node *temp;
        if(head==NULL){
            printf("Empty list ");
        }
        else
        {
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            
            temp->next=head->next;
            free(head);
            head=temp->next;
            
            }

    }

    void lDelete(){
    struct node *temp,*prev;
    if(head==NULL){
        printf("Empty list");
    }
    else{
        temp=head;
        while(temp->next!=head){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
    }

    void rDelete(){
    struct node *temp,*prev;
    int loc;
    if(head==NULL){
        printf("List is Empty");
    }
    else{
        printf("Enter the loc:");
        scanf("%d",&loc);
        temp=head;
        for(int i=1;i<loc;i++){
                prev=temp;
                temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);

    }
    }

    void display(){
    struct node *temp;
    if(head==NULL){
        printf("Empty list ");
    }
    else{
    temp=head;
    while(temp->next!=head){
    printf("\n%d",temp->data);
    temp=temp->next;
    }
    printf("\n%d",temp->data);
    }
    }


    int main()
    {
        int c;
        printf("1.Insert at the begining of list \n2.Insert at last of LinkedList \n3.Insert at Random position in list \n4.Delete from begining of list \n5.Delete from enf of list \n6.delete by specific location \n7.Display list \n 8.exit");
        while(1){

            printf("\nEnter your choice:");
            scanf("%d",&c);
            switch(c){

            case 1:
            bInsert();
            break;

            case 2:
            lInsert();
            break;

            case 3:
            rInsert();
            break;

            case 4:
            bDelete();
            break;

            case 5:
            lDelete();
            break;

            case 6:
            rDelete();        
            break;

            case 7:
            display();
            break;

            case 8:
            exit(0);
            break;

            default:
            printf("Enter the number 1-8");
            }
        }
        return 0;
    }