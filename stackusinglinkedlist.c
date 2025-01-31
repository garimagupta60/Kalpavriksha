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

void pop(stack* newStack){
    if(isEmpty(newStack)){
        printf("Underflow\n");
        return;
    }else{
        node* temp = newStack->top;
        newStack->top = newStack->top->next;
        printf("Deleted %d\n",temp->data);
        free(temp);
        newStack->size--;
    }
}
void peek(stack* newStack){
    if(isEmpty(newStack)){
        printf("Underflow\n");
        return;
    }else{
        node* temp = newStack->top;
        printf("Top element: %d\n",temp->data);
    }
}

void sizeOfStack(stack* newStack){
    printf("Size: %d\n",newStack->size);
}

int main(){
    stack* newStack = createStack();
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
        if(scanf("%d",&choice)!=1){
            while(getchar()!='\n');
            printf("ENter the valid choice\n");
            continue;
        }
                switch(choice){
            case 1: 
            printf("Enter element\n");
            scanf("%d",&value);
            push(newStack,value);
            break;
            case 2: pop(newStack); break;
            case 3: peek(newStack);break;
            case 4: 
            if(isEmpty(newStack)){
                printf("Stack is empty\n");
            }else{
                printf("Stack is not empty\n");
            }
            break;
            case 5: sizeOfStack(newStack);break;
            case 6: exit(0);break;
            default: printf("Invalid choice\n");
        }

    }
    return 0;
}