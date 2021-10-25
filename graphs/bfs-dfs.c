#include<stdio.h>
#include<stdlib.h>
int adj[50][50],visited[50],q[20],front=-1,rear=-1,top=-1,n,i,current;


void bfs(int v)
{
    visited[v]=1;
    q[++rear]=v;

    //TRAVERSE TILL THE END
    while(front!=rear)
    {
        current=q[++front];
        for(int i=1;i<=n;i++)
        {
            if((adj[current][i]==1)&& visited[i]==0)
            {
                q[++rear]=i;
                visited[i]=1;
                printf("\n%d->%d",v,i);
            }
        }

    }
}

void dfs(int d)
{
    visited[d]=1;
    q[++top]=d;
    for(int i=1;i<=n;i++)
    {
        if((adj[d][i]==1)&& visited[i]==0)
            {
                q[++top]=i;
                visited[i]=1;
                printf("\n%d->%d",d,i);
                dfs(i);
            }

    }
}

int main()
{
    int ch,start,j;
    printf("Create a graph \n enter no. in the graph:");
    scanf("%d",&n);
    printf("Enter the adjanceny matrix:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    do{
        printf("\n1.BFS\n2.DFS\n3.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);

        //KEEPS TRACK OF VISITED NODES
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }

        printf("Enter the starting vertex:");
        scanf("%d",&start);

        switch(ch)
        {
            case 1:
            bfs(start);
            break;
            case 2:
            dfs(start);
            break;
            case 3:
            exit(0);
        }


    }while(1);
}
