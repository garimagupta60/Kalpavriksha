#include<stdio.h>
void swap(int* num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int twoPointerSearch(int arr[1000],int size, int low, int high, int key) {
    while (low <= high) {
        if (arr[low] == key)
            return low;
        if (arr[high] == key)
            return high;
        low++;
        high--;
    }
    return -1;
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

    printf("\nEnter element to search\n");
    int key;
    scanf("%d",&key);
    int index = twoPointerSearch(array, size,0,size-1, key);
    if (index == -1)
        printf("Key Not Found");
    else
        printf("Key Found at Index: %d", index);

    return 0;
}