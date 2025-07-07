#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE];
int front=-1,rear = -1;


int isFull(){
    if(rear == SIZE - 1){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front == -1){
        return 1;
    }

    return 0;
}


void enqueue(int val){
    if(isFull()){
        printf("Queue Overflow\n");
        return;
    }else if(isEmpty()){
        front = 0;
        rear = 0;
        queue[rear] = val;
        printf("Added %d to Queue (first insertion)\n",val);
    } else{
        rear = rear+1;
        queue[rear] = val;
        printf("Added %d to Queue\n",val);
    }
    

}

void dequeue(){
    if(isEmpty()){
        printf("Queue underflow\n");
        return;
    }else if(front == rear){
        printf("Popped %d from queue\n",queue[front]);
        front = -1;
        rear = -1;
    } else{
        printf("Popped %d from queue\n",queue[front]);
        front = front +1;
    }
}

void displayQueue(){
    if(isEmpty()){
      printf("Empty Queue\n");
    }else{
        printf("Queue:\n");
        for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]); 
        }
    }
    
}

int main(){
    int choice,val;
    
    while (1)
    {
        printf("Queue Operations\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter Your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the value to push: ");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid Selection\n");

        }
    }
    
    
}