#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data[100];
    struct Node * left;
    struct Node * right;
};

struct Node * current = NULL;


struct Node * createNode (char * url){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data,url);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node * visitPage(char * url){
    struct Node * newNode = createNode(url);
    if(current != NULL && current->right != NULL){
        struct Node * temp = current;
        while(temp->right != NULL){
            struct Node * next = temp;
            free(temp);
            temp = next;
        }
        current->right = NULL;
    }

    if(current != NULL){
        current->right = newNode;
        newNode->left = current;
        newNode->right = NULL;
    }

    current = newNode;

    printf("Visited %s\n",url);


}


struct Node * goBack(){
    if(current != NULL && current->left != NULL){
        current = current->left;
        printf("Moved Backwords to page %s\n",current->data);
    }else{
        printf("No previous page\n");
    }
}

struct Node * goForword(){
    if(current != NULL && current->right != NULL){
        current = current->right;
        printf("Moved Forword To %s \n",current->data);
    }else{
        printf("There is no next page");
    }
}

struct Node * showCurrent(){
    if(current != NULL){
        printf("Current Page %s\n",current->data);
    }else{
        printf("No page visited");
    }
}

struct Node * showHistory(){
    if(current != NULL){
        struct Node * temp = current;

        while(temp->left != NULL){
            temp=temp->left;
        }

        while(temp != NULL){
            if(temp == current){
                printf("[%s] ",temp->data);
            }else{
                printf("%s ",temp->data);
            }
            temp= temp->right;


            


            

            
            
            
        }

    }
}
int main(){
    visitPage("google.com");
    visitPage("youtube.com");
    visitPage("insta.com");
    // showCurrent();
    // goBack();
    // showCurrent();
    // goForword();
    // showCurrent();
    showHistory();
}