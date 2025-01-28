#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int size_of_array, int array[]) {
    for (int i = size_of_array - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() {
    int array[10000];
    int size = 0;
    while (1) {
        int value;
        if (scanf("%d", &value) != 1) { 
            break;
        }
        array[size] = value;
        size++;
        int ch = getchar();
        if (ch == '\n' || ch == EOF) { 
            break;
        }
    }
    if (size == 0) {
        printf("No elements in the array.\n");
        return 0;
    }
    int key;
    scanf("%d", &key);
    bubble_sort(size, array);
    printf("Sorted array:");
    for(int i=0; i<size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    int index = binarySearch(array, 0, size - 1, key);
    if (index == -1)
        printf("Key Not Found\n");
    else
        printf("Key Found at Index: %d\n", index);

    return 0;
}
