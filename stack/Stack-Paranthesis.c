#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    char * arr;
}STACK;

int isempty(STACK * sp)
{
    if(sp->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(STACK * sp)
{
    if(sp->top==sp->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(STACK * sp,char val)
{
    if(isfull(sp))
    {
        printf("overflow...");
    }
    else{
        sp->top++;
        sp->arr[sp->top]=val;
    }
}

char pop(STACK * sp)
{
    if(isempty(sp))
    {
        printf("underflow...");
        return 0;
    }
    else{
        char val=sp->arr[sp->top];
        sp->top--;
        return val;
    }
}

int paramatch(char * exp)
{
    STACK * ptr;
    ptr->size=100;
    ptr->top=-1;
    ptr->arr=(char *)malloc(ptr->size * sizeof(char));

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            push(ptr,'(');
        }
        else if(exp[i]==')'){

            if(isempty(ptr))
            {
                return 0;
            }
            pop(ptr);
        }
    }

    if(isempty(ptr)){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    char * exp = "(((7+8)";
    // Check if stack is empty
    if(paramatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}