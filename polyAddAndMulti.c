#include<stdio.h>
#include<stdlib.h>

// create a srtucture with coeff pow and next link

struct Node {
    int coeff;
    int pow;
    struct Node * next;
};

// create a new Node with coeff and expo
struct Node * createNode(int coeff,int pow){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

//insert a node at end
struct Node * insertNode(struct Node * head,int coeff,int pow){
    struct Node * newNode = createNode(coeff,pow);
    

    //check if there is anything in the head.if no it is the first node creation
    if(head == NULL){
        return newNode;
    }

    //if something is there in the head

    struct Node * temp = head;

    //this loop will traverse till the last node by looking for the null in the link part(here we call it as next).
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

struct Node * readPoly(){
    struct Node * poly = NULL;
    int n,coeff,pow;

    printf("Enter number of terms: ");
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        printf("Enter the coeff and power: ");
        scanf("%d %d",&coeff,&pow);
        poly = insertNode(poly,coeff,pow);
    }

    return poly;
}


void display(struct Node * head){
    if(!head || head == NULL){
        printf("Empty! OR no polynomial\n");
        return ;
    }
    printf("Polynomial:  ");
    while(head != NULL){
        printf("%dX^%d",head->coeff,head->pow);
        head = head->next;
        if(head != NULL && head->coeff >= 0){
            printf("+");
        }
    }
    printf("\n");

}

struct Node * addPoly(struct Node * poly1,struct Node * poly2){
    struct Node * result =NULL;
    while(poly1 != NULL && poly2 != NULL){
        if(poly1->pow == poly2->pow){
            result = insertNode(result,poly1->coeff + poly2->coeff,poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }else if(poly1->pow > poly2->pow){
            result = insertNode(result,poly1->coeff,poly1->pow);
            poly1 = poly1->next;
        }else if(poly2->pow > poly1->pow){
            result = insertNode(result,poly2->coeff,poly2->pow);
            poly2 = poly2->next;
        }
    }

    while(poly1 != NULL){
        result = insertNode(result,poly1->coeff,poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        result = insertNode(result,poly2->coeff,poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

struct Node * multiplyPoly(struct Node * poly1,struct Node * poly2){
    struct Node * result = NULL;
    struct Node * temp = poly2;
    while(poly1 != NULL){
        printf("poly1 -coeff 1st while --%d \n",poly1->coeff);
        while(temp != NULL){
            printf("poly2-coeff 2nd while --%d \n",poly2->coeff);
            result = insertNode(result,poly1->coeff * temp->coeff,poly1->pow + temp->pow);
             temp = temp->next;
        }
        temp = poly2;
        poly1 = poly1->next;
    }


    return result;
    
}

int main(){
    struct Node * poly1 = readPoly();
    struct Node * poly2 = readPoly();
    struct Node * sum = addPoly(poly1,poly2);
    struct Node * product = multiplyPoly(poly1,poly2);

    display(poly1);
    display(poly2);
    display(product);
    return 0;

}