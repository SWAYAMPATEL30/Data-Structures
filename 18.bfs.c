#include<stdio.h>
#include<stdlib.h>
int adj[10][10];
int q[10];
int f=0,r=-1;
int vis[10];
int n;

void bfs(int v){
    for(int i=0;i<n;i++)
    {
        if(adj[v][i]==1 && vis[i]==0)
        {
            q[++r]=i;
            vis[i]=1;
            printf("%d",i);
        }
    if(f<=r)
        bfs(q[f++]);
}}

int main()
{
    int x;
    printf("Enter the number on nodes:\n ");
    scanf("%d",&n);
    printf("Enter the adj matrix\n ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    printf("Enter the starting vertex");
    scanf("%d",&x);

    vis[x]=1;
    printf("Traverse is :%d",x);
    bfs(x);

return 0;

}