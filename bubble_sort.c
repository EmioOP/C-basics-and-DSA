#include<stdio.h>

void printArray(int *A, int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

void sortArray(int *A, int n){

    int temp;
    int isSorted = 0;
    for (int i = 0; i < n; i++)
    {
        isSorted = 1;

        printf("Number of Passes %d \n",i+1);
       for (int j= 0; j < n-1; j++)
       {
        if(A[j] > A[j+1]){
            temp = A[j];
            A[j]=A[j+1];
            A[j+1] = temp;

            isSorted = 0;
        }
       }

       if(isSorted == 1){
        printf("Array Sorted \n");
        break;
       }
       
    }
    
}

int main(){
    int A[] = {5,6,4,2,8,7,3,1,9,9};
    int n = 10;
    sortArray(A,n);
    printArray(A,n);
    return 0;
}