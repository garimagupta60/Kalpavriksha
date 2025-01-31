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
    displayQueue(front->next);
    printf("%d ", front->data); 
}


typedef struct stack{
    queue *queue1;
    queue *queue2;
    int size;
}stack;

stack* createStack(){
    stack *newstack = (stack*)malloc(sizeof(stack));
    newstack->queue1 = createQueue();
    newstack->queue2 = createQueue();
    newstack->size = 0;
    return newstack;
}

void pushStack(stack* newstack, int value){
    enqueue(newstack->queue1,value);
    newstack->size++;
}

int popStack(stack* newstack){
    if(isEmpty(newstack->queue1) && isEmpty(newstack->queue2)){
        printf("Underflow\n");
        return -1;
    }
    if(isEmpty(newstack->queue2)){
        while(newstack->queue1->size!=1){
            enqueue(newstack->queue2, dequeue(newstack->queue1));
        }
        int value = dequeue(newstack->queue1);
        while(!isEmpty(newstack->queue2)){
            enqueue(newstack->queue1, dequeue(newstack->queue2));
        }
        return value;
        newstack->size--;
    }
    return -1;
}
int peekStack(stack* newstack){
    if(isEmpty(newstack->queue1) && isEmpty(newstack->queue2)){
        printf("Underflow\n");
        return -1;
    }
    if(isEmpty(newstack->queue2)){
        while(newstack->queue1->size!=1){
            enqueue(newstack->queue2, dequeue(newstack->queue1));
        }
        int value = dequeue(newstack->queue1);
        enqueue(newstack->queue2,value);
        queue *temp = newstack->queue1;
        newstack->queue1 = newstack->queue2;
        newstack->queue2 = temp;
        return value;
    }
    return -1;
}

int sizeofStack(stack* newstack){
    return (newstack->queue1->size)+(newstack->queue2->size);
}

int isEmptyStack(stack* newstack){
    return isEmpty(newstack->queue1) && isEmpty(newstack->queue2);
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