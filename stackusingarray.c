#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *array;
}Stack;

void doubleStack(Stack* stack){
    stack->size = stack->size*2;
    stack->array = (int*)realloc(stack->array,sizeof(int)*stack->size);
}
Stack* createStack(int size){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->size  = size;
    stack->top = -1; 
    stack->array = (int*)malloc(sizeof(int)*size);
    if(stack->array == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    return stack;
}

int isEmpty(Stack* stack){
    if(stack->top == -1)return 1;
    return 0;
}

int isFull(Stack* stack){
    if(stack->top == stack->size-1)return 1;
    return 0;
}

void push(Stack* stack, int value){
    if(isFull(stack)){
        doubleStack(stack);
    }
        stack->top++;
        stack->array[stack->top] = value;
        printf("Pushed successfully\n");
}

void pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Underflow\n");
        return;
    }else{
        int item = stack->array[stack->top];
        stack->top--;
        printf("Popped item = %d",item);        
    }
}

void peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Underflow\n");
        return;
    }else{
        int item = stack->array[stack->top];
        printf("Peeked item = %d",item);        
    }
}

void sizeOfStack(Stack* stack){
    printf("Size = %d",stack->top+1);
}

int main(){
    int size = 0;
    printf("Enter the size of stack\n");
    scanf("%d",&size);
    Stack *stack = createStack(size);

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
            push(stack,value);
            break;
            case 2: pop(stack); break;
            case 3: peek(stack);break;
            case 4: 
            if(isEmpty(stack)){
                printf("Stack is empty\n");
            }else{
                printf("Stack is not empty\n");
            }
            break;
            case 5: sizeOfStack(stack);break;
            case 6: exit(0);break;
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}