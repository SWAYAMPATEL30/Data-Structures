#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *left;
    struct node *right;
    int data;
}*root;

void insert()
{
    struct node *ptr,*prev,*temp;
    int v;
    printf("Enter the node:");
    scanf("%d",&v);
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=v;
    ptr->left=ptr->right=NULL;
    if(root==NULL){
        root=ptr;
    }
    else{
        temp=root;
    while(temp!=NULL)
    {
        if(temp->data > v){
            prev=temp;
            temp=temp->left;
        }
        else {
            prev=temp;
            temp=temp->right;
        }}
        if(prev->data>v)
        {
            prev->left=ptr;
        }
        else
        {
            prev->right=ptr;
    
    }
}
}

    void inorder(struct node *p)
    {
        if(p!=NULL){
        inorder(p->left);
        printf("%d",p->data);
        inorder(p->right);
    }}
    void postorder(struct node *p)
    {
        if(p!=NULL){
        postorder(p->left);
        postorder(p->right);
        printf("%d",p->data);
    }}
    
    void preorder(struct node *p)
    {
        if(p!=NULL){
            printf("%d",p->data);
            preorder(p->left);
            preorder(p->right);
            
        }
    }
    
    void mirror(struct node *p)
    {
        if(p!=NULL){
        struct node *temp;
        temp=p->left;
        p->left=p->right;
        p->right=temp;
        
        mirror(p->left);
        mirror(p->right);
    }
    }
    int height(struct node *p)
    {if(p!=NULL){
        int m;
        int c=height(p->left);
        int d=height(p->right);
        if(c>d)m=c+1;
        else m=d+1;
        return m;
    }}
    
    int  count(struct node *p)
    {if(p!=NULL){
        
        return (count(p->left)+count(p->right)+1);
    }
    }
    
    int internalcount(struct node *p){
    if(p!=NULL){
        if(p->left!=NULL || p->right!=NULL){
            return (1+internalcount(p->left)+internalcount(p->right));
        }
    }
    
    }
    int externalcount(struct node *p){
        if(p!=NULL){
            return(count(root)-internalcount(root));
        }
    }
    
    // void delete()
    
    // {
    //     int v;
    //     struct node *ptr,*temp,*prev;
    //     printf("Enter the data to delete:");
    //     scanf("%d",&v);
        
    //     temp=root;
    //     prev=NULL;
        
    //     while(temp!=NULL && temp->data!=v){
    //         prev=temp;
    //         if(v<temp->data){
    //             //prev=temp;
    //             temp=temp->left;
    //         }
    //         else{
    //           // prev=temp;
    //             temp=temp->right;
    //         }
    //     }
        
    //     if(temp==NULL){
    //         printf("Element not found");
    //     }
    //     else if(temp->left==NULL &&& temp->right==NULL)
    //         {
    //             if (temp == root) {
    //         root = NULL;
    //     } 
    //             else if(temp==prev->left){
    //                 prev->left=NULL;
    //             }
    //             else
    //             {
    //                 prev->right=NULL;
    //             }
    //             free(temp);
    //         }
    //         else if(temp->left!=NULL && temp->right==NULL)
    //         {
    //             if(temp==prev->left)
    //             {
    //                 prev->left=temp->left;
    //             }
    //             else
    //             {
    //                 prev->right=temp->right;
    //             }
    //             free(temp);
    //         }
    //         else if(temp->left==NULL && temp->right!=NULL)
    //         {
    //             if(temp==prev->left)
    //             {
    //                 prev->left=temp->right;
    //             }
    //             else
    //             {
    //                 prev->right=temp->right;
    //             }
    //             free(temp);
    //         }
    //         else
    //         {
    //             struct node *succ;
    //             struct node *psucc;
    //             succ=temp->left;
    //             psucc=temp;
    //             while(succ->right!=NULL){
    //                 psucc=succ;
    //                 succ=succ->right;
    //             }
    //             temp->data=succ->data;
    //             psucc->right=succ->left;
    //             free(succ);
    //             }
        
    // }
//     void delete() {
//     int v;
//     struct node *temp, *prev, *succ, *psucc;
//     printf("Enter the data to delete: ");
//     scanf("%d", &v);

