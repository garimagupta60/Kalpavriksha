#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
    int size;
}queue;

node* createNode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

queue* createQueue(){
    queue* newqueue = (queue*)malloc(sizeof(queue));
    newqueue->size = 0;
    newqueue->rear = NULL;
    newqueue->front = NULL;
    return newqueue;
}

int isEmpty(queue* newqueue){
    return (newqueue->front == NULL);
}
void enqueue(queue* newqueue, int value){
    node* newnode = createNode(value);
    if(isEmpty(newqueue)){
        newqueue->rear = newnode;
        newqueue->front = newnode;
    }else{
        (newqueue->rear)->next = newnode;
        newqueue->rear = newnode;
    }
    newqueue->size++;
}

int dequeue(queue* newqueue){
    if(isEmpty(newqueue)){
        printf("Underflow\n");
        return -1;
    }
    else{
        node* temp = newqueue->front;
        newqueue->front = newqueue->front->next;
        int value = temp->data;
        free(temp);
        newqueue->size--;
        return value;
    }
}

int peek(queue* newqueue){
    if(isEmpty(newqueue)){
        printf("Underflow\n");
        return -1;
    }
    node* temp = newqueue->front;
    return temp->data;
}

void sizeOfqueue(queue* newqueue){
    printf("Size: %d\n",newqueue->size);
}

void displayQueue(node* front) {
    if (front == NULL) {
        return;
    }
    printf("%d ", front->data); 
    displayQueue(front->next);
}


typedef struct stack{
    queue *queue1;
    int size;
}stack;

stack* createStack(){
    stack *newstack = (stack*)malloc(sizeof(stack));
    newstack->queue1 = createQueue();
    newstack->size = 0;
    return newstack;
}

void pushStack(stack* newstack, int value){
    enqueue(newstack->queue1,value);
    for(int i=0; i<newstack->queue1->size-1; i++){
        enqueue(newstack->queue1, dequeue(newstack->queue1));
    }
    newstack->size++;
}

int popStack(stack* newstack){
    if(isEmpty(newstack->queue1)){
        printf("Underflow\n");
        return -1;
    }
    int value = dequeue(newstack->queue1);
    newstack->size--;
    return value;
}

int peekStack(stack* newstack){
    if(isEmpty(newstack->queue1)){
        printf("Underflow\n");
        return -1;
    }
    int value = peek(newstack->queue1);
    return value;
}

int sizeofStack(stack* newstack){
    return (newstack->queue1->size);
}

int isEmptyStack(stack* newstack){
    return isEmpty(newstack->queue1);
}

void displayStack(stack* newstack){
    if (isEmpty(newstack->queue1)) {
        printf("Stack is empty\n");
        return;
    }
    displayQueue(newstack->queue1->front);
}
int main(){
    stack *newstack = createStack();
    int choice;
    int value;
    while(1){
        printf("\nMenu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Is empty\n");
        printf("5. Size of stack\n");
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
            pushStack(newstack,value);
            break;

            case 2: 
            value = popStack(newstack); 
            if (value != -1) {
                printf("Poped element: %d\n", value);
            }
            break;

            case 3: 
            value = peekStack(newstack);
            if (value != -1) {
                printf("Peek element: %d\n", value);
            }
            break;
            case 4: 
            if(isEmptyStack(newstack)){
                printf("stack is empty\n");
            }else{
                printf("stack is not empty\n");
            }
            break;
            case 5: 
            printf("Size of stack: %d\n", sizeofStack(newstack));
            break;
            case 6: exit(0);break;
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}