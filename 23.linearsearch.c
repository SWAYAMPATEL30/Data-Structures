#include<stdio.h>
int n,arr[10],k,target;
int main()
{
printf("Enter the size:");
scanf("%d",&n);
for(int i=0;i<n;i++){
    printf("Eneter the number:");
    scanf("%d",&arr[i]);
}
printf("Enter the number: to find ");
scanf("%d",&target);

for(int i=0;i<n;i++){
    if(arr[i]==target)
    {
        k=1;
        
    }
}
if(k==1)printf("Element found");
else printf("Element Not fount ");
return 0;
}