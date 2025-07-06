#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(struct stack * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    } else{
        return 0;
    }
}

void push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack overFlow \n");
    }else{
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = val;
        printf("Pushed %d To Stack\n",val);
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow \n");
    }else{
        int poppedValue = ptr->arr[ptr->top];
        ptr->top = ptr->top-1;
        printf("Popped % d from Stack \n",poppedValue);
        return poppedValue;
    }
}

void printStack(struct stack * ptr){
    printf("Stack Elements: \n");
    for(int i =0;i<ptr->size;i++){
        printf("\t%d\n",ptr->arr[i]);
    }
}

int main(){
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int * ) malloc(s->size * sizeof(int));

    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    push(s,10);
    
    printf("After push Full: %d \n",isFull(s));
    printf("After push Empty: %d \n",isEmpty(s));

    pop(s);
    pop(s);
    pop(s);
    pop(s);

    printf("After pop Full: %d \n",isFull(s));
    printf("After pop Empty: %d \n",isEmpty(s));


    printStack(s);


    return 0;
}