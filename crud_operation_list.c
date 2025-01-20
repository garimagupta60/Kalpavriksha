#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* createNode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void insertAtEnd(int x){
    struct node* newnode =  createNode(x);
    if(head==NULL){
        head = newnode;
    }else{
        struct node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}
void insertAtBeginning(int x){
    struct node* newnode =  createNode(x);
    if(head==NULL){
        head = newnode;
    }else{
        newnode->next = head;
        head = newnode;
    }
}

int number_of_nodes(struct node* head){
    int count=0;
    struct node* current = head;
    while(current!=NULL){
        count++;
        current = current->next;
    }
    return count;
}
void insertAtPosition(int position,int x){
    int count = number_of_nodes(head);
    struct node* newnode =  createNode(x);
    if(position<1 || position>count+1){
        printf("invalid position\n");
        exit(0);
    }else if(position==1){
        insertAtBeginning(x);
    }else{
        int number_of_steps = 1;
        struct node* current = head;
        while(current!=NULL & number_of_steps<position-1){
            current = current->next;
            number_of_steps++;
        }
        if(current->next!=NULL){
            newnode->next = current->next;
        }
        current->next = newnode;
    }
}
void display(){
    struct node* current = head;
    if(current==NULL){
        printf("NULL");
        exit(0);
    }
    while(current!=NULL){
        if(current->next!=NULL){
            printf("%d ",current->data);
        }else{
            printf("%d",current->data);
        }
        current = current->next;
    }
}

void updateAtPosition(int position, int newValue){
    int count = number_of_nodes(head);
    if(position<1 || position>count){
        printf("invalid position\n");
        exit(0);
    }
    struct node* current = head;
    int number_of_step=1;
    while(current!=NULL && number_of_step<position){
        current = current->next;
        number_of_step++;
    }
    current->data = newValue;
}
void updateAtEnd(int newValue){
     if (head == NULL) {
        printf("List is empty\n");
        exit(0);
    }
    struct node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->data = newValue;
}
void updateAtBeginning(int newValue){
    if(head==NULL){
        return;
    }
    head->data = newValue;
}

void deleteAtBeginning(){
    if(head==NULL){
        return;
    }
    else{
        struct node* current = head;
        head = head->next;
        current->next = NULL;
        free(current);
    }
}

void deleteAtEnd(){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        head = NULL;
        return;
    }
    struct node* current = head;
    while(current->next->next!=NULL){
        current = current->next;
    }
    struct node* temp = current->next;
    current->next = NULL;
    free(temp);
}

void deleteAtPosition(int position){
    int count = number_of_nodes(head);
    if(position<1 || position>count){
        printf("invalid position\n");
        exit(0);
    }else if(position==1){
        deleteAtBeginning();
        return;
    }else{
        int number_of_steps =1;
        struct node* current = head;
        while(current!=NULL & number_of_steps<position-1){
            current = current->next;
            number_of_steps++;
        }
        struct node* temp = current->next;
        current->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
}

int main(){
    int number_of_operations = 0;
    int x;
    int pos;
    scanf("%d",&number_of_operations);
    while(number_of_operations){
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
            scanf("%d",&x);
            insertAtEnd(x);
            break;
            
            case 2:
            scanf("%d",&x);
            insertAtBeginning(x);
            break;
            
            case 3:
            scanf("%d",&pos);
            scanf("%d",&x);
            insertAtPosition(pos,x);
            break;
            
            case 4:
            display();
            break;
            
            case 5:
            scanf("%d",&pos);
            scanf("%d",&x);
            updateAtPosition(pos,x);
            break;
            
            case 6:
            deleteAtBeginning();
            break;
            
            case 7:
            deleteAtEnd();
            break;
            
            case 8:
            scanf("%d",&pos);
            deleteAtPosition(pos);
            break;
            
            default:exit(0);
        }
        number_of_operations--;
    }
    return 0;
}