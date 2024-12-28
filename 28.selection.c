#include <stdio.h>
#include<stdlib.h>

void selection(int arr[],int n)
{
for(int i=0;i<n-1;i++){
    int min=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    if(min!=i){
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
}

int main ()
{
    int n;

    printf("enter the size :");
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        printf("data");
        scanf("%d",&arr[i]);
    }

    selection(arr,n);
for(int i=0;i<n;i++){
        
        printf("%d",arr[i]);
    }


}