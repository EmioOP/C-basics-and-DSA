#include<stdio.h>

void printArray(int *a, int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void sortArray(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        int minIndex = i; // for checking in index the small number is.
        for (int j = i; j < n; j++)//taking j = i array because we dont want to check i th element after the i th iteration because its already sorted
        {
           if(a[j]<a[minIndex]){
            minIndex = j; //checking if the j-th element value is less than the min index value if that the min index is changed to j
           }
        }
        //swap the elements
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
        
    }
    
}
int main(){
    int a[] = {3,2,4,1,5,8,6,7,9,10};
    int n = 10;

    sortArray(a,n);
    printArray(a,n);

    return 0;
}