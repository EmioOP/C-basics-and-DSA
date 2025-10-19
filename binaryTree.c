#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};


struct Node * createNode(int data){
    struct Node * newNode = (struct Node * )malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node * createTree(){
    int data;

    printf("Enter the data (-1 for no node)");
    scanf("%d",&data);

    if(data == -1){
        return NULL;
    }

    struct Node * newNode = createNode(data);

    printf("enter the left child: ");
    newNode->left = createTree();

    printf("Enter right child: ");
    newNode->right = createTree();

    return newNode;
}

void inorder(struct Node * root ){
    if(root){
        inorder(root->left);
        printf("%d-",root->data);
        inorder(root->right);
    }
}

void preorder(struct Node * root){
    if(root){
        printf("%d-",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node * root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d-",root->data);
    }
}

int main(){
    struct Node * root = NULL;
    printf("Create the binary tree:\n");
    root = createTree();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");
    return 0;

}