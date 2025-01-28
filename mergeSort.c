#include<stdio.h>
void swap(int* num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void merge(int lower_bound, int middle_index, int higher_bound, int size_of_array, int array[size_of_array]){
    int index1=lower_bound;
    int index2 = middle_index+1;
    int temp[size_of_array];
    int temp_array_index = lower_bound;
    while(index1<=middle_index && index2<=higher_bound){
        if(array[index1]<=array[index2]){
            temp[temp_array_index] = array[index1];
            index1++;
            temp_array_index++;
        }else{
            temp[temp_array_index] = array[index2];
            index2++;
            temp_array_index++;
        }
    }
    while(index1<=middle_index ){
        temp[temp_array_index] = array[index1];
        index1++;
        temp_array_index++;
        
    }
    while(index2<=higher_bound){
        temp[temp_array_index] = array[index2];
        index2++;
        temp_array_index++;
        
    }

    for (int i = lower_bound; i <= higher_bound; i++) {
        array[i] = temp[i];
    }
}
void merge_sort(int lower_bound, int higher_bound, int size_of_array, int array[size_of_array]){
    if(lower_bound>=higher_bound)return;
    int middle_index = lower_bound+(higher_bound-lower_bound)/2;
    merge_sort(lower_bound,middle_index,size_of_array,array);
    merge_sort(middle_index+1,higher_bound,size_of_array,array);
    merge(lower_bound, middle_index, higher_bound, size_of_array, array);
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

    merge_sort(0,size-1,size, array);
    printf("Finally arrray: ");
    printarray(array,size);
}