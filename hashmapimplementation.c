#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    int value;
    struct node* next;
}node;

typedef struct hashmap{
    int size;
    int capacity;
    node** array;
}map;

map* hashtable = NULL;

node* createnode(int key, int value){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->key = key;
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
}

void createmap(int size){
    hashtable = (map*)malloc(sizeof(map));
    hashtable->size = 0;
    hashtable->capacity = size;
    hashtable->array = (node**)malloc(sizeof(node*)*size);
    for(int i=0; i<size; i++){
        hashtable->array[i] = NULL;
    }
    return;
}

int hashfunction(int key){
    int index = key % (hashtable->capacity);
    return index;
}

void insertintohashmap(int key, int value){
    int index = hashfunction(key);
    node* newnode = createnode(key,value);
    if(hashtable->array[index] == NULL){
        hashtable->array[index] = newnode;
    }else{
        node* current = hashtable->array[index];
        node* prev = NULL;
        while(current!=NULL){
            if(current->key == key){
                current->value = value;
                return;
            }
            prev = current;
            current = current->next;
        }
        prev->next = newnode;
    }
    hashtable->size++;
}

int searchintohashmap(int key){
    int index = hashfunction(key);
    if(hashtable->array[index] == NULL){
        return -1;
    }else{
        node* current = hashtable->array[index];
        while(current!=NULL){
            if(current->key == key){
                return current->value;
            }
            current = current->next;
        }
    }
    return -1;
}

void deletefromhashmap(int key){
    int index = hashfunction(key);
    if(hashtable->array[index] == NULL){
        printf("Key not found\n");
        return;
    }else{
        node* current = hashtable->array[index];
        node* prev = NULL;
        while(current!=NULL){
            if(current->key == key){
                if(prev == NULL){
                    hashtable->array[index] = current->next;
                    printf("Key %d deleted.\n", current->key);
                    free(current);
                    return;
                }else{
                    node* temp = current;
                    prev->next = current->next;
                    printf("Key %d is deleted\n",temp->key);
                    free(temp);
                    return;
                }
            }
            prev = current;
            current = current->next;
        }
    }
}

void displayhashtable(){
    printf("Hash Table:\n");
    for(int i=0; i<hashtable->capacity; i++){
        if(hashtable->array[i]!=NULL){
            int arrowbefore = 1;
            node* current = hashtable->array[i];
            printf("Index %d:",i);
            while(current!=NULL){
                if(arrowbefore == 0)printf(" -> ");
                printf("(%d,%d)",current->key,current->value);
                arrowbefore = 0;
                current = current->next;
            }
            printf("\n");
        }
    }
}
int main(){ 
    int key = 0;
    int value = 0;
    int choice = 0;
    createmap(10);
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
            printf("Enter key: ");
            scanf("%d",&key);
            if(key < 0){
                printf("Invalid key\n");
                printf("Enter key: ");
                scanf("%d",&key);
            }

            printf("Enter value: ");
            scanf("%d",&value);
            if(value < 0){
                printf("Invalid key\n");
                printf("Enter value: ");
                scanf("%d",&value);
            }
            
            insertintohashmap(key, value);
            break;

            case 2:
            printf("Enter key: ");
            scanf("%d",&key);
            value = searchintohashmap(key);
            if (value == -1) {
                printf("Key not found\n");
            } else {
                printf("Value: %d\n", value);
            }
            break;

            case 3:
            printf("Enter key: ");
            scanf("%d",&key);
            deletefromhashmap(key);
            break;

            case 4:
            displayhashtable();
            break;

            default: 
            printf("Exiting program.\n");
            exit(0);
        }
    }
    return 0;
}

