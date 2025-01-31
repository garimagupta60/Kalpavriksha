#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int front;
    int rear;
    int *array;
    int size;
}queue;

queue* createQueue(int size){
    queue* newqueue = (queue*)malloc(sizeof(queue));
    if(newqueue == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newqueue->front = -1;
    newqueue->rear = -1;
    newqueue->size = size;
    newqueue->array = (int*)malloc(sizeof(int)*newqueue->size);
    return newqueue;
}

int isEmpty(queue* newqueue){
    if(newqueue->front == -1)return 1;
    return 0;
}
int isFull(queue* newqueue){
    if(newqueue->rear == newqueue->size-1)return 1;
    return 0;
}
void enqueue(queue* newqueue, int value){
    if(isFull(newqueue)){
        printf("Overflow\n");
        return;
    }
    if(isEmpty(newqueue)){
        newqueue->front = 0;
    }
        newqueue->rear++;
        newqueue->array[newqueue->rear] = value;
}

void dequeue(queue* newqueue){
    if(isEmpty(newqueue)){
        printf("Underflow\n");
        return;
    }
    int item = newqueue->array[newqueue->front];
    if(newqueue->front == newqueue->rear){
        newqueue->front = -1;
        newqueue->rear = -1;
    }else{
        newqueue->front++;
    }
    printf("Deleted element: %d\n",item);
}

void peek(queue* newqueue){
    if(isEmpty(newqueue)){
        printf("Underflow\n");
        return;
    }
    int item = newqueue->array[newqueue->front];
    printf("Peek element: %d\n",item);
}

void sizeOfqueue(queue* newqueue){
    if(isEmpty(newqueue)){
        printf("Size: 0");
        return;
    }
    int size = (newqueue->rear)-(newqueue->front)+1;
    printf("Size: %d",size);
}

int main(){
    int size = 0;
    printf("Enter the size");
    scanf("%d",&size);
    queue* newqueue = createQueue(size);
    int choice;
    int value;
    while(1){
        printf("\nMenu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Is empty\n");
        printf("5. Size of queue\n");
        printf("6. Exit the program\n");
        printf("Enter choice: ");
        if(scanf("%d", &choice)!=1){
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number between 1 and 7.\n");
            continue;
        }
        switch(choice){
            case 1: 
            printf("Enter element\n");
            scanf("%d",&value);
            enqueue(newqueue,value);
            break;
            case 2: dequeue(newqueue); break;
            case 3: peek(newqueue);break;
            case 4: 
            if(isEmpty(newqueue)){
                printf("queue is empty\n");
            }else{
                printf("queue is not empty\n");
            }
            break;
            case 5: sizeOfqueue(newqueue);break;
            case 6: exit(0);break;
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}