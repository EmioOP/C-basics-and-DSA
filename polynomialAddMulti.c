#include<stdio.h>
#include<stdlib.h>



struct Node {
    int coeff;
    int pow;
    struct Node * next;

};


struct Node * createNode(int coeff,int pow){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;

}

struct Node * insertNode(struct Node* root,int coeff,int pow){
    
    if(root == NULL){
        return createNode(coeff,pow);
    }
    struct Node * newNode = createNode(coeff,pow);
    struct Node * temp = root;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    return root;
}


struct Node * readPoly(){
    struct Node * result = NULL;
    int n;
    int coeff;
    int pow;
    printf("Enter the number of terms ");
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        printf("Enter Coeff and Pow: ");
        scanf("%d %d",&coeff,&pow);
        
        result = insertNode(result,coeff,pow);
    }

    return result;
}

void display(struct Node * root){
    if(root == NULL){
        printf("Empty!..\n");
        return;
    }

    while (root != NULL)
    {
       printf("%dX^%d",root->coeff,root->pow);
       if(root->next !=NULL){
        printf(" + ");
       }
       root = root->next;
    }
    printf("\n");
    return;
    
}

struct Node * addPoly(struct Node * poly1,struct Node * poly2){
    struct Node * result = NULL;

    while(poly1 != NULL && poly2 != NULL){
        
        if(poly1->pow == poly2->pow){
            result = insertNode(result,(poly1->coeff+poly2->coeff),poly1->pow);
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
    while(poly2 != NULL){
        result = insertNode(result,poly2->coeff,poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}

struct Node * multiply(struct Node * poly1,struct Node * poly2){
    struct Node * result = NULL;
    struct Node * p2;
    while(poly1 != NULL){
        p2 = poly2;
        while(p2 != NULL){
            
            int coeff = poly1->coeff * p2->coeff;
            int pow = poly1->pow + p2->pow;

            struct Node * temp = NULL;
            temp = insertNode(temp,coeff,pow);
            result = addPoly(result,temp);
            p2 = p2->next;

        }
        poly1 = poly1->next;
    }
    return result;
}

int main(){
    struct Node * poly1 =  readPoly();
    struct Node * poly2 = readPoly();

    display(poly1);
    display(poly2);

    // struct Node * addition = addPoly(poly1,poly2);

    // display(addition);

    struct Node * multi = multiply(poly1,poly2);

    display(multi);
    
    return 0;
}
