#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}NODE;

NODE * createnode(int val)
{
    NODE * newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void postorder(NODE * root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{ 
    NODE *p = createnode(4);
    NODE *p1 = createnode(1);
    NODE *p2 = createnode(6);
    NODE *p3 = createnode(5);
    NODE *p4 = createnode(2);


    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  


    // Linking the root node with left and right children

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    postorder(p);
    return 0;
}