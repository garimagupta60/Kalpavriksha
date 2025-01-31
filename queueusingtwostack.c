#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    int size;
    node* top;
}stack;

node* createNode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

stack* createStack(){
    stack* newStack = (stack*)malloc(sizeof(stack));
    if(newStack == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newStack->size = 0;
    newStack->top = NULL;
    return newStack;
}


int isEmpty(stack* newStack){
    return(newStack->top == NULL);
}

void push(stack* newStack, int value){
    node* newnode = createNode(value);
    if(isEmpty(newStack)){
        newStack->top = newnode;
    }else{
        newnode->next = newStack->top;
        newStack->top = newnode;
    }
    newStack->size++;
}

int pop(stack* newStack){
    if(isEmpty(newStack)){
        printf("Underflow\n");
        return -1;
    }else{
        node* temp = newStack->top;
        newStack->top = newStack->top->next;
        int value = temp->data;
        free(temp);
        newStack->size--;
        return value;
    }
}
int peek(stack* newStack){
    if(isEmpty(newStack)){
        printf("Underflow\n");
        return -1;
    }else{
        node* temp = newStack->top;
        return temp->data;
    }
}

void displayStack(node* top) {
    if (top == NULL) {
        return;
    }
    while(top!=NULL){
        printf("%d ", top->data); 
        top = top->next;

    }
}

void printReverse(node* top){
    if (top == NULL) return;
    printReverse(top->next);
    printf("%d ", top->data);
}

typedef struct queueUsingStack{
    stack* stack1;
    stack* stack2;
    int size;
}queue;

queue* createQueue(){
    queue* newqueue = (queue*)malloc(sizeof(queue));
    newqueue->stack1 = createStack();
    newqueue->stack2 = createStack();
    newqueue->size = 0;
    return newqueue;
}

void enqueue(queue* newqueue, int value){
    push(newqueue->stack1,value);
    newqueue->size++;
}

int dequeue(queue* newqueue){
    if(isEmpty(newqueue->stack1) && isEmpty(newqueue->stack2)){
        printf("Underflow\n");
        return -1;
    }
    if (isEmpty(newqueue->stack2)) {
        while (!isEmpty(newqueue->stack1)) {
            push(newqueue->stack2, pop(newqueue->stack1));
        }
    }
    newqueue->size--;
    return pop(newqueue->stack2);
}

int peekQueue(queue* newqueue){
    if(isEmpty(newqueue->stack1) && isEmpty(newqueue->stack2)){
        printf("Underflow\n");
        return -1;
    }
    if (isEmpty(newqueue->stack2)) {
        while (!isEmpty(newqueue->stack1)) {
            push(newqueue->stack2, pop(newqueue->stack1));
        }
    }
    return peek(newqueue->stack2);
}

int isEmptyQueue(queue* newqueue) {
    return isEmpty(newqueue->stack1) && isEmpty(newqueue->stack2);
}
int sizeOfQueue(queue* newqueue) {
    return ((newqueue->stack1->size) + (newqueue->stack2->size));
}

void displayQueue(queue* newqueue){
    if(isEmpty(newqueue->stack1) && isEmpty(newqueue->stack2)){
        printf("Empty\n");
    }
    displayStack(newqueue->stack2->top);
    printReverse(newqueue->stack1->top);
    printf("\n");
}

int main(){
    queue* newqueue = createQueue();
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
        if(scanf("%d",&choice)!=1){
            while(getchar()!='\n');
            printf("Enter valid choice between 1 to 6\n");
            continue;
        }
        switch(choice){
            case 1: 
            printf("Enter value");
            scanf("%d",&value);
            enqueue(newqueue,value);
            break;

            case 2:
            value = dequeue(newqueue);
            if (value != -1) {
                printf("Dequeued element: %d\n", value);
            }
            break;

            case 3:
            value = peekQueue(newqueue);
            if (value != -1) {
                printf("Peek element: %d\n", value);
            }
            break;

            case 4:
            if(isEmptyQueue(newqueue)){
                printf("queue is empty\n");
            }else{
                printf("queue is not empty\n");
            }
            break;
            case 5: 
            printf("Size of queue: %d\n", sizeOfQueue(newqueue));
            break;
            case 6: exit(0);break;
            default: printf("Invalid choice\n");
        }

    }
    return 0;
}

