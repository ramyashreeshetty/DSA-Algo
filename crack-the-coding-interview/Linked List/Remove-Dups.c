//Problem: Write code to remove duplicates from an unsorted linked list. 1 -> 2 -> 1 ===> 1 -> 2

// removeDuplicate() will remove duplicate nodes from the list.
// Define a new node current which will initially point to head.
// Node temp will point to current and index will always point to node next to current.
// Loop through the list till current points to null.
// Check whether current?s data is equal to index's data that means index is duplicate of current.
// Since index points to duplicate node so skip it by making node next to temp to will point to node next to index, i.e. temp.next = index.next.


#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * link;
}NODE;

NODE * createNode()
{
    NODE * newnode=(NODE *)malloc(sizeof(NODE));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}

NODE * insertatend(NODE * head)
{
    if(head==NULL)
    {
        head=createNode();
    }
    else{
        NODE * ptr=head;
        NODE * new=createNode();
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
    }
    return head;
}


void removeDup(NODE * head)
{
    NODE *curr=head;
    NODE * i,*j;

    printf("Removing duplicates....");

    while(curr!=NULL)
    {
        i=curr;
        j=curr->link;
        while(j!=NULL)
        {
            if(curr->data==j->data)
            {

                if(j->link==NULL)
                {
                    i->link=NULL;
                }
                else{
                i->link=j->link;
                }

            }
            else{
                i=j;
            }
            j=j->link;
        }
        curr=curr->link;

    }

}


void display(NODE * head)  
{  
    struct node *p; 
    int count=0;    
    if(head != NULL)  
    {  
    p=head; 
    printf("\nprinting values . . . . .\n");   
    while (p!=NULL)  
    {  
        printf("\n%d",p->data);  
        p = p -> link; 
        count++; 
    } 
    }
    if(count==0)
    {
        printf("empty");
    }   
}     


void main ()  
{  
    int choice = 0,index,elem,in; 
    NODE * head=NULL; 
    while(choice != 4)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert\n2.Remove dup\n3.show\n4.Exit");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {   
            case 1:  
            head=insertatend(head);         
            break; 
            case 2:
            removeDup(head);
            break; 
            case 3:
            display(head);        
            break;   
            case 4:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  