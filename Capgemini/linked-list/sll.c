#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * link;
}NODE;

NODE * createnode()
{
    NODE * newnode=(NODE*)malloc(sizeof(NODE));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}

NODE * insertatbeg(NODE * head)
{
    if(head==NULL)
    {
        head=createnode();

    }
    else{
        NODE * newnode=createnode();
        newnode->link=head;
        head=newnode;
    }
    return head;
}

NODE * insertatend(NODE * head)
{
    NODE * curr=head;
    if(head==NULL)
    {
        head=createnode();
    }
    else{
        NODE * ptr=createnode();
        while(curr!=NULL)
        {
            curr=curr->link;
        }
        curr->link=ptr;
    }
    return head;
}

NODE * insertatindex(NODE * head,int index)
{
    NODE * curr=head;
    NODE * ptr=createnode();
    int i=0;
    while(i!=index-1)
    {
        curr=curr->link;
        i++;
    }
    ptr->link=curr->link;
    curr->link=ptr;
    return head;
}

NODE * delatbeg(NODE * head)
{
    NODE * ptr=head;
    head=ptr->link;
    free(ptr);
    return head;
}

NODE * delatend(NODE * head)
{
    NODE * p=head;
    NODE * q=head->link;

    while(q->link!=NULL)
    {
        p=p->link;
        q=q->link;
    }
    p->link=NULL;
    free(q);
    return head;
}

NODE * delatindex(NODE * head,int index)
{
    NODE * p=head;
    NODE * q=head->link;
    int i=0;

    while(i!=index-1)
    {
        p=p->link;
        q=q->link;
        i++;
    }
    p->link=q->link;
    free(q);
    return head;

}

NODE * search(NODE * head)
{
    NODE *ptr;  
    int item,i=0,flag=1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
            }
            i++;  
            ptr = ptr -> link;  
        }  
        if(flag==1)  
        {  
            printf("Item not found\n");  
        }  
    }     
}

void display(NODE * head)
{
    NODE * curr=head;
    if(head==NULL)
    {
        printf("empty");
    }
    while(curr!=NULL)
    {
        printf("%d\n",curr->data);
        curr=curr->link;
    }
}