//     temp = root;
//     prev = NULL;

//     // Step 1: Search for the node to delete
//     while (temp != NULL && temp->data != v) {
//         prev = temp;
//         if (v < temp->data) {
//             temp = temp->left;
//         } else {
//             temp = temp->right;
//         }
//     }

//     if (temp == NULL) {
//         printf("Element not found\n");
//         return;
//     }

//     // Step 2: Case 1 - Node has no children (Leaf Node)
//     if (temp->left == NULL && temp->right == NULL) {
//         if (temp == root) {
//             root = NULL;
//         } else if (temp == prev->left) {
//             prev->left = NULL;
//         } else {
//             prev->right = NULL;
//         }
//         free(temp);
//     }
//     // Step 3: Case 2 - Node has only a left child
//     else if (temp->left != NULL && temp->right == NULL) {
//         if (temp == root) {
//             root = temp->left;
//         } else if (temp == prev->left) {
//             prev->left = temp->left;
//         } else {
//             prev->right = temp->left;
//         }
//         free(temp);
//     }
//     // Step 4: Case 3 - Node has only a right child
//     else if (temp->left == NULL && temp->right != NULL) {
//         if (temp == root) {
//             root = temp->right;
//         } else if (temp == prev->left) {
//             prev->left = temp->right;
//         } else {
//             prev->right = temp->right;
//         }
//         free(temp);
//     }
//     // Step 5: Case 4 - Node has two children
//     else {
//         succ = temp->right;
//         psucc = temp;

//         // Find the inorder successor (smallest node in the right subtree)
//         while (succ->left != NULL) {
//             psucc = succ;
//             succ = succ->left;
//         }

//         // Replace the node's data with the successor's data
//         temp->data = succ->data;

//         // Remove the successor
//         if (psucc->left == succ) {
//             psucc->left = succ->right;
//         } else {
//             psucc->right = succ->right;
//         }
//         free(succ);
//     }
// }


void delete()
{
    struct node *temp;
    struct node *ptr,*succ,*psucc,*prev;
    
    int v;
    printf("Enter the data to delete:");
    scanf("%d",&v);
    
    temp=root;
    prev=NULL;
    
    while(temp!=NULL && temp->data!=v){
        prev=temp;
        if(v<temp->data) temp=temp->left;
        else temp=temp->right;
    }
    if(temp==root){
        root=NULL;
        free(root);
    }
    
    if(temp->left==NULL && temp->right==NULL){
        if(temp==root){
            root=NULL;
        }
        else if(temp==prev->left){
            prev->left=temp->left;
    }
    else{
        prev->right=temp->left;
    }
    free(temp);
    }
    else if(temp->left!=NULL && temp->right==NULL){
        if(temp==root){
            root=temp->left;
        }
        else if(temp==prev->left){
            prev->left=temp->left;
    }
    else{
        prev->right=temp->left;
    }
    free(temp);
    }
    if(temp->left==NULL && temp->right!=NULL){
        if(temp==root){
            root=temp->right;
        }
        else if(temp==prev->left){
            prev->left=temp->left;
    }
    else{
        prev->right=temp->left;
    }
    free(temp);
    }
    else
    {
        succ=temp->left;
        psucc=temp;
        while(succ->right!=NULL){
            succ=succ->right;
        }
        temp->data=succ->data;
        
        if(psucc->left=succ){
            psucc->left=succ->left;
        }
        else
        psucc->right=succ->left;
        free(succ);
    }
    
}

    int main()
    {
        insert();
        insert();
        insert ();
        insert();
        printf("\n in order ");
        inorder(root);
        
                delete();
        inorder(root);
        
        
        
// printf("\n pre order ");
// preorder(root);
//             printf("\n postorder ");    
//         postorder(root);
        
// mirror(root);
//         printf("\n in ordermirro  ");
//         inorder(root);
        
//         printf("the height is  :%d",height(root));
//          printf("the count is  :%d",count(root));
//           printf("the inyernal count is  :%d",internalcount(root));
//           printf("the external count is  :%d",externalcount(root));
//         delete();
//         inorder(root);
        
        return 0;

    }

