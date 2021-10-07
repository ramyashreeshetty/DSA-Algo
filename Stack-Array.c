#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
}STACK;

// STACK * createStack(int size)
// {
//     STACK * stack = (STACK*)malloc(sizeof(STACK));
//     stack->size = size;
//     stack->top = -1;
//     stack->arr = (int*)malloc(stack->size* sizeof(int));
//     return stack;
    
// }

int isempty(STACK * ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(STACK* ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(STACK* ptr,int val)
{
    if(isfull(ptr))
    {
        printf("overflow...");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(STACK * ptr)
{
    if(isempty(ptr))
    {
        printf("underflow...");
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }

}

void display(STACK * ptr)
{
    printf("displaying\n");
    while(ptr->top!=-1)
    {
        printf("%d\n",ptr->arr[ptr->top]);
        ptr->top--;
    }
}

//peek gives the value in certain position not index
//index=top-position+1

int peek(STACK * sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}


void main ()  
{  
    STACK *sp = (STACK *) malloc(sizeof(STACK));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);

    //display(sp);

    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!


    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }

}   

