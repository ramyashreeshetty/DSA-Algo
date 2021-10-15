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


void palindrome(NODE * head1)
{

    int num1=0,num2=0,n1=0,n2=0;
    NODE * ptr1=head1;

    //GETTING THE NUMBERS
    while(ptr1!=NULL)
    {
        num1=num1*10+(ptr1->data);
        ptr1=ptr1->link;
    }
    //printf("\n sum1:%d",num1);

    int temp=num1;
    //REVERSING THEM
    while(num1!=0)
    {
        int rem=num1%10;
        n1=n1*10+rem;
        num1=num1/10;
    }
    //printf("\n sum2:%d",n1);
    
    if(temp==n1)
    {
        printf("\n palindrome");
    }
    else{
        printf("\n hell no");
    }

}

void main ()  
{  
    int choice = 0,index,elem,in; 
    NODE * head1=NULL; 
    NODE * head2=NULL;
    while(choice != 3)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert1\n2.Palindrome\n3.Exit");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {   
            case 1:  
            head1=insertatend(head1);         
            break; 
            case 2:
            palindrome(head1);
            break;         
            case 3:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  