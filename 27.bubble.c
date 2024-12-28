#include<stdio.h>

void bubble(int arr[],int n){
    int i,j;
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;

            }

        }
        if(flag==0){
            break;
        }
    }
}
int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++){
        printf("enter:");
        scanf("%d",&arr[i]);
    }
    bubble(arr,n);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}