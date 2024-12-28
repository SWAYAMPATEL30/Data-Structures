#include<stdio.h>
#include<stdlib.h>
void insertion(int arr[],int n){
    int temp;
    for(int i=1;i<n;i++){
        temp=arr[i];
        int j=i-1;
        while(j>=0&& arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main()
{

    int n;
    printf("Entwr the size:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter:");
        scanf("%d",&arr[i]);
    }

 insertion(arr,n);
    printf("selected soert is ");
        for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}