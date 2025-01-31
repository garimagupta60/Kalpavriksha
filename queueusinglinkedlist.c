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
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

queue* createQueue(){
    queue* newqueue = (queue*)malloc(sizeof(queue));
    if(newqueue == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
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

void dequeue(queue* newqueue){
    if(isEmpty(newqueue)){
        printf("Underflow\n");
        return;
    }
    else{
        node* temp = newqueue->front;
        newqueue->front = newqueue->front->next;
        printf("Deleted: %d\n",temp->data);
        free(temp);
        newqueue->size--;
    }
}

void peek(queue* newqueue){
    if(isEmpty(newqueue)){
        printf("Underflow\n");
        return;
    }
    node* temp = newqueue->front;
    printf("Peak ELement: %d\n",temp->data);
    
}

void sizeOfqueue(queue* newqueue){
    printf("Size: %d\n",newqueue->size);
}

int main(){
    queue *newqueue = createQueue();
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