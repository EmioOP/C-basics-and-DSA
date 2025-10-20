#include<stdio.h>
#define MAX 20


void bubbleSort(int * A,int n){
    for(int i =0; i<n;i++){
        for (int j = 0; j < n-1-i; j++)
        {
           if(A[j] > A[j+1]){
            int temp = A[j];
            A[j] = A[j+1];
            A[j+1] = temp;
           }
        }
        
    }
}

void printArray(int * A,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
}

void insertToArray(int * A,int n){
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    
}

int main(){
    int A[MAX];
    int n ;
    printf("Enter Number of Elements: ");
    scanf("%d",&n);
    printf("Enter Array Elements: ");
    insertToArray(A,n);
    bubbleSort(A,n);
    printf("Sorted Array: ");
    printArray(A,n);
    return 0;
}