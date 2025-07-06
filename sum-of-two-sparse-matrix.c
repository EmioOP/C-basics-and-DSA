#include<stdio.h>
#define MAX 100

typedef struct{
    int row;
    int col;
    int value;
} Triplet;


void addSparseMatrix(Triplet A[],Triplet B[],Triplet C[]){
    int i=1 ,j=1 ,k = 1;
    //seting meta data the same
    C[0].row = A[0].row;
    C[0].col = A[0].col;

    while (i<= A[0].value && j<=B[0].value)//i and j should be less than or equal to the number of non zero elements in that matrix
    {
        if(A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)){
            C[k++] = A[i++];  //this IF checks the which element will come first so that one will be pushed to Resultant matrix

        }else if(B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)){
            C[k++] = B[j++]; //this IF checks the which element will come first so that one will be pushed to Resultant matrix
        } else{
            int sum = A[i].value + B[j].value; // here we can assume that the elements are in same index of two matrix so add it and set to value of C[k]
            if(sum != 0){
                C[k].row = A[i].row;
                C[k].col = A[i].col;
                C[k].value = sum;
                k++;
            }
            i++;
            j++;
        }
        
    }
    while(i<=A[0].value){
        C[k++]=A[i++];
    }

    while (j <= B[0].value)
    {
        C[k++] = B[j++];
    }

    C[0].value = k-1;

}

void printTriplet(Triplet M[]) {
    printf("Row Col Val\n");
    for (int i = 0; i <= M[0].value; i++) {
        printf("%3d %3d %4d\n", M[i].row, M[i].col, M[i].value);
    }
}


int main(){


    Triplet A[MAX] = {
        {3, 3, 3},
        {0, 0, 5},
        {1, 1, 8},
        {2, 2, 9}
    };

    Triplet B[MAX] = {
        {3, 3, 3},
        {0, 0, 3},
        {1, 2, 7},
        {2, 2, -9}
    };

    Triplet C[MAX];


    addSparseMatrix(A, B, C);

    printf("Matrix A:\n");
    printTriplet(A);

    printf("\nMatrix B:\n");
    printTriplet(B);

    printf("\nResulting Matrix C (A + B):\n");
    printTriplet(C);


    return 0;
}