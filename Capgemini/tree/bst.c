//Program to construct,delete and search in BST. (including inorder traversal)

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * rlink;
    struct node * llink;
}NODE;

NODE * root;

NODE * createNode(NODE * root,int key)
{
    if(root==NULL)
    {
        NODE * new;
        new=(NODE *)malloc(sizeof(NODE));
        new->data=key;
        new->rlink=NULL;
        new->llink=NULL;
        return new;
    }
    if(key < (root->data))
    {
        root->llink=createNode(root->llink,key);
    }
    else if( key > (root->data))
    {
        root->rlink=createNode(root->rlink,key);
    }
    return root;
}

NODE * inorder(NODE * root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d ",root->data);
        inorder(root->rlink);
    }
}

NODE * search(NODE * root,int key)
{
    if(root==NULL)
    {
        printf("\nElement not found!");
    }
    else if(key < (root->data))
    {
        root->llink=search(root->llink,key);
    }
    else if(key > (root->data)){
        root->rlink=search(root->rlink,key);
    }
    else{
        printf("\nElement Found!");
    }
    return root;
}


//to find the biggest elem from the left of root.
NODE * inorderpre(NODE * root)
{
    root=root->llink;
    while(root->rlink!=NULL)
    {
        root=root->rlink;
    }
    return root;
}

NODE * delete(NODE * root,int key)
{
    NODE * iPre;
    
    if(root==NULL)
    {
        return NULL;
    }
    if(root->llink==NULL && root->rlink==NULL)
    {
        free(root);
        return NULL;
    }

    if(key<root->data)
    {
        root->llink=delete(root->llink,key);
    }
    else if(key>root->data)
    {
        root->rlink=delete(root->rlink,key);
    }
    else{
        iPre=inorderpre(root);
        root->data=iPre->data;
        root->llink=delete(root->llink,iPre->data);
    }
    return root;
}

int main()
{
    int ch,num;

    while(1)
    {
        printf("\nOPTIONS----->");
        printf("\n1. Insert\n2.Search\n3.Inorder\n4.Exit\n5.Delete");
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter the element to be inserted:");
                scanf("%d",&num);
                root=createNode(root,num);
                break;
            case 2:
                printf("\nEnter the element to be searched:");
                scanf("%d",&num);
                root=search(root,num);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                exit(0);
                break;
            case 5:
                printf("\nEnter the element to be deleted:");
                scanf("%d",&num);
                root=delete(root,num);
                break;
            default:
                printf("invalid choice");
        }
    }

    return 0;
}

