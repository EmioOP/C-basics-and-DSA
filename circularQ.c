#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear =  -1;


int isEmpty(){
    if(front == -1){
        return 1;
    }
    return 0;
}

int isFull(){
    if((rear+1)%SIZE == front){
        return 1;
    }
    return 0;
}


void enqueue(int value){
    if(isFull()){
        printf("Queue is full\n");
        return;
    }else if(front == -1){
        rear = 0;
        front = 0;
    }else {
        rear = (rear+1) % SIZE;
    }
    printf("Inserted %d to queue\n",value);
    queue[rear] = value;
    return;
}

void dequeue(){
    if(isEmpty()){
        printf("Queue Is Empty...\n");
        return ;
    }else if(front == rear){
        int temp = front;
        front = -1;
        rear = -1;
        printf("deleted%d from queue\n",queue[temp]);
    }else{
        int temp = front;
        front = (front + 1) % SIZE;
        printf("deleted%d from queue\n",queue[temp]);
    }
}

void display(){
    if(isEmpty()){
        printf("Empty queue\n");
        return;
    }
    int i =front;
    while(i != rear){
        printf("%d ",queue[i]);
        i = (i+1)%SIZE;
    }
    printf("%d\n",queue[rear]);
}



int main(){
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(9);//queue will overflow

    display();

    dequeue();
    dequeue();

    enqueue(10);
    enqueue(11);

    dequeue();

    display(); 

    dequeue();
    dequeue();
    dequeue();
    dequeue();// queue will be empty
    
    display(); 
    
    return 0;
}