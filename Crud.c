#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct User{
    int id;
    char name[20];
    int age;
    struct User* next;
}User;

User* head = NULL;

User* createUserNode(int id, char* name, int age) {
    User* newUser = (User*)malloc(sizeof(User));
    newUser->id = id;
    strcpy(newUser->name, name);
    newUser->age = age;
    newUser->next = NULL;
    return newUser;
}

User* findUserById(int id) {
    User* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
void insertUserSorted(User* newUser) {
    if (head == NULL || head->id > newUser->id) {
        newUser->next = head;
        head = newUser;
    } else {
        User* current = head;
        while (current->next != NULL && current->next->id < newUser->id) {
            current = current->next;
        }
        newUser->next = current->next;
        current->next = newUser;
    }
}
void loadUserFromFile(){
    FILE *fp = fopen("users.txt","r");
    if(fp == NULL){
        fp = fopen("users.txt", "a");       
        fclose(fp);
        return;
    }
    int id, age;
    char name[20];
    while (fscanf(fp, "%d,%19[^,],%d", &id, name, &age) != EOF) {
        User* newUser = createUserNode(id, name, age);
        insertUserSorted(newUser);
    }
    
    fclose(fp);

}

void saveUsersToFile() {
    FILE *fp = fopen("users.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    User* current = head;
    while (current != NULL) {
        fprintf(fp, "%d,%s,%d\n", current->id, current->name, current->age);
        current = current->next;
    }

    fclose(fp);
}


void Create() {
    int id, age;
    char name[20];
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter Name: ");
    getchar();
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter Age: ");
    scanf("%d", &age);
    if (findUserById(id) != NULL) {
        printf("User with ID %d already exists!\n", id);
        return;
    }
    User* newUser = createUserNode(id, name, age);
    insertUserSorted(newUser);
    printf("User added successfully!\n");
}

void Read() {
    if (head == NULL) {
        printf("No users found.\n");
        return;
    }
    User* current = head;
    printf("ID\tName\tAge\n");
    while (current != NULL) {
        printf("%d\t%s\t%d\n", current->id, current->name, current->age);
        current = current->next;
    }
}

void Update() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    User* user = findUserById(id);
    if (user == NULL) {
        return;
    }
    printf("Enter new name: ");
    getchar();             
    fgets(user->name, 20, stdin);   
    user->name[strcspn(user->name, "\n")] = '\0';
    printf("Enter new age: ");
    scanf("%d", &user->age);
    printf("User updated successfully!\n");
}

void Delete() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    User* prev = NULL;
    User* current = head;

    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) { 
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("User with ID %d deleted successfully.\n", id);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("User with ID %d not found.\n", id);
}

int main(){
    int choice;
    loadUserFromFile();
    while (1) {
        printf("1. Create\n");
        printf("2. Read\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:Create();break;
            case 2:Read();break;
            case 3:Update();break;
            case 4:Delete();break;
            case 5:saveUsersToFile();
                printf("Exiting...\n");
                exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
