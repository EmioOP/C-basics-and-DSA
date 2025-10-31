#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * header = NULL;


struct Node * createNode(int data){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node * insertAtBegining(int data){
    if(header == NULL){
        header = createNode(data);
        return header;
    }

    struct Node * newNode = createNode(data);
    newNode->next = header;
    header = newNode;

    return header;
}

void printList(struct Node * temp){
    if(header == NULL){
        printf("The list is empty");
        return;
    }
    // struct Node * temp = header;
    while (temp != NULL)
    {
        printf("%d-",temp->data);
        temp = temp->next;
    }
    printf("NULL");
    
}

struct Node * spliList(int data){
    if(header == NULL){
        printf("List is empty");
    }

    struct Node * temp = header;
    struct Node * prev = NULL;
    while(temp != NULL){
        if(temp->data == data){
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    return temp;


}

void insertAtEnd(struct Node * temp ,int data ){
    if(temp == NULL){
        temp = createNode(data);
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = createNode(data);

}

int main(){

    struct Node * newList ;

    //We can get user input and perform operations
    insertAtBegining(10);
    insertAtBegining(9);
    insertAtBegining(8);
    insertAtBegining(7);
    insertAtBegining(6);
    insertAtBegining(5);
    //list before spliting
    printList(header);

    newList = spliList(8); // spliting list where data is 8
    printf("\nSplitted List:\n");
    printList(header);
    printf("\n");
    printList(newList);

    insertAtEnd(header,70);// adding 70 to the end of first half split
    printf("\n");
    printList(header);

    
    

    return 0;
}