// Problem: Given a linked list and a value x, partition it such that all nodes
//  * less than x come before nodes greater than or equal to x. You should preserve
//  * the original relative order of the nodes in each of the two partitions.
//  * 
//  * For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.

//Here basically values less than 3 should appear before it so we'll have a seprate LL for it.
//values greater or equal to 3 will have no change(we have preserve their order.)


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


void Partition(NODE * head)
{

    int p;
    printf("Enter the partition:");
    scanf("%d",&p);

    NODE * first=NULL;
    NODE * sec=NULL;

    NODE * ptr=head;

    while(ptr!=NULL)
    {
        if((ptr->data)<p)
        {
            if(first==NULL)
            {
                NODE * newnode=(NODE *)malloc(sizeof(NODE));
                newnode->data=ptr->data;
                newnode->link=NULL;
                first=newnode;
            }
            else{

                NODE * newnode=(NODE *)malloc(sizeof(NODE));
                newnode->data=ptr->data;
                newnode->link=NULL;
                NODE * f=first;
                while(f->link!=NULL)
                {
                    f=f->link;
                }
                f->link=newnode;
                
            }

        }
        else{

            if(sec==NULL)
            {
                NODE * newnode=(NODE *)malloc(sizeof(NODE));
                newnode->data=ptr->data;
                newnode->link=NULL;
                sec=newnode;
            }
            else{
                NODE * newnode=(NODE *)malloc(sizeof(NODE));
                newnode->data=ptr->data;
                newnode->link=NULL;
                NODE * s=sec;
                while(s->link!=NULL)
                {
                    s=s->link;
                }
                s->link=newnode;
                
            }

        }
        ptr=ptr->link;
    }


    //sort
    NODE * current=first;
    NODE * index=NULL;
    while(current != NULL) {  
                //Node index will point to node next to current  
                index = current->link;  
                  
                while(index != NULL) {  
                    //If current node's data is greater than index's node data, swap the data between them  
                    if(current->data > index->data) {  
                        int temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                    }  
                    index = index->link;  
                }  
                current = current->link;  
            }      

    //COncatenate
    NODE * curr=first;
    while(curr->link!=NULL)
    {
        curr=curr->link;
    }    
    curr->link=sec;


    printf("Displaying partition:");
    struct node *ip; 
    if(first != NULL)  
    {  
    ip=first; 
    printf("\nprinting values . . . . .\n");   
    while (ip!=NULL)  
    {  
        printf("%d -> ",ip->data);  
        ip = ip -> link; 
    } 
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
        printf("\n1.Insert\n2.Partition \n3.show\n4.Exit");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {   
            case 1:  
            head=insertatend(head);         
            break; 
            case 2:
            Partition(head);
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