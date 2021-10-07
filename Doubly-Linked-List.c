#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * rlink,*llink;

}NODE;

NODE *createNode()
{
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->rlink=NULL;
    newnode->rlink=NULL;
    return newnode;
}

NODE * insertatbeg(NODE * head)
{

    if(head==NULL)
    {
        head=createNode();
    }
    else{
        NODE * ptr=createNode();
        ptr->rlink=head;
        head->llink=ptr;
        head=ptr;
    }
    return head;
}

NODE * insertatend(NODE * head)
{
    if(head==NULL)
    {
        head=createNode();
    }
    else{
        NODE * ptr=createNode();
        NODE * curr=head;
        while(curr->rlink!=NULL)
        {
            curr=curr->rlink;
        }
        curr->rlink=ptr;
        ptr->llink=curr;
        ptr->rlink=NULL;
    }
    return head;
}

NODE * insertatindex(NODE * head,int index)
{
    int i=0;
    NODE * curr=head;
    NODE * p=head->rlink;
    NODE * ptr=createNode();
    
    while(i!=index-1)
    {
        curr=curr->rlink;
        p=p->rlink;
        i++;
    }
    p->llink=ptr;
    ptr->rlink=p;
    curr->rlink=ptr;
    ptr->llink=curr;
    return head;

}

NODE * display(NODE * head)
{
    int count=0;
    NODE * ptr;
    if(ptr!=NULL)
    {
        ptr=head;
        printf("Displaying elems\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->rlink;
            count++;
        }
    }
    if(count==0){
        printf("empty");

    }
}

NODE * delbeg(NODE * head)
{
    NODE * ptr=head;
    head=head->rlink;
    head->llink=NULL;
    free(ptr);
    return head;
}

NODE * delend(NODE * head)
{
    NODE * p=head;
    NODE * q=head->rlink;

    while(q->rlink!=NULL)
    {
        p=p->rlink;
        q=q->rlink;
    }
    p->rlink=NULL;
    free(q);
    return head;

}

void main ()  
{  
    int choice = 0,index,elem,in; 
    NODE * head=NULL; 
    while(choice != 9)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            head=insertatbeg(head);      
            break;  
            case 2:  
            head=insertatend(head);         
            break;  
            case 3:  
            printf("Enter the index:");
            scanf("%d",&index);
            head=insertatindex(head,index);       
            break; 
            case 4: 
            head=delbeg(head);
            break;
            case 5:
            head=delend(head);
            break;
            case 8:  
            display(head);        
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  