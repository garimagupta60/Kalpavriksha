#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct player
{   int id;
    char name[20];
    int score;
    struct player* next;
} player;


player* createPlayer(){
    int id, score;
    int typeCheckError = 0;
    char name[20];
    printf("Enter ID: ");
    scanf("%d", &id);
    if (id <= 0) {  
        printf("Error: ID must be positive.\n");
        typeCheckError = 1;
    }
    printf("Enter Name: ");
    getchar();
    scanf("%[^\n]%*c",name);
    if (name == NULL || strlen(name) == 0 || strlen(name) >= 20) {
        printf("Error: Invalid name.\n");
        typeCheckError = 1;
    }
    printf("Enter Score: ");
    scanf("%d", &score);
    if(typeCheckError)return NULL;
    player* newplayer = (player*)malloc(sizeof(player));
    newplayer->id = id;
    newplayer->score = score;
    strcpy(newplayer->name,name);
    newplayer->next = NULL;
    return newplayer;
}
player* addPlayer(player* head){
    player* newplayer = createPlayer();
    if(head == NULL){
        head = newplayer;
    }else{
        player* currentPlayer = head;
        while(currentPlayer->next!=NULL){
            currentPlayer = currentPlayer->next;
        }
        currentPlayer->next = newplayer;
    }
    return head;
}
player* searchPlayer(player* head){
    int id;
    scanf("%d",&id);
    if(head == NULL){
        return NULL;
    }else{
        player* currentPlayer = head;
        while(currentPlayer!=NULL){
            if(currentPlayer->id==id){
                return currentPlayer;
            }
            currentPlayer = currentPlayer->next;
        }
    }
    return NULL;
}
void displayPlayers(player* head){
    if(head == NULL){
        printf("No Player exists\n");
        return;
    }
    player* currentPlayer = head;
    while(currentPlayer!=NULL){
        printf("%s %d %d\n",currentPlayer->name, currentPlayer->score, currentPlayer->id);
        currentPlayer = currentPlayer->next;
    }
}

player* findmiddle(player* head){
    player* slow = head;
    player* fast = head->next;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

player* merge(player* left, player* right){
    if (left == NULL) return right;
    if (right == NULL) return left;

    player* ans = (player*)malloc(sizeof(player));
    player* temp = ans;
    while(left!=NULL && right!=NULL){
        if(left->id < right->id){
            temp->next = left;
            temp= temp->next;
            left = left->next;
        }else{
            temp->next = right;
            temp= temp->next;
            right = right->next;
        }
    }
    if(left){
        temp->next = left;
    }
    if(right){
        temp->next = right;
    }

    player* result = ans->next;
    free(ans);
    return result;


}

player* mergesort(player* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    player* middle = findmiddle(head);
    player* left = head;
    player* right = middle->next;
    middle->next = NULL;

    left = mergesort(left);
    right = mergesort(right);
    return merge(left,right);
}

player* sortPlayersOnId(player* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    return mergesort(head);
}


int main(){
    int choice;
    player* head = NULL;
    player* found;
    while(1){
        printf("Menu----\n");
        printf("1. Add player\n");
        printf("2. Search player\n");
        printf("3. Display players\n");
        printf("4. Sort player\n");

        if(scanf("%d",&choice)!=1){
            break;
        }
        switch(choice){
            case 1:head = addPlayer(head);break;
            case 2:
            found = searchPlayer(head);
            if(found == NULL){
                printf("Player not found\n");
            }else{
                printf("Player found\n");
            }
            break;

            case 3:displayPlayers(head);break;

            case 4:head = sortPlayersOnId(head);break;
            default: exit(0);
        }
    }
    return 0;
}