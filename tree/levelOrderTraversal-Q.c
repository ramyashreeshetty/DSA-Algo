#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
}NODE;

NODE *front=NULL;
NODE *rear=NULL;


void enqueue(NODE * root)
{
    //create newnode
    //QUEUE * newnode=(QUEUE*)malloc(sizeof(QUEUE));

    if(root==NULL)
    {
        printf("QUEUE is full");
    }
    else{

        //it means its first node
        if(front==NULL)
        {
            front=rear=root;
        }
        //insert the new nodes
        else{
            rear->right=root;
            root->left=rear;
            rear=root;
        }
    }
}


NODE * dequeue()
{
    int val;
    if(front==rear)
    {
        printf("QUEUE is empty");
    }
    else{
        NODE * ptr=front;
        front=front->right;
        return ptr;
    }

}


NODE * createNode()
{
    int x=0;
    NODE * newnode=(NODE *)malloc(sizeof(NODE));
    printf("Enter data (-1 if no node):");
    scanf("%d",&x);

    if(x==-1)
    {
        return 0;
    }
    else{
        newnode->data=x;
        printf("Enter left child %d",x);
        newnode->left=createNode();

        printf("Enter right child %d",x);
        newnode->right=createNode();

        return newnode;
    }
}


void levelOrder(NODE * root)
{
    NODE * dum=NULL;
    int val=0;

    if(root==NULL)
        return;
    
    //insert root data
    enqueue(root);
    NODE * ptr=root;

    while(ptr!=NULL)
    {
        
        printf("%d->",ptr->data);
        while(ptr->left!=NULL)
        {
            enqueue(ptr->left);
        }
        while(ptr->right!=NULL)
        {
            dum=ptr->right;
            enqueue(ptr->right);
        }

        ptr=dequeue();
        
    }

}

int main()
{
    NODE * root;
    root=0;
    root=createNode();

    printf("Level order traversal of following tree is:\n");
    levelOrder(root);

}