//Basically finding the kth no from the end of the linked list.
// Original List : ->1->2->8->3->7->0->4
// Output : 3rd Element from the end is : 7


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


void myKth(NODE * head)
{
    int k,len=0,n;
    printf("Enter the kth value:");
    scanf("%d",&k);

    NODE * ptr=head;
    NODE * jum=head;

    while(ptr->link!=NULL)
    {
        len++;
        ptr=ptr->link;
    }

    n=len-k;

    for(int i=0;i<=n;i++)
    {
        jum=jum->link;
    }
    printf("Kth no is:%d",jum->data);

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
        printf("\n1.Insert\n2.Kth value\n3.show\n4.Exit");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {   
            case 1:  
            head=insertatend(head);         
            break; 
            case 2:
            myKth(head);
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