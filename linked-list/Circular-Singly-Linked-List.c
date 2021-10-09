#include <stdlib.h>
#include <stdio.h>


//IMPLEMENTATION OF NODE
typedef struct node{
    int data;
    struct node * link;
}NODE;


//CREATION OF NODE
NODE *createNode()
{
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}


//INSERTION AT THE BEGINNING
NODE * insertatbeg(NODE * head)
{
    if(head == NULL)  
    {  
        head=createNode(); 
        head->link=head;
    }  
    else  
    {  
    NODE * ptr=createNode();
    NODE * curr=head;
    while(curr->link!=head)
    {
        curr=curr->link;
    }
    curr->link=ptr;
    ptr->link=head;
    head=ptr;
    }
    return head;
}


//INSERTION AT THE END
NODE *insertatend(NODE * head)
{
    if(head==NULL)
    {
        head=createNode();
        head->link=head;
    }
    else{

    NODE * ptr=createNode();
    NODE * p=head;

    while(p->link!=head)
    {
        p=p->link;
    }
    p->link=ptr;
    ptr->link=head;
    }
    return head;

}

//DELETE FROM THE BEGINNING

NODE * delbeg(NODE * head)
{
    if(head==NULL)
    {
        printf("empty");
    }
    else{
        NODE * p=head;
        NODE * curr=head;
        while(curr->link!=head)
        {
            curr=curr->link;
        }
        head=head->link;
        free(p);
        curr->link=head;
    }
    return head;
}

NODE * delend(NODE * head)
{

    if(head==NULL)
    {
        printf("empty");
    }
    else if(head->link==head)
    {
        head=NULL;
        free(head);
    }
    else{
    NODE * p;
    NODE * curr=head;

    while(curr->link!=head)
    {
        p=curr;
        curr=curr->link;
    }
    p->link=curr->link;
    free(curr);
    }
    return head;

}



void display(NODE * head)  
{  
    NODE *ptr = head;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->link;
    }while(ptr!=head);
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
        printf("\n1.Insert in begining\n2.Insert at last\n4.Delete from Beginning\n5.Delete from last\n8.Show\n9.Exit\n");  
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