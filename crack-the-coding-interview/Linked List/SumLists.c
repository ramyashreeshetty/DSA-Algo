//Problem: Write code to remove duplicates from an unsorted linked list. 1 -> 2 -> 1 ===> 1 -> 2

// removeDuplicate() will remove duplicate nodes from the list.
// Define a new node current which will initially point to head.
// Node temp will point to current and index will always point to node next to current.
// Loop through the list till current points to null.
// Check whether current?s data is equal to index's data that means index is duplicate of current.
// Since index points to duplicate node so skip it by making node next to temp to will point to node next to index, i.e. temp.next = index.next.


#include <stdio.h>
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


void sumofLL(NODE * head1,NODE * head2)
{

    int num1=0,num2=0,n1=0,n2=0;
    NODE * ptr1=head1;
    NODE * ptr2=head2;
    NODE * head3=NULL;

    //GETTING THE NUMBERS
    while(ptr1!=NULL)
    {
        num1=num1*10+(ptr1->data);
        //printf("\n sum1:%d",num1);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL)
    {
        num2=num2*10+(ptr2->data);
        //printf("\n sum2:%d",num2);
        ptr2=ptr2->link;

    }


    //REVERSING THEM
    while(num1!=0)
    {
        int rem=num1%10;
        n1=n1*10+rem;
        num1=num1/10;
    }
    while(num2!=0)
    {
        int rem=num2%10;
        n2=n2*10+rem;
        num2=num2/10;
    }

    //SUM
    int num3=n1+n2;
    printf("\n sum:%d",num3);

    //Sum as linked list
    NODE * ptr3=head3;
    while(num3!=0)
    {
        int rem = num3 % 10; 

        NODE * newnode=(NODE *)malloc(sizeof(NODE));
        newnode->data=rem;
        newnode->link=NULL;

        newnode->link=head3;
        head3=newnode;

        num3=num3/10;

    }

    //printing the linked list

    struct node *p;     
    if(head3 != NULL)  
    {  
    p=head3; 
    printf("\nprinting values . . . . .\n");   
    while (p!=NULL)  
    {  
        printf("%d->",p->data);  
        p = p -> link; 
    } 
    }

}

void main ()  
{  
    int choice = 0,index,elem,in; 
    NODE * head1=NULL; 
    NODE * head2=NULL;
    while(choice != 4)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert1\n2.Insert2 \n3.Sum of list\n4.Exit");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {   
            case 1:  
            head1=insertatend(head1);         
            break; 
            case 2:
            head2=insertatend(head2);
            break; 
            case 3:
            sumofLL(head1,head2);       
            break;   
            case 4:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  