#include<stdio.h>
void swap(int* num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int partition(int lower_bound, int higher_bound, int size_of_array, int array[size_of_array]){
    int pivot = array[lower_bound];
    int i = lower_bound;
    int j= higher_bound;
    while(i<j){
        while(array[i]<=pivot && i<=j){
            i++;
        }
        while(array[j]>pivot && j>=i){
            j--;
        }
        if(i<j)swap(&array[j],&array[i]);
    }
    swap(&array[j],&array[lower_bound]);
    return j;
} 
void quicksort(int lower_bound, int higher_bound, int size_of_array, int array[size_of_array]){
    if(lower_bound>=higher_bound)return;
    int pivot_index = partition(lower_bound, higher_bound, size_of_array, array);
    quicksort(lower_bound,pivot_index-1,size_of_array,array);
    quicksort(pivot_index+1,higher_bound,size_of_array,array);
}

void printarray(int array[100], int size){
    for(int index = 0; index<size; index++){
        printf("%d ",array[index]);
    }
}
int main(){
    int array[1000];
    int size = 0;
    while(1){
        int value;
        if(scanf("%d",&value)!=1){
            break;
        }
        array[size] = value;
        size++;
        char ch = getchar();
        if(ch == '\n' || ch == EOF){
            break;
        }
    }
    printf("Initially arrray: ");
    printarray(array,size);

    quicksort(0,size-1,size, array);
    printf("Finally arrray: ");
    printarray(array,size);
}