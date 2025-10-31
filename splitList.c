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

    int choice,value;
    while(1){
        printf("\n---Menu---\n1.Insert Value\n2.Insert Value in end\n3.Split List\n4.Display\n5.Exit\nSelect Your Coice");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to insert at begining: ");
                scanf("%d",&value);
                insertAtBegining(value);
                break;
            case 2:
                printf("Enter the value to insert at end: ");
                scanf("%d",&value);
                insertAtEnd(header,value);
                break;

            case 3:
                printf("Enter the element from to split: ");
                scanf("%d",&value);
                printf("The original list: ");
                printList(header);
                newList = spliList(value);
                break;
            case 4:
                printf("The Splitted Lists:\n");
                printList(header);
                printf("\n");
                printList(newList);
                break;
            case 5:
                printf("Exiting the program...");
                exit(0);
            default:
            printf("Invalid Inpit..\n");
        }
    }

    
    

    return 0;
}