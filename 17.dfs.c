#include<stdio.h>
#include<stdlib.h>

//dfs

int adj[10][10],visited[10];
int n;
void dfs(int v){
    for(int i=0;i<n;i++)
    {
        if(adj[v][i]==1 && visited[i]==0)
        {
            printf("%d",i);
             visited[i]=1;
            dfs(i);
        }
    }
}
int main()
{
    int x;
    printf("Enter the  numbe rof nodes:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter the value:");
            scanf("%d",&adj[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    printf("Enter the start vertex");
    scanf("%d",&x);
    printf("%d",x);
    visited[x]=1;
    dfs(x);
    
    return 0;
}