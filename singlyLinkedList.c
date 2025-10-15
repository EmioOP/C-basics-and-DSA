#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * link;
};

struct Node * head = NULL;

struct Node * createNode(int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void display(){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    struct Node * temp = head;
    printf("Linked List: ");
    while(temp->link != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("%d ",temp->data);
    printf("NULL\n");
}

void insertAtBeginning(int data){
    struct Node * newNode = createNode(data);
    newNode->link = head;
    head = newNode;   
}

void deleteFromBeginning(){
    struct Node * next = head->link;
    printf("Delete Node From Start Containing data = %d",head->data);
    free(head);
    head = next;
}

void deletFromEnd(){
    struct Node * temp = head;
    struct Node * prev;
    while(temp->link != NULL){
        prev = temp;
        temp = temp->link;
    }
    free(temp);
    prev->link = NULL;
}

int main(){

    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtBeginning(40);
    deletFromEnd();
    display();
    return 0;
}