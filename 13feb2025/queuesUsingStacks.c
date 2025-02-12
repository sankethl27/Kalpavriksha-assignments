typedef struct {
    int top;
    int arr[110];
} stack;

typedef struct {
    stack *s1;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue *obj = malloc(sizeof(MyQueue));
    obj->s1 = malloc(sizeof(stack));
    obj->s1->top = -1;
    return obj;
}
int pop(stack *s)
{
    int x = s->arr[s->top];
    s->top--;
    return x;
}
int isEmpty(stack *s)
{
    return s->top == -1;
}
void myQueuePush(MyQueue* obj, int x) {
    obj->s1->top++;
    obj->s1->arr[obj->s1->top] = x;
}

int myQueuePop(MyQueue* obj) {
    if(obj->s1->top == 0)
    {
        return pop(obj->s1);
    }
    int x = pop(obj->s1);
    int returnVal = myQueuePop(obj);
    myQueuePush(obj,x);
    return returnVal;
}

int myQueuePeek(MyQueue* obj) {
    if(obj->s1->top == 0)
    {
        return obj->s1->arr[obj->s1->top];
    }
    int x = pop(obj->s1);
    int returnVal = myQueuePeek(obj);
    myQueuePush(obj,x);
    return returnVal;
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/