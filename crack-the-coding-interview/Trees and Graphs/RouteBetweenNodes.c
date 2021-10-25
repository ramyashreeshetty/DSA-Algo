#include<stdio.h>
#include<stdlib.h>
int adj[50][50],visited[50],q[20],front=-1,rear=-1,n,i,current;


void bfs(int s,int e)
{
    visited[s]=1;
    q[++rear]=s;
    int ans=0;

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

                if(current==s)
                {
                    printf("TRUE");
                    front=rear;
                    ans=1;
                    break;
                }

            }
        }

    }
    if(ans==0)
    {
        printf("False");
    }
}

int main()
{
    int ch,start,j,end;
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
        printf("\n1.Check Route\n2.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);

        //KEEPS TRACK OF VISITED NODES
        for(int i=0;i<n;i++)
        {
            visited[i]=0;
        }

        printf("Enter the starting vertex:");
        scanf("%d",&start);
        printf("Enter the starting vertex:");
        scanf("%d",&end);

        switch(ch)
        {
            case 1:
            bfs(start,end);
            break;
            case 2:
            exit(0);
        }


    }while(1);
}