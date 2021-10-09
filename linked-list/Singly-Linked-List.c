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
    }  
    else  
    {  
    NODE * ptr=createNode();
    ptr->link=head;
    head=ptr;
    }
    return head;
}


//INSERTION AT THE INDEX
NODE * insertatindex(NODE * head,int index)
{
    NODE * ptr=createNode();
    NODE * p=head;
    int i=0;
    //over here i comes till one index before the place where node should be inserted
    while(i!=index-1)
    {
        p=p->link;
        i++;
    }
    ptr->link=p->link;
    p->link=ptr;
    return head;


}


//INSERTION AT THE END
NODE *insertatend(NODE * head)
{
    if(head==NULL)
    {
        head=createNode();
    }
    else{

    NODE * ptr=createNode();
    NODE * p=head;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=ptr;
    }
    return head;

}

//DELETE FROM THE BEGINNING

NODE * delbeg(NODE * head)
{
    NODE * ptr=head;
    head=head->link;
    free(ptr);
    return head;
}

NODE * delend(NODE * head)
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

NODE * delindex(NODE * head,int index)
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
    int item,i=0,flag=0;  
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
            else  
            {  
                flag=1;  
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
    while(choice != 9)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");  
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
            case 6:
            printf("Enter the index:");
            scanf("%d",&in);
            head=delindex(head,in);
            break;
            case 7:
            search(head);
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