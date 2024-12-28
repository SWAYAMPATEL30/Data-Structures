#include<stdio.h>
#include<stdlib.h>

int n,k=0,target;

int main()
{
    printf("Enter the size :");
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
printf("Enter the nuber");
scanf("%d",&arr[i]);
    }

    printf("target");
    scanf("%d",&target);

    int s=0,e=n-1;
int mid;
    while(s<=e){
        mid=(s+e)/2;

        if(arr[mid]==target){
            k=1;
            break;
        }
        else if(arr[mid]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    if(k==1){
        printf("found");

    }
    else{
        printf("not ");
    }
}