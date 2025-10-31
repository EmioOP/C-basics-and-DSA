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

    struct Node * newList = spliList(8);

    //We can get user input and perform operations
    // insertAtBegining(10);
    // insertAtBegining(9);
    // insertAtBegining(8);
    // insertAtBegining(7);
    // insertAtBegining(6);
    // insertAtBegining(5);
    // printList(header);
    // printf("\nSplitted List:\n");
    // printList(header);
    // printf("\n");
    // printList(newList);
    // insertAtEnd(header,70);
    // printf("\n");
    // printList(header);

    int choice,value;
    while(1){
        printf("---Menu---\n1.Insert Value\n2.Split List\n3.exit:\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d",&value);
                insertAtBegining(value);
                break;            case 2:
                printf("Enter the element from to split: ");
                scanf("%d",&value);
                newList = spliList(value);
                break;
            case 3:
                printf("Exiting the program...");

            case 4:
                printf("Exiting the program...");
                exit(0);
            default:
            printf("Invalid Inpit..\n");
        }
    }
    

    return 0;
}