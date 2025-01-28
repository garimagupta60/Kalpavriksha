#include<stdio.h>
int linearSearch(int array[10000], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}
int main(){
    int array[10000];
    int size = 0;
    while(1){
        int value;
        if(scanf("%d",&value)!=1){
            break;
        }
        array[size] = value;
        size++;
        int ch = getchar();
        if(ch == '\n' || ch == EOF){
            break;
        }
    }

    int key;
    scanf("%d",&key);
    int index = linearSearch(array, size, key);
    if (index == -1)
        printf("Key Not Found");
    else
        printf("Key Found at Index: %d", index);

    return 0;
}