#include<stdio.h>

#define MAX 15 // defining maximum size of the matrix

int main(){
    int a[MAX+1][3],at[MAX+1][3],i,j,k,n; //initializing matrix a,at and vaiables i,j,k,n
    printf("Enter the size of the matrix"); //enter size like  4 5
    scanf("%d%d",&a[0][0],&a[0][1]); //getting size from the user
    printf("Enter the number of non zero elements");
    scanf("%d",&n);  // entering the non zero elements in the and storing in variable n
    a[0][2] = n; // n stored to the 3 rd element of meta data

    printf("Enter each value of the sparse matrix as %d triplets(row,column,value)\n",n);

    for(i=1;i<=n;i++){
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]); //getting matrix elements from the user
    }

    //creating transpose of the matrix a to matrix at
    at[0][0] = a[0][1]; 
    at[0][1] = a[0][0];
    at[0][2] = a[0][2];

    k=1; // will be used later

    //loop for inter chnaging rows and columns by the sorted order
    for(i=0;i<=n;i++){
        for(j=1;j<=n;j++){
            //j should be 1 because 0 th row is used for meta data not needed to traverse through it
            if(a[j][1] == i ){
                at[k][0] = a[j][1];
                at[k][1] = a[j][0];
                at[k][2] = a[j][2];
                k++;
            }
        }
    }

    printf("\nThe transpose \n\nRow\tColumn\tValue\n");
    for(i=0;i<=n;i++){
        printf("%d\t%d\t%d\n",at[i][0],at[i][1],at[i][2]);
    }

}

