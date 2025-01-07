#include<stdio.h>
#include <string.h>
int len(char str[]){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}
char to_lower_case(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}
int main(){
    int rows, cols;
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    while(getchar()!='\n');
    
    char student_name[10][3][50];
    
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Name at (%d,%d): ", i, j);
            fgets(student_name[i][j], 50, stdin);
            student_name[i][j][strcspn(student_name[i][j], "\n")] = '\0';
        }
    }
    
    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", student_name[i][j]);
        }
        printf("\n");
    }
    
    int names_start_vowel = 0;
    char longest_name[80]="";
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char first_char = to_lower_case(student_name[i][j][0]); 
            if (first_char == 'a' || first_char == 'e' || first_char == 'i' || first_char == 'o' || first_char == 'u') {
                names_start_vowel++;
            }
            if (len(student_name[i][j]) > len(longest_name)) {
                strcpy(longest_name, student_name[i][j]);
            }
        }
    }
    
    printf("\nNumber of names starting with a vowel: %d\n", names_start_vowel);
    printf("The longest name: %s\n", longest_name);
}