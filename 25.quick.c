#include<stdio.h>


void partition(int arr[],int lb,int ub)
{
   int pivot=arr[lb];
int start=lb;
int end=ub;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
        
    }
        int temp=arr[lb];
            arr[lb]=arr[ub];
            arr[ub]=temp;
            return end;

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

    quick(arr,0,n-1);
for(int i=0;i<n;i++){
        
        printf("%d",arr[i]);
    }


}