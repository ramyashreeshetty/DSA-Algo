struct Stack
{
    int ptr;
    unsigned capacity;
    int *arr;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->ptr = -1;
    stack->arr = (int*)malloc(sizeof(int)*capacity);
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->ptr < 0;
}

void push(struct Stack *stack, int item)
{
    stack->arr[++stack->ptr] = item;
}

int peek(struct Stack *stack)
{
    return stack->arr[stack->ptr];
}

int pop(struct Stack *stack)
{
    return stack->arr[stack->ptr--];
}

int stackSize(struct Stack *stack)
{
    int size = stack->ptr + 1;
    return size;
}

// The solution starts here. The above code implements the stack function in C.
struct Stack *stack = NULL;

void collision(int curr)
{
    while (!isEmpty(stack)) {
        if (peek(stack) + curr == 0) {
            pop(stack);
            return;
        } else if (peek(stack) > 0 && peek(stack) > - curr) {
            return;
        } else if (peek(stack) < 0) {
            push(stack, curr);
            return;
        } else {
            pop(stack);
        }
    }
    push(stack, curr);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize){
    stack = createStack(asteroidsSize);
    
    for (int i = 0; i < asteroidsSize; i++) {
	    // There are three cases which the collision will not happen.
        if (isEmpty(stack) || asteroids[i] > 0 || peek(stack) < 0) {
            push(stack, asteroids[i]);
        } else {
            // collision
            collision(asteroids[i]);
        }
    }
    
    
    int size = stackSize(stack);
    int *res = (int*)malloc(sizeof(int)*size);
    for (int i = size - 1; i >= 0; i--) {
        res[i] = pop(stack);
    }
    *returnSize = size;
    return res;
}