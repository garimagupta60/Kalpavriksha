#include<stdio.h>
void swap(int* num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void selectionSort(int array[100], int size){
    for(int index = 0; index<size; index++){
        int mini = index;
        for(int index2 = index; index2<size; index2++){
            if(array[index2]<array[mini]){
                mini = index2;
            }
        }
        swap(&array[index],&array[mini]);
    }
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

    selectionSort(array,size);
    printf("Finally arrray: ");
    printarray(array,size);
}